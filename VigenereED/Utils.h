/* Utils */
#pragma once

class Utils {
private:
public:
    /* Public */
    /* Vars */
    string pchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234567890:;?!/\\.,\"'()[]{}-_ ";
    string cchar = ":;?!/\\.,\"'()[]{}-_ ";
    /* Functions */
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
        #if defined(_WIN32) || defined(_WIN64)
                system("cls");
        #else defined(__linux__) || defined(__unix__)
                system("clear");
        #endif
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
    bool VerifyCharString(string stv, string perms) {
        bool confirm = true;
        for (int i = 0; i < stv.length(); i++) {
            bool confirmInter = false;
            for (int j = 0; j < perms.length(); j++) {
                if (stv[i] == perms[j]) {
                    confirmInter = true;
                    break;
                }
                if (j == perms.length() - 1) {
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