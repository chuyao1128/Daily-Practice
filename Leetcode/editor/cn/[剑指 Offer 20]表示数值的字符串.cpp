//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"012
//3"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
//
//
// Related Topics 数学
// 👍 71 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    enum State {
        STATE_START,
        STATE_SIGN_INT,
        STATE_INTEGER,
        STATE_POINT_WITHOUT_INT,
        STATE_POINT,
        STATE_DECIMAL,
        STATE_EXE,
        STATE_SIGN_EXP,
        STATE_INTEGER_EXP,
        STATE_END
    };
    enum CharType {
        CHAR_SPACE,
        CHAR_NUMBER,
        CHAR_SIGN,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch == ' ')
            return CHAR_SPACE;
        if (ch >= '0' && ch <= '9')
            return CHAR_NUMBER;
        if (ch == '+' || ch == '-')
            return CHAR_SIGN;
        if (ch == 'e' || ch == 'E')
            return CHAR_EXP;
        if (ch == '.')
            return CHAR_POINT;
        else
            return CHAR_ILLEGAL;
    }


    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
                {STATE_START, {{CHAR_SPACE, STATE_START}, {CHAR_SIGN, STATE_SIGN_INT}, {CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
                {STATE_SIGN_INT, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
                {STATE_INTEGER, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT}, {CHAR_EXP, STATE_EXE}, {CHAR_SPACE, STATE_END}}},
                {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_DECIMAL}}},
                {STATE_POINT, {{CHAR_NUMBER, STATE_DECIMAL}, {CHAR_EXP, STATE_EXE}, {CHAR_SPACE, STATE_END}}},
                {STATE_DECIMAL, {{CHAR_NUMBER, STATE_DECIMAL}, {CHAR_EXP, STATE_EXE}, {CHAR_SPACE, STATE_END}}},
                {STATE_EXE, {{CHAR_SIGN, STATE_SIGN_EXP}, {CHAR_NUMBER, STATE_INTEGER_EXP}}},
                {STATE_SIGN_EXP, {{CHAR_NUMBER, STATE_INTEGER_EXP}}},
                {STATE_INTEGER_EXP, {{CHAR_NUMBER, STATE_INTEGER_EXP}, {CHAR_SPACE, STATE_END}}},
                {STATE_END, {{CHAR_SPACE, STATE_END}}}};
        int len = s.length();
        State st = STATE_START;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            //如果key存在，则find返回key对应的迭代器，如果key不存在，则find返回unordered_map::end。
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_DECIMAL || st == STATE_INTEGER_EXP || st == STATE_END;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
