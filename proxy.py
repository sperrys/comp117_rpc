#!/bin/env python

#
#  proxy.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  Purpose: functions specific to the proxy 
# 

import basic_utils as utils 
import constants as c

# This function constructs the proxy function declaration
# for a given function name and signature 
def construct_func_decl(name, sig):
	args = sig["arguments"]
	argstring = ', '.join([a["type"] + ' ' + a["name"] for a in args])
	func_sig = sig["return_type"] + " " + name +'(' + argstring +')'

	return (func_sig + "  " + '{'  + "\n")

# This function constructs the proxy function body
# for a given function name and signature 
def construct_func_body(name, sig):
	args = sig["arguments"]
	num_args = len(args)
	body = """    // Compose the remote call\n    string message; \n    vector<string> pairs; \n\n"""
	body += """    // Remote Call metadata \n    pairs.push_back(jsonify_pair("method", "{name}", "string"));\n"""
	body += """    pairs.push_back(jsonify_pair("param_count", "{param_count}, "string)); \n \n"""
	body += """    // Remote call params \n    vector<string> param_objects; \n"""

	b = body.format(param_count=num_args, name=name)
	body = b 

	for a in args: 
		m = """    param_objects.push_back({type}, {name}));\n""";
		f_m = m.format(type=utils.add_handle(a["type"]), name=a["name"])
		body += f_m


	body += """\n    string params = jsonify_array(param_objects); \n"""
	body += """    pairs.push_back(jsonify_pair("params", params, "array")); \n\n""" 
	body += """    // Finalize the message \n""" 
	body += """    message = jsonify_object(pairs);\n\n"""
	body += """    // Send the remote call\n"""
	body += """    c150debug->printf(C150RPCDEBUG,\" {name}() invoked\");\n"""
	body += """    RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null \n\n""" 
	body += """    // Read the response\n"""
	body += """    c150debug->printf(C150RPCDEBUG,\"{name}() invocation sent, waiting for response\");\n"""
	body += """    string response = read_message(RPCPROXYSOCKET, read_message_size(RPCPROXYSOCKET));\n\n"""
	body += """    // Check the response\n"""
	body += """    if (extract_bool(response, "error")) {{ \n"""
	body += """        throw C150Exception("{name}() encountered an error during computation"); \n"""  
	body += """    }} \n"""
	body += """    c150debug->printf(C150RPCDEBUG, "{name}() successful return from remote call"); \n"""
	body += """    return """ + utils.add_deserialize(sig["return_type"]) + "(extract_object(response, \"result\"));\n }} \n\n"

	f_body = body.format(name=name)
	return f_body