#include "tcp.h"

using namespace std;
using namespace C150NETWORK;

size_t read_message_size(C150StreamSocket *socket) {
  char buffer[30];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket

  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = socket->read(buff_ptr, 1);  // read a byte

    if (*buff_ptr == '{') { return stoi(string(buffer)); }
    buff_ptr++;
    
    // error handling
    if (readlen == 0) {
      c150debug->printf(C150RPCDEBUG, "Read zero length message, checking EOF");
      if (socket-> eof()) {
        c150debug->printf(C150RPCDEBUG, "EOF signaled on input");
      } else {
        throw C150Exception("Unexpected zero length read without EOF");
      }
    }
  }

  // catchall error handling
  if (readlen == 0) {
    return 0;
  } else {
    throw C150Exception("Finding JSON size failed.");
  }
} 

string read_message(C150StreamSocket *socket, size_t message_size) {
  char buffer[message_size];
  char *buff_ptr = buffer;  // next char to read
  ssize_t readlen;          // amount of data read from socket
  bool read_null;


  for (unsigned int i = 0; i < sizeof(buffer); i++) {
    readlen = socket->read(buff_ptr, 1);  // read a byte
    if (readlen == 0) {
      break;
    } else if (*buff_ptr++ == '\0') {
      read_null = true;
      break;
    }
  }

  // error handling 
  if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"Read zero length message, checking EOF");
    if (socket-> eof()) {
      return "";
      c150debug->printf(C150RPCDEBUG,"EOF signaled on input");
    } else {
      throw C150Exception("Unexpected zero length read without EOF");
    }
  } else if (!read_null) { // If we didn't get a null, input message was poorly formatted
    throw C150Exception("Method name not null terminated or too long");
  }

  // buffer to string
  string message(buffer);
  cout << message  << endl;
  message = to_string(message_size) + "{" + message; // manually reformat message

  return message;
}