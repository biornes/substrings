#include "substring.h"

int main()
{
	string text("testinges");
	string sub("es");
	SubstringFinder obj(text, sub);
	auto result  = obj.Rabin_Carp();
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	cout << "_______________________\n";
	auto res = obj.Knuth_Morris_Pratt();
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	cout << "_______________________\n";
	auto resul = obj.Boyer_Moore();
	for (int i = 0; i < resul.size(); ++i)
	{
		// cout << endl;
		cout << resul[i] << endl;
	}
	cout << "QUIT\n";
	return 0;
}