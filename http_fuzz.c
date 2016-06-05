#include "libtorrent/upnp.hpp"
#include "libtorrent/socket.hpp"
#include "libtorrent/socket_io.hpp" // print_endpoint
#include <fstream>
#include <functional>
#include <boost/ref.hpp>
#include <boost/smart_ptr.hpp>
#include <iostream>

int main (int argc, char* argv[]){
	using namespace libtorrent;
	namespace lt = libtorrent;

FILE *fp;
long lSize;
char *buffer;

while (__AFL_LOOP(1000)){
fp = fopen ( argv[1] , "rb" );
if( !fp ) perror("blah.txt"),exit(1);

fseek( fp , 0L , SEEK_END);
lSize = ftell( fp );
rewind( fp );

/* allocate memory for entire content */
buffer = (char*)calloc( 1, lSize+1 );
if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

/* copy the file into the buffer */
if( 1!=fread( buffer , lSize, 1 , fp) )
  fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);


http_parser p;
	bool error = false;

p.incoming(buffer::const_interval(buffer, buffer+lSize), error);


fclose(fp);
free(buffer);	
}

}
