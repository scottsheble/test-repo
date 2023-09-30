/**********************************************************************************************
 * NIU CSCI 340 Section 1                                                                     *
 * Assignment 3                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIU_CSCI_340_GRIDS_IMPL_H
#define NIU_CSCI_340_GRIDS_IMPL_H

// include the declarations needed for this
#include <iostream>
#include <fstream>
#include "grids.decl.h"

////////////////////////////////////////////////////////////////////////////////
//
// grid_row_major method implementations
//
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief These methods take coordinates as parameters -- the xy version takes (x,y) coordinates 
 * and the rc version takes (row, column) coordinates. If the coordinates fit within the boundaries 
 * of the grid, they will return true, otherwise false. Notice that both sets of coordinates start 
 * with 0 as the lowest available.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <typename T, typename RA_CONTAINER>
bool grid_row_major<T,RA_CONTAINER>::boundscheckxy(int x, int y) const {
    return x >= 0 && x < _width && y >= 0 && y < _height;
}

/**
 * @brief These methods take coordinates as parameters -- the xy version takes (x,y) coordinates 
 * and the rc version takes (row, column) coordinates. If the coordinates fit within the boundaries 
 * of the grid, they will return true, otherwise false. Notice that both sets of coordinates start 
 * with 0 as the lowest available.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @param col 
 * @return true 
 * @return false 
 */
template <typename T, typename RA_CONTAINER>
bool grid_row_major<T,RA_CONTAINER>::boundscheckrc(int row, int col) const {
    return row >= 0 && row < _height && col >= 0 && col < _width;
}

/**
 * @brief This method should return true if, and only if, there are no elements present 
 * in the grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @return true 
 * @return false 
 */
template <typename T, typename RA_CONTAINER>
bool grid_row_major<T,RA_CONTAINER>::empty() const {
    return _width == 0 || _height == 0;
}

/**
 * @brief Get rid of all of the data that was being stored, and change the stored height 
 * and width accordingly.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 */
template <typename T, typename RA_CONTAINER>
void grid_row_major<T,RA_CONTAINER>::clear() {
    data.clear();
    _width = 0;
    _height = 0;
}

/**
 * @brief atxy(x,y): takes screen x,y coordinates -- (x=0,y=0) is the top left element, and 
 * (x=width-1, y=height-1) is the bottom right. These coordinates are commonly used when 
 * doing raster graphics on a computer screen.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param x 
 * @param y 
 * @return T& 
 */
template <typename T, typename RA_CONTAINER>
T & grid_row_major<T,RA_CONTAINER>::atxy(int x, int y) {
    if (boundscheckxy(x, y)) {
        return data[y * _width + x];
    }
    throw std::out_of_range("Index out of bounds");
}

/**
 * @brief atxy(x,y): takes screen x,y coordinates -- (x=0,y=0) is the top left element, and 
 * (x=width-1, y=height-1) is the bottom right. These coordinates are commonly used when 
 * doing raster graphics on a computer screen.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param x 
 * @param y 
 * @return const T& 
 */
template <typename T, typename RA_CONTAINER>
const T & grid_row_major<T,RA_CONTAINER>::atxy(int x, int y) const {
    if (boundscheckxy(x, y)) {
        return data[y * _width + x];
    }
    throw std::out_of_range("Index out of bounds");
}

/**
 * @brief atrc(row, col): takes row, column coordinates -- row 0 is the first row, and row 
 * (height-1) is the last row. Column 0 is the first, leftmost column. These coordinates are 
 * typically used by mathematicians (they may decide to start the numbering at 1 instead of 0) 
 * and you'll see them used a lot when a program involves linear algebra (like matrix multiplication).
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @param col 
 * @return T& 
 */
template <typename T, typename RA_CONTAINER>
T & grid_row_major<T,RA_CONTAINER>::atrc(int row, int col) {
    if (boundscheckrc(row, col)) {
        return data[row * _width + col];
    }
    throw std::out_of_range("Index out of bounds");
}

/**
 * @brief atrc(row, col): takes row, column coordinates -- row 0 is the first row, and row 
 * (height-1) is the last row. Column 0 is the first, leftmost column. These coordinates are 
 * typically used by mathematicians (they may decide to start the numbering at 1 instead of 0) 
 * and you'll see them used a lot when a program involves linear algebra (like matrix multiplication).
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @param col 
 * @return const T& 
 */
