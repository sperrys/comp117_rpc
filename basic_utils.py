#!/bin/env python

#
#  			 basic_utils.py 
#
#  Written by: Aaron Bowen, Spencer Perry
#
#  Purpose: Helpful mini functions that aid 
#  			with generation 
#

import constants as c 
import re 

# Helper Functions that Prepend Common Strings 
def add_quotes(word):
	return "\""+word+"\""
def add_arrows(word):
	return "<"+word+">"
def add_handle(name):
	return "handle_"+ name
def add_my(name):
	return "my_"+ name
def add_serialize(name):
	return "serialize_" + name
def add_deserialize(name):
	return "deserialize_" + name 
def add_prepend(name):
	return "__" + name
def remove_prepend(name):
	return name.replace("_","")
def has_prepend(name):
	return (name[0] == "_")
def strip_type(name):
	return re.sub(r'\[.+\]', "", name)
def strip_num_elements(name):
	name = str(name)
	return (re.findall(r'\[(.*?)\]', name))
def replace_brackets(name): 
	string = name.replace('[', '_')
	string = string.replace(']', '_')
	return string



# Function that generates the constants for a given stub type 
# Returns: the string of all the constants
def gen_constants(stub_type): 
	constants = ""
	
	if stub_type == "STUB":
		for n in c.S_CONSTANTS:
			constants += c.CONSTANT + n + ";\n"
	elif stub_type == "PROXY":
		for n in c.P_CONSTANTS:
			constants +=  c.CONSTANT + n + ";\n"		
	return constants

# Function that takes a stub_type and generates namespace
# Returns: the string of the namespaces
def gen_namespace(stub_type):
	n_spaces = ""
	
	if stub_type == "STUB":
		for n in c.S_NAMESPACE: 
			n_spaces += c.NAMESPACE + n + ";\n"

	elif stub_type == "PROXY":
		for n in c.P_NAMESPACE: 
			n_spaces += c.NAMESPACE + n + ";\n"

	return n_spaces

# function takes the current include statement
# and the stub type, then loops through the 
# global libraries and local libarys for the stub type
# Returns: An updated string with the correct library includes
def gen_libs(include, stub_type):
	if stub_type == "STUB":
		for g_lib in c.STUB_GLOBALS: 
			include += c.INCLUDE + add_arrows(g_lib) + "\n"
		for l_lib in c.STUB_LOCALS:
			include += c.INCLUDE + add_quotes(l_lib) + "\n"
	elif stub_type == "PROXY":
		for g_lib in c.PROXY_GLOBALS: 
			include += c.INCLUDE + add_arrows(g_lib) + "\n"
		for l_lib in c.PROXY_LOCALS:
			include += c.INCLUDE + add_quotes(l_lib) + "\n"
	return include

# function that takes the filebase and the file extension
# and generates comments for the head of the file
# Returns: string of the file comments  
def gen_head_comments(filebase, extension, stub_type):
	comments =  c.COMMENT + " --------------------------------------------------------------" + c.NEWLINE  
	comments += (c.COMMENT + c.NEWLINE) * 2
	comments += c.COMMENT + c.SPACE * c.CENTERED + filebase + extension + c.SPACE * c.CENTERED + c.NEWLINE 
	comments += c.COMMENT + c.NEWLINE
	comments += c.COMMENT + c.SPACE * c.OFFSET + "Authors: Aaron Bowen, Spencer Perry" + c.NEWLINE
	comments += c.COMMENT +  c.SPACE * c.OFFSET + "This is an auto-generated " + stub_type.lower() + "." + c.NEWLINE
	comments += (c.COMMENT + c.NEWLINE) * 2
	comments +=  c.COMMENT + " --------------------------------------------------------------" + c.NEWLINE

	return comments



