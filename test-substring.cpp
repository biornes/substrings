#include "substring.h"

int main()
{
	string text("testing testing");
	string sub("es");
	SubstringFinder obj(text, sub);
	auto result  = obj.Rabin_Carp();
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << "\n_______________________\n";
	auto res = obj.Knuth_Morris_Pratt();
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	cout << "\n_______________________\n";
	auto resul = obj.Boyer_Moore();
	for (int i = 0; i < resul.size(); ++i)
	{
		cout << resul[i] << " ";
	}
	cout << "\nQUIT\n";
	return 0;
}