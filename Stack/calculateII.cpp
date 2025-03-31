#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

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
int calculateII(string s)
{
    stack<int> number;
    int currNumber = 0;
    char op = '+';
    int result = 0;
    s += "+";
    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
        {
            currNumber = currNumber * 10 + s[i] - '0';
            continue;
        }
        if (s[i] == ' ')
            continue;
        else
        {
            if (op == '+' || op == '-')
            {
                number.push((op == '+' ? currNumber : -currNumber));
            }
            if (op == '*' || op == '/')
            {
                int tmp = number.top();
                number.pop();
                if (op == '*')
                    number.push(tmp * currNumber);
                else
                    number.push(tmp / currNumber);
            }
            currNumber = 0;
            op = s[i];
        }
    }

    while (!number.empty())
    {
        cout << number.top() << endl;
        result += number.top();
        number.pop();
    }
    return result;
}
int main()
{
    string s = "1*2-3/4+5*6-7*8+9/10"; // 7
    cout << calculateII(s);
    return 0;
}