// Implement these functions to make the INI file parsing features work.
// See details in README.md.

// This will be compiled to iniparse.o and linked in when needed by make.

#include "settings.h"
#include "iniparse.h"

INI_CONFIG read_ini(std::istream &input, int verbosity) {
  // XXX You must implement this. Check README.md and reference output to see format.
}

bool write_ini( std::ostream & ost, const INI_CONFIG & config ) {
  // XXX You must implement this.
}

void print_ini( std::ostream & ost, const INI_CONFIG & config ) {
  // XXX You must implement this.
}

void add_ini_section(INI_CONFIG & config, const std::string &section) {
  // XXX You must implement this.
}

void remove_ini_section(INI_CONFIG & config, const std::string &section) {
  // XXX You must implement this.
}

std::string get_ini_key(const INI_CONFIG &config, const std::string &section, const std::string &key) {
  // XXX You must implement this.
}

void set_ini_key(INI_CONFIG &config, const std::string &section, const std::string &key, const std::string & value) {
  // XXX You must implement this.
}

int remove_ini_key(INI_CONFIG &config, const std::string &section, const std::string &key) {
  // XXX You must implement this.
}
