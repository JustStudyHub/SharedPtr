#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Shared_ptr\shared_ptr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sharedPtrTest
{		
	
	TEST_CLASS(ConstructorTestInt)
	{
	public:		
		

		TEST_METHOD(CopyConstrucotor)
		{
			try
			{
				shared_ptr<int> p1(new int(9));
				Assert::AreEqual(1, p1.use_count());
                {
				    shared_ptr<int> p2(p1);
					Assert::AreEqual(2, p1.use_count());
					Assert::AreEqual(2, p2.use_count());
				    shared_ptr<int> p3(p2);
					Assert::AreEqual(3, p1.use_count());
					Assert::AreEqual(3, p2.use_count());
					Assert::AreEqual(3, p3.use_count());
				    shared_ptr<int> p4(p3);
					Assert::AreEqual(4, p1.use_count());
					Assert::AreEqual(4, p2.use_count());
					Assert::AreEqual(4, p3.use_count());
					Assert::AreEqual(4, p4.use_count());
                }
				Assert::AreEqual(1, p1.use_count());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(ConstructorTestString)
	{
	public:
		
		TEST_METHOD(CopyConstrucotor)
		{
			try
			{
				shared_ptr<std::string> p1(new std::string("dfvd"));
				Assert::AreEqual(1, p1.use_count());
				{
					shared_ptr<std::string> p2(p1);
					Assert::AreEqual(2, p1.use_count());
					Assert::AreEqual(2, p2.use_count());
					shared_ptr<std::string> p3(p2);
					Assert::AreEqual(3, p1.use_count());
					Assert::AreEqual(3, p2.use_count());
					Assert::AreEqual(3, p3.use_count());
					shared_ptr<std::string> p4(p3);
					Assert::AreEqual(4, p1.use_count());
					Assert::AreEqual(4, p2.use_count());
					Assert::AreEqual(4, p3.use_count());
					Assert::AreEqual(4, p4.use_count());
				}
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(OpertorTestInt)
	{
	public:
		TEST_METHOD(AssignmentOperator)
		{
			try
			{
				shared_ptr<int> p1(new int(9));
				shared_ptr<int> p2(new int(100000));
				p1 = p2;
				Assert::AreEqual(*p1, *p2);
				Assert::AreEqual(2, p1.use_count());
				Assert::AreEqual(2, p2.use_count());
				p2 = p1;
				Assert::AreEqual(2, p1.use_count());
				Assert::AreEqual(2, p2.use_count());
				shared_ptr<int> p3;
				shared_ptr<int> p4(new int(200));
				p3 = p4;
				Assert::AreEqual(*p3, *p4);
				Assert::AreEqual(2, p3.use_count());
				Assert::AreEqual(2, p4.use_count());
				p3 = p3;
				Assert::AreEqual(*p3, 200);
				Assert::AreEqual(2, p3.use_count());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
	TEST_CLASS(OpertorTestString)
	{
	public:
		TEST_METHOD(AssignmentOperator)
		{
			try
			{
				shared_ptr<std::string> p1(new std::string("dfvd"));
				shared_ptr<std::string> p2(new std::string("dfvsdsvsvsd"));
				p1 = p2;
				Assert::AreEqual(*p1, *p2);
				Assert::AreEqual(2, p1.use_count());
				Assert::AreEqual(2, p2.use_count());
				p2 = p1;
				Assert::AreEqual(2, p1.use_count());
				Assert::AreEqual(2, p2.use_count());
				shared_ptr<std::string> p3;
				shared_ptr<std::string> p4(new std::string("d"));
				p3 = p4;
				Assert::AreEqual(*p3, *p4);
				Assert::AreEqual(2, p3.use_count());
				Assert::AreEqual(2, p4.use_count());
				p3 = p3;
				Assert::AreEqual(*p3, *p4);
				Assert::AreEqual(2, p3.use_count());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}		
	};

}