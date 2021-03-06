#include "reader/module.ih"

namespace odc {
	bool Reader::isBigEndian() { // http://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program
		union {
			uint32_t i;
			uint8_t c[4];
		} test = {0x01020304};
		return test.c[0] == 1; 
	}

	bool Reader::isLittleEndian() {
		return !isBigEndian();
	}
}
