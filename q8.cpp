// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0;
        while (i < str.size() && str[i] == ' ')
        {
            i++;
        }
        if (i == str.size())
        {
            return 0;
        }
        bool negative = false;
        if (str[i] == '-')
        {
            negative = true;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        long result = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
            if (result > INT_MAX)
            {
                return negative ? INT_MIN : INT_MAX;
            }
            i++;
        }
        return negative ? -result : result;
    }
};

// Approach 1: Finite State Machine
// Intuition
//  This is a typical finite state machine problem. We define a state transition table, and use it to determine the state of the automaton as we process each character in the string.
//  The state transition table is shown below. The table consists of 5 columns and 9 rows.
//  The first column is the current state,
//   the second column is the current character,
//   the third column is the sign of the number,
//   the fourth column is the number we have got so far
//   , and the fifth column is the next state.
//   The next state is determined by the current state and the current character.
//    The initial state is "start". The final state is "end".
//     The "end" state is the only state that can be a final state.
//     The other states can only be intermediate states. The "start" state can be an intermediate state or a final state. The "signed" state can be an intermediate state or a final state. The "in_number" state can only be an intermediate state. The "end" state can only be a final state.
//  The state transition table is shown below.
//  State Current character Sign Number Next state
//  start ' ' 1 0 start
//  start +/- 1 0 signed
//  start digit 1 0 in_number
//  start other 1 0 end
//  signed ' ' 1 0 signed
//  signed +/- 1 0 end
//  signed digit 1 0 in_number
//  signed other 1 0 end
//  in_number ' ' 1 0 in_number
//  in_number +/- 1 0 end
//  in_number digit 1 0 in_number
//  in_number other 1 0 end

// make the table in markdown
// | State | Current character | Sign | Next state |
// | :----: | :---------------: | :--: | :--------: |
// | start | ' ' | 1 | start |
// | start | '+' | 1 | signed |
// | start | '-' | 0 | signed |
// | start | digit | 1 | in_number |
// | start | other | 1 | end |
// | signed | ' ' | 1 | signed |
// | signed | '+/-' | 1 | end |
// | signed | digit | 1 | in_number |
// | signed | other | 1 | end |
// | in_number | ' ' | 1 | in_number |
// | in_number | '+' | 1 | end |
// | in_number | '-' | 0 | end |
// | in_number | digit | 1 | in_number |
// | in_number | other | 1 | end |

// Hope this helps!
// If you have any questions, please leave a comment below.
// If you like this article, please share it with your friends.
// If you want to read more articles like this, please follow me.
// Thank you for reading!
