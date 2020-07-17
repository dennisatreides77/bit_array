#pragma once

#include <type_traits>

namespace atr {
namespace low {
namespace bit {

	template<typename tp_word>
	class tm_bit_position final {
	public:
		using t_this	= tm_bit_position;
		using t_word	= typename std::enable_if<std::is_integral<tp_word>::value, tp_word>::type;
		using t_index	= std::size_t;

	private:
		constexpr static t_index offset_per_byte_array[17]	= { 1, 3, 4, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7 };
		constexpr static t_index index_right_shift			= offset_per_byte_array[sizeof(t_word)];
		constexpr static t_index offset_mask				= t_index(-1) >> ((sizeof(t_word) << 3) - index_right_shift);

	public:
		inline static t_index calc_request_word_number(t_index size_per_bit)
		{
			t_index sw = sizeof(t_word) << 3;
			return t_index((size_per_bit + (sw - 1)) / sw);
		}

	private:
		t_index			position;

	public:
		inline t_index	get(void) const
		{
			return this->position;
		}
		inline t_index	set(t_index position)
		{
			this->position = position;
			return;
		}
		inline t_index	get_index(void) const
		{
			return this->position >> index_right_shift;
		}
		inline t_index	get_offset(void) const
		{
			return this->position & offset_mask;
		}
		inline t_word	get_mask(void) const
		{
			return 1 << get_offset();
		}

	public:
		t_index operator - (const t_this& obj)
		{
			return this->position - obj->position;
		}
		t_this operator + (t_index offset) const
		{
			return t_this(this->position + offset);
		}
		t_this operator - (t_index offset) const
		{
			return t_this(this->position - offset);
		}
		t_this& operator += (t_index offset)
		{
			this->position += offset;
			return *this;
		}
		t_this& operator -= (t_index offset)
		{
			this->position -= offset;
			return *this;
		}
		t_this& operator ++ ()
		{
			++this->position;
			return *this;
		}
		t_this operator ++ (int)
		{
			return t_this(this->position + 1);
		}
		t_this& operator -- ()
		{
			--this->position;
			return *this;
		}
		t_this operator -- (int)
		{
			return t_this(this->position - 1);
		}

	public:
		bool operator == (t_index position)
		{
			return this->position == position;
		}
		bool operator != (t_index position)
		{
			return this->position != position;
		}
		bool operator <= (t_index position)
		{
			return this->position <= position;
		}
		bool operator < (t_index position)
		{
			return this->position < position;
		}
		bool operator >= (t_index position)
		{
			return this->position >= position;
		}
		bool operator > (t_index position)
		{
			return this->position > position;
		}

	public:
		t_this& operator = (t_index position)
		{
			this->position = position;
			return *this;
		}

		t_this& operator = (const t_this& obj)
		{
			this->position = obj.position;
			return *this;
		}

	public:
		inline tm_bit_position()
			: t_this::position(t_index(0))
		{
		}
		inline tm_bit_position(t_index position)
			: t_this::position(position)
		{
		}
		inline tm_bit_position(const t_this& obj)
			: t_this::position(obj.position)
		{
		}
	};

} // bit
} // low
} // atr
