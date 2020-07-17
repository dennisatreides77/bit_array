#pragma once

#include "tm_bit_position.h"

#include <vector>

namespace atr {
namespace low {
namespace bit {

template<typename tp_word>
class tm_bit_array final {
public:
	using t_this		= tm_bit_array;
	using t_word		= typename std::enable_if<std::is_integral<tp_word>::value, tp_word>::type;
	using t_position	= tm_bit_position<t_word>;
	using t_array		= std::vector<t_word>;
	using t_index		= std::size_t;

private:
	t_position			size;
	t_array				array;

public:
	inline t_index get_size(void) const
	{
		return size;
	}

	inline void set_size(t_index size_per_bit)
	{
		array.resize(t_position::calc_size_per_words(size_per_bit), t_word(0));
		return;
	}

	inline bool tst_position(t_position pos) const
	{
		return pos < size;
	}

	inline bool get_at(t_position pos) const
	{
		t_index idx = pos.get_index();
		t_index off = pos.get_offset();
		return (array[idx] & (1 << off)) != 0;
	}

	inline void set_at(t_position pos, bool val)
	{
		t_index idx = pos.get_index();
		t_index off = pos.get_offset();
		if(val)
			array[idx] |= (1 << off);
		else
			array[idx] ^= ~(1 << off);
		return;
	}

	inline bool operator [] (t_position pos) const
	{
		return get_at(pos);
	}


public:
	t_this& operator = (const t_this& obj)
	{
		array		= obj.array;
		size		= obj.size;
		return *this;
	}

	t_this& operator = (t_this&& obj)
	{
		array		= std::move(obj.array);
		size		= obj.size;
		obj.size	= 0;
		return *this;
	}

public:
	inline tm_bit_array()
		: t_this::size(0)
	{
	}
	inline tm_bit_array(t_index size)
		: t_this::array(t_position::calc_request_word_number(size), t_word(0))
		, t_this::size(size)
	{
	}
	inline tm_bit_array(const t_this& obj) noexcept
		: t_this::array(obj.array)
		, t_this::size(obj.size)
	{
	}
	inline tm_bit_array(t_this&& obj) noexcept
		: t_this::array(std::move(obj.array))
		, t_this::size(obj.size)
	{
		obj.size = 0;
	}
	inline tm_bit_array(const t_word* arr, t_index size, t_index size_per_bit = 0) noexcept
		: t_this::array(arr, arr + size)
		, t_this::size(sizeof(t_word) * 8 * size)
	{
		if (size_per_bit > 0)
		{
			t_index s = t_position::calc_request_word_number(size_per_bit);
			if (size != s)
			{
				this->array.resize(s, t_word(0));
				this->size = size_per_bit;
			}
		}
	}
};

} // bit
} // low
} // atr
