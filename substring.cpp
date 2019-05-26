

class SubstringFinder
{
private:
	string _text;
	string _substr;
	size_t _alph = 256;
	size_t _prime = 31;

public:
	SubstringFinder(string &t, string &s, size_t alph = 256) : _text(t), _substr(s), _alph(alph) {}

	vector<size_t>& Rabin_Carp()
	{
		size_t t_len = _text.length();
		size_t sub_len = _substr.length();
		size_t d_m = (int)pow(_alph, sub_len - 1) % (int)_prime;
		auto hash_t = 0, hash_s = 0;
		static vector<size_t> result;
		for (int i = 0; i < sub_len - 1; ++i)
		{
			hash_s = (int) (_alph * hash_s + (int) _substr[i])	% (int)_prime;
			hash_t = (int) (_alph * hash_t + (int) _text[i])	% (int)_prime;
		}
		for (size_t i = 0; i < t_len - sub_len; ++i)
		{

			if (hash_t == hash_s)
			{
				if (_substr == _text.substr(i, sub_len))
				{
					result.push_back(i);
				}
			}
			if (i < t_len - sub_len)
			{
				hash_t = (int) (_alph * (hash_t - d_m * (int) _text[i]) + _text[i + sub_len]) % (int)_prime;
			}
		}
		return result;
	}
};