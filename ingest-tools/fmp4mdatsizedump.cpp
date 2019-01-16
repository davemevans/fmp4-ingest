#include "fmp4stream.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>

using namespace fMP4Stream;
using namespace std;

int main(int argc, char *argv[])
{
	ingest_stream ingest_stream;
	if (argc > 1)
	{

		ifstream input(argv[1], ifstream::binary);

		if (!input.good())
		{
			cout << "failed loading input file: " << string(argv[1]) << endl;
			return 0;
		}

		try {
			ingest_stream.load_from_file(&input, true);
			input.close();
			ingest_stream.print_mdat_sizes();
		}
		catch (...)
		{
			cout << " unknown error reading the file " << endl;
		}
		return 1;
	}
	else
	{
		cout << "fmp4mdatsizedump: dumps mdat box sizes to the screen" << endl;
		cout << "usage: fmp4mdatsizedump input_file" << endl;
	}
}
