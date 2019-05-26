

class SubstringFinder
{
private:
	string _text;
	string _substr;
	size_t _alph = 31;
	int _prime = INT_MAX;

	vector<size_t>& prefixFunc()
	{
		static vector<size_t> pi(_substr.length());
		
		pi[0] = 0;
		size_t k = 0;

		for (size_t i = 0; i < _substr.length() - 1; ++i)
		{

			while (k > 0 and _text[k] != _text[i])
			{

				k = pi[k - 1];
			}
			if (_text[k] == _text[i])
			{
				// cout << 1<< endl;
				++k;
			}
			pi.push_back(k);
		}

		return pi;
	}


public:
	SubstringFinder(string &t, string &s, size_t alph = 31) : _text(t), _substr(s), _alph(alph) {}

	vector<size_t>& Rabin_Carp()
	{
		size_t t_len = _text.length();
		size_t sub_len = _substr.length();
		int d_m = (int)pow(_alph, sub_len - 1) % (int)_prime;
		int hash_t = 0, hash_s = 0;
		static vector<size_t> result;
		for (int i = 0; i < sub_len; ++i)
		{
			hash_s = (int) (_alph * hash_s + _substr[i])	% _prime;
			hash_t = (int) (_alph * hash_t + _text[i])		% _prime;
		}
		for (size_t i = 0; i < t_len - sub_len + 1; ++i)
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
				hash_t = (_alph * (hash_t - d_m * (_text[i])) + _text[i + sub_len]) % _prime;
			}
		}
		return result;
	}

	vector<int>& getStopTable()
	{
		static vector<int> stopTable(256, -1);
		for (int i = 0; i < _substr.length() - 1 ; ++i) stopTable[_substr[i]] = i;
		// for (int i = 0; i < stopTable.size(); ++i){
		// 	cout << (char)(i) << " " << stopTable[i] << endl;
		// }
		return stopTable;
	}

	vector<int>& getSuffixTable()
	{
		static vector<int> suffixTable();

		return suffixTable;
	}

	vector<size_t>& Boyer_Moore()
	{
		static vector<size_t> result;

		return result;

	}

	vector<size_t>& Knuth_Morris_Pratt()
	{
		static vector<size_t> result;
		auto pi = prefixFunc();
		size_t k = 0;
		for (size_t i = 0; i < _text.length(); ++i)
		{
			while (k > 0 and _substr[k] != _text[i])
			{
				k = pi[k - 1];
			}
			if (_substr[k] = _text[i]) { k++; }
			if ( k == _substr.length() )
			{
				result.push_back(i - _substr.length() + 1);
				k = pi[k - 1];
			}
		}

		return result;
	}
};