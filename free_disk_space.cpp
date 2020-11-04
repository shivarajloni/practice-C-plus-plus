// A floppy disk shows f-bytes free and u-bytes used. If you delete a file of size
// o-bytes and create a new file of size n-bytes. how many free bytes will the floppy disk have?
// f, u, o, & n are user-entered value

#include <iostream>

using namespace std;

int main()
{
	int f, u, o, n;
	cout << "Enter Free disk size in bytes.. " << endl;
	cin >> f;

	cout << "Enter Used disk size in bytes.. " << endl;
	cin >> u;

	cout << "Enter old disk size in bytes.. " << endl;
	cin >> o;	

	cout << "Enter new disk size in bytes.. " << endl;
	cin >> n;

	int totalDiskSize = f + u;
	int currentUsedDiskSize = u - o;


	currentUsedDiskSize = currentUsedDiskSize + n;
	int currentFreeDiskSize = totalDiskSize - currentUsedDiskSize;

	cout<<"Free Space Available"<<currentUsedDiskSize<<"bytes";

	return 0;
};

// Has more Rum-time & execution Errors! 