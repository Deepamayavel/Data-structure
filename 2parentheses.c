#include <stdio.h>
#include <string.h>

int longestValidParentheses(char *s) {
    int n = strlen(s);
    int stack[n + 1];
    int top = -1;
    int maxLen = 0;
    int lastInvalid = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            if (top >= 0) {
                // Found a matching '('
                top--;
                if (top >= 0)
                    maxLen = (maxLen > i - stack[top]) ? maxLen : (i - stack[top]);
                else
                    maxLen = (maxLen > i - lastInvalid) ? maxLen : (i - lastInvalid);
            } else {
                // No matching '(' for this ')'
                lastInvalid = i;
            }
        }
    }
    return maxLen;
}

int main() {
    char input[100];
    char s[100];
    int j = 0;

    printf("Enter a string containing only '(' and ')': ");
    scanf("%[^\n]", input);  // read entire line (including quotes if any)

    // Filter only '(' and ')'
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(' || input[i] == ')') {
            s[j++] = input[i];
        }
    }
    s[j] = '\0';

    int result = longestValidParentheses(s);
    printf("Input: s = \"%s\"\n", s);

    if (result == 0)
        printf("There is no valid parentheses substring.\n");
    else
        printf("Output: %d\n", result);
    return 0;
}
