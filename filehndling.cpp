// // // #include <iostream>
// // // using namespace std;
 
// // // // function to encode a alphabet as
// // // // Morse code
// // // string morseEncode(char x)
// // // {
 
// // //     // refer to the Morse table
// // //     // image attached in the article
// // //     switch (x) 
// // //     {
// // //     case 'A':
// // //         return ".-";
// // //     case 'B':
// // //         return "-...";
// // //     case 'C':
// // //         return "-.-.";
// // //     case 'D':
// // //         return "-..";
// // //     case 'E':
// // //         return ".";
// // //     case 'F':
// // //         return "..-.";
// // //     case 'G':
// // //         return "--.";
// // //     case 'H':
// // //         return "....";
// // //     case 'I':
// // //         return "..";
// // //     case 'J':
// // //         return ".---";
// // //     case 'K':
// // //         return "-.-";
// // //     case 'L':
// // //         return ".-..";
// // //     case 'M':
// // //         return "--";
// // //     case 'N':
// // //         return "-.";
// // //     case 'O':
// // //         return "---";
// // //     case 'P':
// // //         return ".--.";
// // //     case 'Q':
// // //         return "--.-";
// // //     case 'R':
// // //         return ".-.";
// // //     case 'S':
// // //         return "...";
// // //     case 'T':
// // //         return "-";
// // //     case 'U':
// // //         return "..-";
// // //     case 'V':
// // //         return "...-";
// // //     case 'W':
// // //         return ".--";
// // //     case 'X':
// // //         return "-..-";
// // //     case 'Y':
// // //         return "-.--";
// // //     case 'Z':
// // //         return "--..";
// // //     case ' ':
// // //         return ".....";
// // //     default:
// // //         cout << "Found invalid character: "<<endl;
             
// // //     }
// // // }
 
// // // void morseCode(string s)
// // // {
 
// // //     // character by character print
// // //     // Morse code
// // //     for (int i = 0; s[i]; i++)
// // //         cout << morseEncode(s[i]);
// // //     cout << endl;
// // // }
 
// // // // Driver's code
// // // int main()
// // // {
// // //     string s = "THIS IS MESSAGE";
// // //     morseCode(s);
// // //     return 0;
// // // }
// // #include <iostream>

// // using namespace std;

// // int main()
// // {
// // 	int count = 1, number, x = 0, A = 0, B = 9999;
// // 	int j = 1, k = 0;
// // 	cout << "Enter any number: ";
// // 	cin >> number;
// // 	cout << "Dual prime numbers are: " << endl;
// // 	while (count <= number)
// // 	{
// // 		while (j <= count)
// // 		{
// // 			if (count % j == 0)
// // 				k++;
// // 			j++;
// // 		}
// // 		if (k == 2) {
// // 			x++;
// // 			if (x % 2 == 0)
// // 				B = count;
// // 			if (x % 2 != 0)
// // 				A = count;
// // 			if (B - A == 2 || A - B == 2)
// // 				cout << A << " & " << B << endl;
// // }
    
// // 		count++;
// // 	}
// // 	return 0;
// // }





// #include<iostream>
// using namespace std;

// int main()
// {
// 	int arr1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
// 	int arr2[6][6];

// 	cout << " Enter values: \n";
// 	for (int i = 0; i < 6; i++)
// 	{
// 		cout << " Row " << i + 1 << ": ";
// 		for (int j = 0; j < 6; j++)
// 		{
// 			cin >> arr2[i][j];
// 		}
// 	}
// 	cout << "\n\n Displaying first array: " << endl;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		cout << " Row " << i + 1 << ": ";
// 		for (int j = 0; j < 3; j++)
// 		{
// 			cout << arr1[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	cout << "\n\n Displaying second array: " << endl;
// 	for (int i = 0; i < 6; i++)
// 	{
// 		cout << " Row " << i + 1 << ": ";
// 		for (int j = 0; j < 6; j++)
// 		{
// 			cout << arr2[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	int r, c;
// 	bool flag = true, exist = false;

// 	for(int i=0;i<6;i++) // array 2 rows
// 	{
// 		for(int j=0;j<6;j++) // array 2 columns
// 		{
// 			if (arr2[i][j] == arr1[0][0])
// 			{
// 				r = i; 
// 				c = j;
// 				int k, l;
// 				flag = true;
// 				for (k = 0; k < 3 && r<6; k++, r++) //array 1 rows
// 				{
// 					c = j;
// 					for (l = 0; l < 3 && c < 6 ; l++, c++)//array 1 columns
// 					{
// 						if (arr1[k][l] != arr2[r][c])
// 						{
// 							flag = false;
// 							break;
// 						}
// 					}
// 					if (!flag)
// 						break;
// 				}

// 				if (k == 3 && l == 3)
// 				{
// 					cout << "\n The 3x3 array exists in 6x6 array." << endl;
// 					exist = true;
// 				}
// 			}
// 		} 
// 		if (exist)
// 			break;
// 	}
// 	if (!exist)
// 		cout << "\n The 3x3 array does not exist in 6x6 array." << endl;


// 	return 0;
// }

#include <iostream>
using namespace std;

int main(){
    char string1[20];
    int i, length;
    int flag = 0;
    
    cout << "Enter a string: "; cin >> string1;
    
    length = strlen(string1);
    
    for(i=0;i < length ;i++){
        if(string1[i] != string1[length-i-1]){
            flag = 1;
            break;
           }
        }
    
    if (flag) {
        cout << string1 << " is not a palindrome" << endl; 
    }    
    else {
        cout << string1 << " is a palindrome" << endl; 
    }
    system("pause");
    return 0;
}