// Implementations of the sudoku functions go in this file
// Details can be found in README.md

// This will be compiled to sudoku.o by the Makefile and linked when needed

#include "settings.h"
#include "sudoku.h"

void set_sudoku_cell_known(SUDOKUGRID &grid, int row, int col, int solution) {
  // XXX You need to implement this function
}

void set_sudoku_cell_unknown(SUDOKUGRID &grid, int row, int col) {
  // XXX You need to implement this function
}

// remove a specific possibility from the sudoku cell given
void remove_sudoku_option(SUDOKUGRID &grid, int row, int col, int value) {
  // XXX You need to implement this function
}

void print_sudoku_grid(std::ostream & ost, const SUDOKUGRID &grid, char unknown, char impossible) {
  // XXX You need to implement this function
}

////////////////////////////////////////////////////////////////////////////////
// This one is provided. You do not need to change it.
////////////////////////////////////////////////////////////////////////////////
int handle_sudoku_cell(SUDOKUGRID &grid, int row, int col) {
  int count = 0;

  count += handle_row_for_cell(grid, row, col); 
  count += handle_col_for_cell(grid, row, col); 
  count += handle_subgrid_for_cell(grid, row, col); 

  return count; }

int handle_row_for_cell(SUDOKUGRID &grid, int row, int col) {
  // XXX You need to implement this function
}
int handle_col_for_cell(SUDOKUGRID &grid, int row, int col) {
  // XXX You need to implement this function
}

int handle_subgrid_for_cell(SUDOKUGRID &grid, int row, int col) {
  // XXX You need to implement this function
}

bool load_sudoku_grid(const std::string &filename, SUDOKUGRID &grid) {
  // XXX You need to implement this function
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// This is what the implementation looks like for grid_row_major,
//   if you're using another SUDOKUGRID type, you will likely have to change it.
////////////////////////////////////////////////////////////////////////////////
void initialize_grid(SUDOKUGRID &grid) {
  grid.resize(9,9);
}

