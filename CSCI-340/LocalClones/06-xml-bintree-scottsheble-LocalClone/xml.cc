// Implement a simple parser for XML that uses a tilted binary tree for storage
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

#include "nodes.h" // supplied node declarations
#include "bintree.h"
#include "xml.h"

std::string to_string(const xml_element &element, bool opening) {
  // XXX You must implement this
  return "";
}

std::vector <XMLNODE *> xml_find_by_name(XMLNODE * root, const std::string &name) {
  // XXX You must implement this
  return {};
}

std::vector <XMLNODE *> xml_find_with_attr(XMLNODE * root, const std::string &attrname) {
  // XXX You must implement this
  return {};
}

int xml_add_node(const xml_element &element, xml_tree_state & state, bool verbose) {
   // XXX You must implement this.
   return 1000;
}

int xml_close_tag(const std::string name, xml_tree_state & state, bool verbose) {
   // XXX You must implement this.
   return 1000;
}

int xml_handle_plaintext(std::string &plaintext, xml_tree_state & state, bool verbose) {
   // XXX You must implement this.
   return 1000;
}

int xml_handle_attributes(const std::string &input, std::map<std::string, std::string> &attrs, bool verbose) {
   // XXX You must implement this.
   return 0;
}

int xml_handle_tag(std::string &tagstring, xml_tree_state & state, bool verbose) {
   // XXX You must implement this.
   return 1000;
}

void xml_print_subtree(XMLNODE *root, std::ostream & ost) {
  // XXX You must implement this.
}

