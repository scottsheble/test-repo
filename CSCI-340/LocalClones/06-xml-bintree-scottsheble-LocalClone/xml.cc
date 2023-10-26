/**********************************************************************************************
 * NIU CSCI 340 Section 1                                                                     *
 * Assignment 6                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
// Implement a simple parser for XML that uses a tilted binary tree for storage 
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include "nodes.h" // supplied node declarations
#include "bintree.h"
#include "xml.h"

/**
 * @brief This function should return a string containing the XML representation of the 
 * element, element, passed in.
 * 
 * @param element 
 * @param opening 
 * @return std::string 
 */
std::string to_string(const xml_element &element, bool opening) {
    // creates and returns a string representation of the XML element.
    std::string result;
    if (opening) {
        // creates opening tag.
        result = "<" + element.name;
        for (const auto &attr : element.attrs) {
            // adds attributes to the opening tag
            result += " " + attr.first + "=\"" + attr.second + "\"";
        }
        result += ">";
    } else {
        // closing tags.
        result = "</" + element.name + ">";
    }
    return result;
}

/**
 * @brief This function does a preorder traversal of the XML tree with root as its root, 
 * building a vector containing pointers to all of the nodes containing elements whose name 
 * matches the given name. Returns the vector built.
 * 
 * @param root 
 * @param name 
 * @return std::vector <XMLNODE *> 
 */
std::vector <XMLNODE *> xml_find_by_name(XMLNODE * root, const std::string &name) {
    // search for XML nodes with the specified tag name and return a vector of matching nodes.
    std::vector<XMLNODE *> result;
    if (root) {
        if (root->data.type == tag && root->data.name == name) {
            result.push_back(root);
        }
        // recursively search in the left and right subtrees.
        std::vector<XMLNODE *> left_result = xml_find_by_name(root->left, name);
        std::vector<XMLNODE *> right_result = xml_find_by_name(root->right, name);
        result.insert(result.end(), left_result.begin(), left_result.end());
        result.insert(result.end(), right_result.begin(), right_result.end());
    }
    return result;
}

/**
 * @brief This function does a preorder traversal of the XML tree with root as its root, 
 * building a vector containing pointers to all of the nodes containing elements that have an 
 * attribute named attrname. Returns the vector built.
 * 
 * @param root 
 * @param attrname 
 * @return std::vector <XMLNODE *> 
 */
std::vector <XMLNODE *> xml_find_with_attr(XMLNODE * root, const std::string &attrname) {
    // Search for XML nodes with the specified attribute and return a vector of nodes matching
    std::vector<XMLNODE *> result;
    if (root) {
        for (const auto &attr : root->data.attrs) {
            if (attr.first == attrname) {
                result.push_back(root);
                break; 
            }
        }
        // Recursively search in the left and right subtrees
        std::vector<XMLNODE *> left_result = xml_find_with_attr(root->left, attrname);
        std::vector<XMLNODE *> right_result = xml_find_with_attr(root->right, attrname);
        result.insert(result.end(), left_result.begin(), left_result.end());
        result.insert(result.end(), right_result.begin(), right_result.end());
    }
    return result;
}

/**
 * @brief This function is responsible for inserting a new element onto a tree. If there is 
 * currently nothing in the tree, the new element is inserted at the root. If not, look at the 
 * current position within the tree, found in the state object.After you insert the element, 
 * set the current position to the location of the newly inserted node. Returns the number of 
 * errors encountered.
 * 
 * @param element 
 * @param state 
 * @param verbose 
 * @return int 
 */
int xml_add_node(const xml_element &element, xml_tree_state & state, bool verbose) {
    // Add a new XML node to the tree under the current node in the state
    XMLNODE *newNode = new XMLNODE(element);
    newNode->data.closed = false;

    if (!state.cur) {
        // If no current node exists, set the new node as the root
        state.root = newNode;
        state.cur = newNode;
    } else {
        if (state.cur->data.closed) {
            // The current node is closed, so find the nearest open node in the parent chain
            XMLNODE *parentNode = state.cur->parent;
            while (parentNode && parentNode->data.closed) {
                parentNode = parentNode->parent;
            }
            if (parentNode) {
                // Add the new node as the child of the open parent
                if (!parentNode->left) {
                    parentNode->left = newNode;
                } else {
                    parentNode->right = newNode;
                }
                newNode->parent = parentNode;
                state.cur = newNode;
            } else {
                if (verbose) {
                    std::cerr << "ERROR: Cannot add node; no open parent found." << std::endl;
                }
                delete newNode;
                return 1;
            }
        } else {
            // Add the new node as a sibling to the current node
            if (!state.cur->parent->left) {
                state.cur->parent->left = newNode;
            } else {
                state.cur->parent->right = newNode;
            }
            newNode->parent = state.cur->parent;
            state.cur = newNode;
        }
    }
    return 0;
}

