#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_3_it/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreateLists)
		{
			int values[] = { 1, -2, 3, -4, 5, -6, 7, -8, 9 };
			int size = sizeof(values) / sizeof(values[0]);

			pair<Node*, Node*> lists = createLists(values, size);

			Node* head1 = lists.first;
			Node* head2 = lists.second;

			Assert::AreEqual(1, head1->data);
			Assert::AreEqual(3, head1->next->data);
			Assert::AreEqual(5, head1->next->next->data);
			Assert::AreEqual(7, head1->next->next->next->data);
			Assert::AreEqual(9, head1->next->next->next->next->data);

			Assert::AreEqual(-2, head2->data);
			Assert::AreEqual(-4, head2->next->data);
			Assert::AreEqual(-6, head2->next->next->data);
			Assert::AreEqual(-8, head2->next->next->next->data);
		}
	};
}
