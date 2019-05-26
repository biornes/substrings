#include "substring.h"

int main()
{
	string text("testing");
	string sub("test");
	SubstringFinder obj(text, sub);
	auto result  = obj.Rabin_Carp();
	// cout << result.size() << endl;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	obj.getStopTable();
	// auto res = obj.Knuth_Morris_Pratt();
	// for (int i = 0; i < res.size(); ++i)
	// {
	// 	cout << res[i] << endl;
	// }
	cout << "QUIT\n";
	return 0;
}