template <typename T, typename RA_CONTAINER>
const T & grid_row_major<T,RA_CONTAINER>::atrc(int row, int col) const {
    if (boundscheckrc(row, col)) {
        return data[row * _width + col];
    }
    throw std::out_of_range("Index out of bounds");
}

/**
 * @brief These methods return the width, or the height, respectively, of the grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @return int 
 */
template <typename T, typename RA_CONTAINER>
int grid_row_major<T,RA_CONTAINER>::width() const {
    return _width;
}

/**
 * @brief These methods return the width, or the height, respectively, of the grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @return int 
 */
template <typename T, typename RA_CONTAINER>
int grid_row_major<T,RA_CONTAINER>::height() const {
    return _height;
}

/**
 * @brief Overwrite this grid by copying in the contents of the other grid. Replace this 
 * grid's width, height, and data, copying them from the other grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @tparam OTHER_CONTAINER 
 * @param source 
 * @return grid_row_major <T, RA_CONTAINER>& 
 */
template <typename T, typename RA_CONTAINER>
template <typename OTHER_CONTAINER>
grid_row_major <T, RA_CONTAINER> & grid_row_major<T, RA_CONTAINER>::operator = (const grid_row_major<T, OTHER_CONTAINER> & source) {
    if (this != &source) {
        _width = source._width;
        _height = source._height;
        data.assign(source.data.begin(), source.data.end());
    }
    return *this;
}

/**
 * @brief rowbegin(i) provides an iterator that points to the first element in row i 
 * (numbering from 0). rowend(i) returns an iterator that points just past the last 
 * element on row i. These are simple to provide in a row major grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::rowbegin(int row) {
        return data.begin() + row * _width;
}

/**
 * @brief rowbegin(i) provides an iterator that points to the first element in row i 
 * (numbering from 0). rowend(i) returns an iterator that points just past the last 
 * element on row i. These are simple to provide in a row major grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::rowend(int row) {
        return data.begin() + row * _width + _width;
}

/**
 * @brief rowbegin(i) provides an iterator that points to the first element in row i 
 * (numbering from 0). rowend(i) returns an iterator that points just past the last 
 * element on row i. These are simple to provide in a row major grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::rowbegin(int row) const {
        return data.cbegin() + row * _width;
}

/**
 * @brief rowbegin(i) provides an iterator that points to the first element in row i 
 * (numbering from 0). rowend(i) returns an iterator that points just past the last 
 * element on row i. These are simple to provide in a row major grid.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param row 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::rowend(int row) const {
        return data.cbegin() + row * _width + _width;
}

/**
 * @brief colbegin(i) will return a column iterator that points to the first element 
 * in column i (numbering from 0)
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param col 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::colbegin(int col) {
        col_iterator<typename RA_CONTAINER::iterator> col_iterator(data.begin() + col, _width);
        return col_iterator;
}

/**
 * @brief colend(i) returns a column iterator that points to the position that you'd 
 * get to after iterating one time past the last valid element in the column.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param col 
 * @return auto 
 */
template <typename T, typename RA_CONTAINER>
auto grid_row_major<T,RA_CONTAINER>::colend(int col) {
    if (col >= 0 && col < _width) {
        col_iterator<typename RA_CONTAINER::iterator> col_iterator(data.begin() + col + (_width * _height), _width);
        return col_iterator;
    }
}

/**
 * @brief Destructively resize the grid. Do not worry about keeping the data that was 
 * previously present intact. Make the data container big enough to fit a width height 
 * grid, and change the _height and _width parameters to the new size.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param new_width 
 * @param new_height 
 */
template <typename T, typename RA_CONTAINER>
void grid_row_major<T, RA_CONTAINER>::resize(int new_width, int new_height) {
    if (new_width >= 0 && new_height >= 0) {
        _width = new_width;
        _height = new_height;
        data.resize(_width * _height);
    }
}

/**
 * @brief This method will try to replace the contents of this grid with the data 
 * from the specified file. To do this, it will open the file with a std::fstream 
 * and ask for data with the abstraction operator.
 * 
 * @tparam T 
 * @tparam RA_CONTAINER 
 * @param filename 
 * @return true 
 * @return false 
 */
