
// Recursion Approach


#include <bits/stdc++.h> 

void sortedInsert(stack<int> &st, int element){
	if(st.empty() || element > st.top()){
		st.push(element);
		return;
	}

	int top=st.top();
	st.pop();

	sortedInsert(st, element);
	st.push(top);
}

void sortStack(stack<int> &st)
{
	// Write your code here
	if(st.empty()) return;

	int top = st.top();
	st.pop();

	sortStack(st);

	sortedInsert(st, top);
}