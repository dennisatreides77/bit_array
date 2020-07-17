
#include "tm_bit_position.h"
#include "tm_bit_array.h"

using t_bit_array = atr::low::bit::tm_bit_array<std::uint8_t>;

int main(int argc, char*argv[])
{
	std::uint8_t arr[3] = {0x37, 0x82, 0x6C};

	t_bit_array a1;
	t_bit_array a2(10);
	t_bit_array a3(a2);
	t_bit_array a4(t_bit_array(13));
	t_bit_array a5(arr, 3);
	t_bit_array a6(arr, 3, 10);
	t_bit_array a7(arr, 3, 33);

	return 0;
}