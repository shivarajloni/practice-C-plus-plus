#include <iostream>
#include <stack>
#include <vector>
using namespace std;

        // Insert the given key in sorted stack while maintaining its sorted order
        // This is similar to recursive Insertion sort routine
void sortedInsert(stack<int> &stack, int key)
{
	        // Base case: if the stack is empty or
	        // the key is greater than all elements in the stack
	if (stack.empty() || key > stack.top())
	{
		stack.push(key);
		return;
	}

	    // Remove the top element
	int top = stack.top();
	stack.pop();

	    // recursion for the remaining elements in the stack
	sortedInsert(stack, key);

	// To insert the popped element back in the stack
	stack.push(top);
}

    // Recursive method to sort a stack
void sortstack(stack<int> &stack)
{
	    // Base case: stack is empty
	if (stack.empty()) {
		return;
	}

	    // remove the top element
	int top = stack.top();
	stack.pop();

	    // recursion for the remaining elements in the stack
	sortstack(stack);

	    // insert the popped element back in the sorted stack
	sortedInsert(stack, top);
}

void printStack(stack<int> stack)
{
	while (!stack.empty())
	{
		cout << stack.top() <<  " ";
		stack.pop();
	}
	cout << '\n';
}

int main()
{
	vector<int> list = { 5, -2, 9, -7, 3 };

	stack<int> stack;
	for (int i: list) {
		stack.push(i);
	}

	cout << "Stack before sorting : ";
	printStack(stack);

	sortstack(stack);

	cout << "Stack after sorting  : ";
	printStack(stack);
}