# bit_array
C++ simple bit position and simple bit array class

tm_bit_position is a simple class template for describing the position of a bit in an array of words. Calculates the index of a word in an array and a bit offset in the word. It can compute a query for the size of an array of words and compare it with other positions. tm_bit_array uses it to determine bit positions and to store the size of an array of pe bits.

tm_bit_array is a simple class template for storing bits. It uses std::vector to store words of bits.

tp_word in the description of templates defines the size of the used word for storage