/**
 * @brief This function tries to close the most recently opened tag whose name matches the name
 * string. If the tag is closed immediately after opening, then it is possible to find the tag 
 * to close in the current location of the tree. If it's not found in the current location, you
 * should find the current node's real parent (remember our binary tree is a tilted non-binary
 * tree). You can use the tilted_find_parent function to do this. If the tag with the right 
 * name is found in one of those locations, mark it as closed and set the current location of 
 * the tree to the tag just closed. Return 0 for success. If you do not find a tag with the 
 * right name in either of those places, then there is either something wrong with your tree 
 * (check your xml_add_node logic), or the XML was not properly nested. Print an error message 
 * and return 1. Returns the number of errors encountered -- 0 for success.
 * 
 * @param name 
 * @param state 
 * @param verbose 
 * @return int 
 */
int xml_close_tag(const std::string name, xml_tree_state & state, bool verbose) {
    // Close an XML tag, updating the tree structure
    if (!state.cur) {
        if (verbose) {
            std::cerr << "ERROR: No open tag to close." << std::endl;
        }
        return 1;
    }
    if (state.cur->data.name != name) {
        if (verbose) {
            std::cerr << "ERROR: Closing tag name does not match the open tag." << std::endl;
        }
        return 1;
    }
    state.cur->data.closed = true;
    state.cur = state.cur->parent;
    return 0;
}

/**
 * @brief This function is called by parse_xml whenever it detects plain text outside of a tag. 
 * It must construct a plaintext xml_element and call xml_add_node to place it on the tree in 
 * the appropriate location. The function will return the number of errors encountered (which 
 * will likely have occurred in the call to xml_add_node).
 * 
 * @param plaintext 
 * @param state 
 * @param verbose 
 * @return int 
 */
int xml_handle_plaintext(std::string &plaintext, xml_tree_state & state, bool verbose) {
    // Handle plaintext within the XML (e.g., add as a text node)
    if (state.cur) {
        xml_element textElement;
        textElement.type = plain;
        textElement.fulltext = plaintext;
        xml_add_node(textElement, state, verbose);
        return 0;
    } else {
        if (verbose) {
            std::cerr << "ERROR: Cannot handle plaintext; no open tag found." << std::endl;
        }
        return 1;
    }
}

/**
 * @brief This function is responsible for detecting the key="value" attributes found in the 
 * string, input. Attributes are separated by one or more pieces of whitespace (as defined 
 * above), but there may be no spaces around the '='. Your function will treat everything 
 * between the quote immediately (no whitespace allowed) following the equal sign and the next 
 * quote it finds as the text of the string forming the attribute's value. The quotes will not 
 * be included in your string. If you have an attribute without a value, or spaces around the 
 * equal sign, then the input is invalid, print an error. If you reach the end of the string 
 * searching for the ending quote of an attribute's value, use what is there as a value, but 
 * print an error message about expecting the quote and not finding it. Returns the number of 
 * attributes detected.
 * 
 * @param input 
 * @param attrs 
 * @param verbose 
 * @return int 
 */
int xml_handle_attributes(const std::string &input, std::map<std::string, std::string> &attrs, bool verbose) {
    // Handle XML tag attributes and populate the attrs map
    attrs.clear();
    size_t pos = 0;
    while (pos < input.size()) {
        pos = input.find_first_not_of(" \t", pos);
        if (pos == std::string::npos) {
            break; // No more attributes
        }
        size_t eqPos = input.find('=', pos);
        if (eqPos == std::string::npos) {
            if (verbose) {
                std::cout << "ERROR: Invalid attribute format: " << input << std::endl;
            }
            return 1;
        }
        std::string attrName = input.substr(pos, eqPos - pos);
        pos = input.find_first_not_of(" \t", eqPos + 1);
        if (pos == std::string::npos) {
            if (verbose) {
                std::cout << "ERROR: Missing attribute value: " << input << std::endl;
            }
            return 1;
        }
        char quote = input[pos];
        if (quote != '"' && quote != '\'') {
            if (verbose) {
                std::cout << "ERROR: Attribute value must be enclosed in double or single quotes: " << input << std::endl;
            }
            return 1;
        }
        size_t endQuote = input.find(quote, pos + 1);
        if (endQuote == std::string::npos) {
            if (verbose) {
                std::cout << "ERROR: Missing closing quote for attribute value: " << input << std::endl;
            }
            return 1;
        }
        std::string attrValue = input.substr(pos + 1, endQuote - pos - 1);
        attrs[attrName] = attrValue;
        pos = endQuote + 1;
    }
}

