/* Encode */
#pragma once

class Encode {
    /* Required Packs */
    Utils Utils;
private:
    /* Private */
    /* Functions */
    string QueryText(void) {
        string textBuffer;
        cout << "Type text to encode: ";
        getline(cin, textBuffer);
        return textBuffer;
    }
    string QueryKey(void) {
        string keyBuffer;
        cout << "Type key to encode: ";
        getline(cin, keyBuffer);
        return keyBuffer;
    }
    char EncodeTable(char text, char key) {
        char t = text;
        char k = key;
        int ti = t;
        int ki = k;

        string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (t == 'A') return k;
        if (k == 'A') return t;

        for (int i = 0;i < alfa.length();i++) {
            if (t == alfa[i]) {
                if (ki + i > 90) {
                    return 64 + ((ki + i) - 90);
                }
                return ki + i;
            }
        }
    }
    string encode(string text, string key) {
        if (!Utils.VerifyCharString(key, Utils.pchar)) {
            cout << "invalid key\n";
            return "";
        }
        if (!Utils.VerifyCharString(text, Utils.pchar)) {
            cout << "invalid text\n";
            return "";
        }
        string fKey = "";
        string end = "";
        if (key.length() == text.length()) {
            fKey = key;
        }
        else if (key.length() > text.length()) {
            fKey = Utils.GetFirstsChars(key, text.length());
        }
        else if (key.length() < text.length()) {
            fKey = fKey + key;
            string pKey;
            bool conf = false;
            while (true) {
                if (!conf) {
                    pKey = "";
                    pKey = fKey + key;
                }
                else {
                    pKey = pKey + key;
                }
                if (pKey.length() == text.length()) {
                    fKey = pKey;
                    break;
                }
                if (pKey.length() > text.length()) {
                    fKey = Utils.GetFirstsChars(pKey, pKey.length() - key.length()) + Utils.GetFirstsChars(key, text.length() - Utils.GetFirstsChars(text, fKey.length()).length());
                    break;
                }
                conf = true;
            }
        }

        for (int i = 0;i < text.length();i++) {
            bool conf = false;
            for (int j = 0; j < Utils.cchar.length(); j++) {
                if (text[i] == Utils.cchar[j]) {
                    end = end + Utils.cchar[j];
                    conf = true;
                    break;
                };
            }
            if (!conf) end = end + EncodeTable(text[i], fKey[i]);
        }
        return end;
    }
public:
    /* Public */
    /* Functions */
    void init(void) {
        Utils.ClearConsole();
        string text = Utils.toUpper(QueryText());
        string key = Utils.toUpper(QueryKey());
        string encoded = Utils.toLower(encode(text, key));
        cout << "encoded: " << encoded << "\n";
        Utils.WaitKeyDown();
    }
};