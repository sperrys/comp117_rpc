#!/bin/env python

#
#  constants.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  defines the used constants across rpc generation
#


# Constants for formatting  
CENTERED = 20
OFFSET = 10
INDENT = 4

# Constants for templating
COMMENT = "//"
SEMICOLON = ";"
COMMA = ','
NEWLINE = "\n"
SPACE = " "
EQUALS = "="
CONSTANT = "const "

INCLUDE = "#include "
NAMESPACE = "using namespace "

# These arrays define the libaries included 
# for the stub 
STUB_GLOBALS = ["string", "cstdio", "cstring", "utility.h"]
STUB_LOCALS = ["rpcstubhelper.h", "c150debug.h"]

# These arrays define the libaries included 
# for the proxy
PROXY_GLOBALS  = ["vector", "cstring", "cstdio", "stdbool.h", "iostream", "sstream"]
PROXY_LOCALS = ["rpcproxyhelper.h", "c150debug.h", "utility.h"]

#These arrays define the namespaces for each file 
P_NAMESPACE = ["C150NETWORK", "std"]
S_NAMESPACE = ["C150NETWORK"] 

#These arrays define the constants for each file
P_CONSTANTS = ["string VALUE_KEY = \"value\"", "string TYPE_KEY = \"type\"",
			   "string STRUCT_KEY = \"is_struct\"", "string ARRAY_KEY = \"is_array\""]

S_CONSTANTS = []

# Array of Basic Types Supported
BASIC_TYPES = ["int", "bool", "string", "char", "float", "void"]