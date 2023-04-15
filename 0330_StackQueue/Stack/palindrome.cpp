// 회문 :
// abcdedcba는 회문.
// abcddcba도 회문.
// aba도 회문.

// 작동 원리 : (문자열 길이 / 2) 개 만큼 앞에서부터 차례로 스택에 넣어서
// 스택에 넣은 개수만큼 남은 문자열 개수도 맞춰서 (글자 길이 홀수면 앞에서 하나
// 뺸다.) 스택 delete한 것과 남은 문자열을 앞에서부터 차례로 비교. 구현은..스택
// 때문에 c++로 했습니다.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(string msg) {
    int len = msg.length();
    int index = len - len / 2;
    // 6이면 3, 7이면 4
    stack<char> s;
    // 012345 :
    for (int i = 1; i <= len / 2; i++) {
        s.push(msg[i - 1]); // 앞에서부터 len/2개 씩(나눗셈에서 나머지 버림)
    }
    for (; index < len; index++) {
        if (s.top() != msg[index]) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    string a;
    cout << "sentence : ";
    cin >> a;
    cout << a << " is"
         << (isPalindrome(a) ? " palindrome\n" : " not palindrome\n");
    return 0;
}