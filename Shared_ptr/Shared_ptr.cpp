
#include "pch.h"
#include <iostream>
#include "shared_ptr.h"


int main()
{
	shared_ptr<int> p1(new int(9));
	std::cout << "p1.use_count " << p1.use_count() << "\n";
	std::cout << "p1.unique " << ((p1.unique()) ? "true" : "false") << "\n\n";

	shared_ptr<int> p2(new int(10));
	std::cout << "p2.use_count " << p2.use_count() << "\n";
	std::cout << "p2.unique " << ((p2.unique()) ? "true" : "false") << "\n\n";

	std::cout << "===================\n";
	shared_ptr<int> p3(p1);
	std::cout << "p1.use_count " << p1.use_count() << "\n";
	std::cout << "p1.unique " << ((p1.unique()) ? "true" : "false") << "\n\n";

	std::cout << "p2.use_count " << p2.use_count() << "\n";
	std::cout << "p2.unique " << ((p2.unique()) ? "true" : "false") << "\n\n";

	std::cout << "p3.use_count " << p3.use_count() << "\n";
	std::cout << "p3.unique " << ((p3.unique()) ? "true" : "false") << "\n\n";

	std::cout << "===================\n";
	p3 = p2;
	std::cout << "p1.use_count " << p1.use_count() << "\n";
	std::cout << "p1.unique " << ((p1.unique()) ? "true" : "false") << "\n\n";

	std::cout << "p2.use_count " << p2.use_count() << "\n";
	std::cout << "p2.unique " << ((p2.unique()) ? "true" : "false") << "\n\n";

	std::cout << "p3.use_count " << p3.use_count() << "\n";
	std::cout << "p3.unique " << ((p3.unique()) ? "true" : "false") << "\n\n";
	std::system("PAUSE");
	return 0;
}
