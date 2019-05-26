#include "substring.h"

int main()
{
	string text("test");
	string sub("a");
	SubstringFinder obj(text, sub);
	auto result  = obj.Rabin_Carp();
	// cout << result.size() << endl;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	cout << "QUIT\n";
	return 0;
}