#include "byte_buffer.hpp"



bool isLittleEndian()
{
	ByteBuffer<int32_t> buff;
	buff.data = 0xff000000;
	return buff.bytes[3] == 0xff;
}
bool isBigEndian()
{
	ByteBuffer<int32_t> buff;
	buff.data = 0xff000000;
	return buff.bytes[0] == 0xff;
}