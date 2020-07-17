# bit_array
C++ simple Bit position and simple Bit array class

tm_bit_position is a simple class template to describe position of the bit in a word array. It calc a index of word in array and a offset of the bit in the word. 
It may calc request the word array size and compares with another the positions. tm_bit_array use it to define positions of the bits and to storage array size pe bits.

tm_bit_array is a simple class template to storage bits. It use std::vector to save words of the bits.

tp_word in the templates description define size of the used word to storage
