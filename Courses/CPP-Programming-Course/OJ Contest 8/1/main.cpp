#include "management.h"

vector<student> studentList;

int main() {
	int n; cin >> n;
	int operation;
	void(*func[7])() = { NULL,add,change,queryByID,queryByName,outputID,outputSys };
	for (int i = 0; i < n; ++i) {
		cin >> operation;
		func[operation]();
	}
	return 0;
}