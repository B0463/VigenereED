#pragma once

class Utils {
private:
public:
    int StrToInt(string choiceBuffer) {
        string okChars = "0123456789";
        bool confirm = true;
        for (int i = 0;i < choiceBuffer.length();i++) {
            bool confirmInter = false;
            for (int j = 0;j < 10;j++) {
                if (choiceBuffer[i] == okChars[j]) {
                    confirmInter = true;
                    break;
                }
                if (j == 9) {
                    break;
                }
            }
            if (confirmInter) {
                continue;
            }
            confirm = false;
            break;
        }
        if (confirm) {
            return std::stoi(choiceBuffer);
        }
        return -1;
    }
    void ClearConsole(void) {
        cout << "<console clear>\n";
    }
    string toUpper(string s)
    {
        std::transform(
            s.begin(),
            s.end(),
            s.begin(),
            [](unsigned char c) {
                return std::toupper(c);
            }
        );
        return s;
    }
    string toLower(string s)
    {
        std::transform(
            s.begin(),
            s.end(),
            s.begin(),
            [](unsigned char c) {
                return std::tolower(c);
            }
        );
        return s;
    }
    bool VerifyAlfaStringSW(string tvas) {
        string okChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        bool confirm = true;
        for (int i = 0;i < tvas.length();i++) {
            bool confirmInter = false;
            for (int j = 0;j < 26;j++) {
                if (tvas[i] == okChars[j]) {
                    confirmInter = true;
                    break;
                }
                if (j == 25) {
                    break;
                }
            }
            if (confirmInter) {
                continue;
            }
            confirm = false;
            break;
        }
        return confirm;
    }
    bool VerifyAlfaStringMW(string tvas) {
        string okChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        bool confirm = true;
        for (int i = 0;i < tvas.length();i++) {
            bool confirmInter = false;
            for (int j = 0;j < 27;j++) {
                if (tvas[i] == okChars[j]) {
                    confirmInter = true;
                    break;
                }
                if (j == 26) {
                    break;
                }
            }
            if (confirmInter) {
                continue;
            }
            confirm = false;
            break;
        }
        return confirm;
    }
    string GetFirstsChars(string text, int num) {
        string end;
        if (text.length() <= num) {
            return text;
        }
        if (num < 1) {
            return "";
        }
        for (int j = 0;j < num;j++) {
            end.push_back(text[j]);
        }
        return end;
    }
    void WaitKeyDown(void) {
        string WKDBuffer;
        getline(cin, WKDBuffer);
    }
};