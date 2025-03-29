#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// int calculate(string s)
// {
//     stack<int> conNums;
//     stack<char> conString;
//     for (int i = 0; i < s.length(); ++i)
//     {
//         cout << i << " ";
//         char character = s[i];
//         if (s[i] == ' ')
//         {
//             continue;
//         }
//         if (character - '0' >= 0 && character - '0' <= 9)
//         {
//             cout << 1 << " ";
//             int num = 0;
//             while (i < s.length() && s[i] - '0' >= 0 && s[i] - '0' <= 9)
//             {
//                 num = num * 10 + (s[i] - '0');
//                 ++i;
//             }
//             cout << "Push " << num << endl;
//             conNums.push(num);
//             --i;
//         }
//         else
//         {
//             //
//             if (conNums.size() < 2 || conString.empty())
//             {
//                 cout << 2 << endl;
//                 conString.push(character);
//             }
//             else
//             {
//                 if ((character == '+' || character == '-') && (conString.top() == '*' || conString.top() == '/'))
//                 {

//                     char temp = conString.top();
//                     conString.pop();
//                     conString.push(character);
//                     int result = 0;
//                     int numTwo = conNums.top();
//                     conNums.pop();
//                     int numOne = conNums.top();
//                     conNums.pop();
//                     if (temp == '*')
//                         result = numOne * numTwo;
//                     if (temp == '/')
//                         result = numOne / numTwo;
//                     cout << "Result 3 " << result << endl;
//                     conNums.push(result);
//                 }
//                 else
//                 {
//                     if (conString.top() == '+' || conString.top() == '-')
//                     {
//                         cout << 4 << endl;
//                         conString.push(character);
//                     }
//                     // else
//                     // {
//                     //     char temp = conString.top();
//                     //     conString.pop();
//                     //     conString.push(character);
//                     //     int result = 0;
//                     //     int numTwo = conNums.top();
//                     //     conNums.pop();
//                     //     int numOne = conNums.top();
//                     //     conNums.pop();
//                     //     if (temp == '*')
//                     //         result = numOne * numTwo;
//                     //     if (temp == '/')
//                     //         result = numOne / numTwo;
//                     //     if (temp == '+')
//                     //         result = numOne + numTwo;
//                     //     if (temp == '-')
//                     //         result = numOne - numTwo;
//                     //     cout << 5 << endl;
//                     //     conNums.push(result);
//                     // }
//                 }
//             }
//         }
//     }
//     if (conString.top() == '*' || conString.top() == '/')
//     {
//         int result = 0;
//         int numTwo = conNums.top();
//         conNums.pop();
//         int numOne = conNums.top();
//         conNums.pop();
//         if (conString.top() == '*')
//             result = numOne * numTwo;
//         if (conString.top() == '/')
//             result = numOne / numTwo;
//         conString.pop();
//         conNums.push(result);
//     }
//     stack<char> tempStack;
//     while (!conString.empty())
//     {
//         tempStack.push(conString.top());
//         conString.pop();
//     }
//     while (!tempStack.empty())
//     {
//         char temp = tempStack.top();
//         tempStack.pop();
//         int result = 0;
//         int numTwo = conNums.top();
//         conNums.pop();
//         int numOne = conNums.top();
//         conNums.pop();
//         if (temp == '+')
//             result = numOne + numTwo;
//         if (temp == '-')
//             result = numOne - numTwo;
//         conNums.push(result);
//     }
//     return conNums.top();
// }

int calculate(string s)
{
    // stack<int> stackTemp;
    // Biến lưu trữ giá trị trước khi gặp 1 toán tử
    long int curr = 0;
    long int prevValue = 0;
    // Toán tử cần thực hiện của phép toán trước đó
    // Ta khởi tạo bằng + vì nếu toán số tiếp theo là số âm thì
    // Giá trị temp ta thêm vào trong stack sẻ là 0;
    // Nếu ta sử dụng prevValue thì giá prev đầu tiên luôn là 0 được thêm vào result vì bản thân op được khởi tạo giá trị ban đầu là +
    // Nếu gặp toán tử * hoặc / ở vị op đầu tiên trong string thì luôn tồn tại prev != nếu s[i] là digit trước đó khác 0
    char op = '+';
    long int result = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        //  Nếu s[i] là số thì ta tiếp tục cộng vào temp theo công thức curr = curr * 10  + (s[i] - '0')
        //  Vì có thể tồn tại chuỗi con liên tiếp là các số
        if (isdigit(s[i]))
        {
            curr = curr * 10 + (s[i] - '0');
        }
        // Nếu s[i] là 1 trong các toán tử
        // Chuỗi s luôn kết thúc với sô nên ta phải sử dụng trường hợp i == s.length() - 1 để tính kết quả cho phép toán trước số cuối cùng lưu vào prev
        if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
        {
            // Khi toán tử là + hoặc - thì result sẽ + giá trị trước đó vào vì bản thân prev đã lưu trũ dấu của giá trị
            if (op == '+' || op == '-')
            {
                result += prevValue;
                prevValue = (op == '+') ? curr : -curr;
            }
            else
            {
                if (op == '*' || op == '/')
                {
                    if (op == '*')
                        prevValue *= curr;
                    if (op == '/')
                        prevValue /= curr;
                }
            }
            // Lưu trữ phép toán hiện tại để xử lí ở dấu tiếp theo
            op = s[i];
            // Đưa curr về 0 để lưu trữ giá trị mới tiếp theo sau toán tử
            curr = 0;
        }
    }
    return result + prevValue;
}
int main()
{
    string s = "1*2-3/4+5*6-7*8+9/10"; // 7
    cout << calculate(s);
    return 0;
}