/**
 * @brief This function is called by parse_xml whenever a tag has been found in the input. In 
 * this function, you will need to find out the name of the tag, and whether it is an opening 
 * tag or closing tag. If the string is empty, too short to be a valid tag, or does not begin 
 * with '<' and end with '>', then the tag is invalid. Print an error message and return 1 
 * immediately. If it is an opening tag, it may have attributes. You must pass the portion of 
 * the tagstring after the name to the xml_handle_attributes function to break down those 
 * attributes and store them into the attribute map for the node. Once you've broken down the 
 * tag into its parts, construct an xml_element and call xml_add_node to add it to the tree in 
 * the appropriate location. If it's a closing tag (it has a '/' right after the '<' that 
 * begins the tag), call xml_close_tag to close the tag. Returns the number of errors detected.
 * 
 * @param tagstring 
 * @param state 
 * @param verbose 
 * @return int 
 */
int xml_handle_tag(std::string &tagstring, xml_tree_state & state, bool verbose) {
    if (tagstring.empty()) {
        if (verbose) {
            std::cerr << "ERROR: Empty tag string." << std::endl;
        }
        return 1;
    }

    // Parse the tag string to extract tag name and attributes
    size_t tagStart = tagstring.find('<');
    size_t tagEnd = tagstring.find('>');
    if (tagStart == std::string::npos || tagEnd == std::string::npos || tagEnd <= tagStart) {
        if (verbose) {
            std::cerr << "ERROR: Invalid tag format: " << tagstring << std::endl;
        }
        return 1;
    }

    std::string tagContent = tagstring.substr(tagStart + 1, tagEnd - tagStart - 1);

    // Determine if it's an opening tag or a closing tag
    bool isClosingTag = (tagContent[0] == '/');

    // Remove the '/' if it's a closing tag
    if (isClosingTag) {
        tagContent = tagContent.substr(1);
    }

    // Create an XML element for the tag
    xml_element element;
    element.type = tag;
    element.closed = isClosingTag;

    // Find the tag name
    size_t nameEnd = tagContent.find_first_of(" \t");
    if (nameEnd == std::string::npos) {
        nameEnd = tagContent.find('>');
    }
    if (nameEnd != std::string::npos) {
        element.name = tagContent.substr(0, nameEnd);

        // Extract and handle attributes (if any)
        std::string attrString = tagContent.substr(nameEnd);
        std::map<std::string, std::string> attributes;
        if (xml_handle_attributes(attrString, attributes, verbose) != 0) {
            return 1;
        }
        element.attrs = attributes;

        // Add the XML element to the tree
        if (xml_add_node(element, state, verbose) != 0) {
            return 1;
        }

        // Close the tag if it's a self-closing tag
        if (tagContent.back() == '/') {
            xml_close_tag(element.name, state, verbose);
        }
    } else {
        if (verbose) {
            std::cerr << "ERROR: Invalid tag name in tag string: " << tagstring << std::endl;
        }
        return 1;
    }

    return 0;
}

/**
 * @brief This function will print out the XML tree (or subtree) with root as its root as valid 
 * XML.
 * 
 * @param root 
 * @param ost 
 */
void xml_print_subtree(XMLNODE *root, std::ostream & ost) {
    if (root) {
        if (root->data.type == xml_type::tag) {
            if (root->data.closed) {
                ost << to_string(root->data, false);
            } else {
                ost << to_string(root->data, true);
            }
        } else if (root->data.type == xml_type::plain) {
            // Handle plain text by directly printing it
            ost << root->data.fulltext;
        }

        for (XMLNODE *child = root->left; child != nullptr; child = child->right) {
            xml_print_subtree(child, ost);
        }

        if (root->data.type == xml_type::tag && !root->data.closed) {
            ost << to_string(root->data, false);
        }
    }
}