template <typename T, typename RA_CONTAINER>
bool grid_row_major<T,RA_CONTAINER>::load_from_file(const std::string & filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return false;
    }

    int new_width, new_height;
    if (!(file >> new_width >> new_height)) {
        std::cerr << "Failed to read grid dimensions from the file." << std::endl;
        file.close();
        return false;
    }

    resize(new_width, new_height);

    for (int row = 0; row < new_height; ++row) {
        for (int col = 0; col < new_width; ++col) {
            if (!(file >> atrc(row, col))) {
                std::cerr << "Error reading data from the file." << std::endl;
                file.close();
                clear(); 
                return false;
            }
        }
    }

    file.close();

    return true;

}

////////////////////////////////////////////////////////////////////////////////
//
// Matrix Multiplication Implementation
//
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The GRID1, GRID2, and GRID3 template parameters are each (potentially different) 
 * classes that implement our grid functionality. What is important is that the lhs and rhs grids 
 * contain elements of types that can be multipled with each other and added to a double in a way 
 * that makes sense. The result grid needs to be able to have doubles assigned to it. You won't need 
 * to specify these types explicitly to call this function; the compiler will be able to deduce them 
 * automatically.
 * 
 * @tparam GRID1 
 * @tparam GRID2 
 * @tparam GRID3 
 * @param lhs 
 * @param rhs 
 * @param result 
 * @return true 
 * @return false 
 */
template <typename GRID1, typename GRID2, typename GRID3>
bool matrix_multiply(GRID1 lhs, GRID2 rhs, GRID3 & result) {
    if (lhs.width() != rhs.height()) {
        std::cerr << "Dimensions are invalid." << std::endl;
        return false;
    }

    result.resize(rhs.width(), lhs.height());

    for (int i = 0; i < lhs.height(); ++i) {
        for (int j = 0; j < rhs.width(); ++j) {
            result.atrc(i, j) = 0;
            for (int k = 0; k < lhs.width(); ++k) {
                result.atrc(i, j) += lhs.atrc(i, k) * rhs.atrc(k, j);
            }
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
//
// Column iterator implementation
//    These are for the col_iterator class I provided for you. Feel free to
// implement these to use that for your column iterators, or you can implement
// it in another way if you prefer that.
//
////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Preincrements the col_iterator by moving it to the next column.
 * 
 * @tparam ITERATOR 
 * @return auto& 
 */
template <typename ITERATOR>
auto & col_iterator<ITERATOR>::operator ++ () { // preincrement
    pos += width;
    return *this;
}

/**
 * @brief Postincrements the col_iterator, returning a copy of the original value.
 * 
 * @tparam ITERATOR 
 * @return auto 
 */
template <typename ITERATOR>
auto col_iterator<ITERATOR>::operator ++ (int) { // postincrement
    auto temp = *this;
    pos += width;
    return temp;
}

/**
 * @brief Adds an integer offset to the col_iterator, moving it to the corresponding column.
 * 
 * @param n 
 * @return * template <typename ITERATOR> 
 */
template <typename ITERATOR>
col_iterator <ITERATOR> col_iterator<ITERATOR>::operator + (int n) const {
    return col_iterator(pos + (n * width), width);
}

/**
 * @brief Accesses the element in the current column at the specified index.
 * 
 * @tparam ITERATOR 
 * @param n 
 * @return auto& 
 */
template <typename ITERATOR>
auto & col_iterator <ITERATOR>::operator [] (int n) {
    return pos[n * width];
}

/**
 * @brief Accesses the element in the current column at the specified index (const version).
 * 
 * @tparam ITERATOR 
 * @param n 
 * @return const auto& 
 */
template <typename ITERATOR>
const auto & col_iterator <ITERATOR>::operator [] (int n) const {
    return pos[n * width];
}

/**
 * @brief Dereferences the col_iterator, returning a reference to the current element 
 * in the column.
 * 
 * @return * template <typename ITERATOR>& 
 */
template <typename ITERATOR>
auto & col_iterator<ITERATOR>::operator * () {
    return *pos;
}

/**
 * @brief Dereferences the col_iterator, returning a reference to the current element 
 * in the column (const version).
 * 
 * @tparam ITERATOR 
 * @return const auto& 
 */
template <typename ITERATOR>
const auto & col_iterator<ITERATOR>::operator * () const {
    return *pos;
}

/**
 * @brief Checks if two col_iterators are equal.
 * 
 * @tparam ITERATOR 
 * @param other 
 * @return true 
 * @return false 
 */
template <typename ITERATOR>
bool col_iterator <ITERATOR>::operator == (const col_iterator <ITERATOR> &other) {
    return pos == other.pos;
}

#endif

