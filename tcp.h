#include "c150streamsocket.h"

size_t read_message_size(C150NETWORK::C150StreamSocket *socket);
string read_message(C150NETWORK::C150StreamSocket *socket, size_t message_size);
