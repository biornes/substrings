

class SubstringFinder
{
private:
	string _text;
	string _substr;
	size_t _alph = 31;
	int _prime = INT_MAX;
	// int _prime = 174281;

	vector<size_t>& prefixFunc(string text)
	{
		// cout << "prefixFunc " << text << endl;
		static vector<size_t> pi(text.length(), 0);
		
		pi[0] = 0;
		size_t k = 0;

		for (size_t i = 1; i < text.length() - 1; ++i)
		{

			while (k > 0 and text[k] != text[i])
			{
				// cout << 2 << endl;
				k = pi[k - 1];
			}
			if (text[k] == text[i])
			{
				// cout << 1<< endl;
				++k;
			}
			// pi.push_back(k);
			pi[i] = k;
		}

		return pi;
	}


public:
	SubstringFinder(string &t, string &s, size_t alph = 26) : _text(t), _substr(s), _alph(alph) {}

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
		size_t m = _substr.length();
		static vector<int> suffixTable(m + 1, m);
		// cout << "SIZE: " << suffixTable.size() << endl;
		auto pi = prefixFunc(_substr);

		
		// for (int i = 0; i < m; ++i)
		// {
		// 	cout << pi[i];
		// }
		// size_t up_est = m - pi[m - 1];
		reverse(_substr.begin(), _substr.end());
		// cout << _substr << endl;
		auto pi_reverse = prefixFunc(_substr);
		reverse(_substr.begin(), _substr.end());
		// cout << _substr << endl;
		// vector<int> Index(m, m);
		// cout << "\n*****\n";
		for (int i = 0;  i < m +1 ; ++i)
		{
			suffixTable[i] = m - pi[m - 1];
			
			// cout << Index[i];
		}
		// cout << "\n*****\n";
	
		vector<int> Shift(m, 0);
		// cout << endl;
		// int ind = 0;
		for (int i = 0;  i < m ; ++i)
		{
			int ind = m - pi_reverse[i];
			int shift = i - pi_reverse[i] + 1;
			if (suffixTable[ind] > shift)
			{
				suffixTable[ind] = shift;
			}
			// cout << Index[i] << " ";
			// cout << Shift[i] << endl;
		}
		// for (int i = 0; i < m - 1; ++i)
		// {
			
		// }
		// for (int i = 0;  i < m + 1 ; ++i)
		// {
		// 	// suffixTable[i] = i - pi_reverse[i] + 1;
		// 	cout << suffixTable[i];
		// }
		return suffixTable;
	}

	vector<int>& Boyer_Moore()
	{
		static vector<int> result;
		vector<int> suff = getSuffixTable();
		vector<int> stop = getStopTable();
		// int delta_stop = 0;
		int j = 0;
		for (int i = 0; i < _text.length() - _substr.length() + 1; )
		{
			// cout << _text[i] << endl;
			j = _substr.length() - 1;
			// cout << j << (_substr[j] == _text[i+j]) << endl;
			while (j >= 0 and _substr[j] == _text[i + j]){ --j; /*cout << "";*/}
			int delta_stop;
			if (j == -1)
			{
				// cout << "j == -1" << endl;
				result.push_back(i);
				delta_stop = 1;
			}
			else
			{
				// cout << "I + J : " << stop[_text[i + j]] << endl;
				delta_stop = j - stop[_text[i + j]];
				// cout << "Delta stop: " << delta_stop << endl;
				// cout << "J: " << j << " " << stop[_text[i + j]];
			}
			int delta_suff = suff[j + 1];
			// cout << "delta_suff: " << delta_suff << endl;
			i += max (delta_stop, delta_suff);
			// cout << max(delta_stop, delta_suff) << endl;
			// cout << i << endl;
		}
		return result;

	}

	vector<size_t>& Knuth_Morris_Pratt()
	{
		static vector<size_t> result;
		auto pi = prefixFunc(_substr);
		size_t k = 0;
		for (size_t i = 0; i < _text.length(); ++i)
		{
			while (k > 0 and _substr[k] != _text[i])
			{
				k = pi[k - 1];
			}
			if (_substr[k] == _text[i]) { k++; }
			if ( k == _substr.length() )
			{
				result.push_back(i - _substr.length() + 1);
				k = pi[k - 1];
			}
		}

		return result;
	}

	// int _max(int a, int b){
	// 	cout << "_MAX" ;
	// 	if (a>b) return a;
	// 	else return b;
		// return a < b ? b : a;

	// }
};