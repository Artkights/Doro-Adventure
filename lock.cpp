#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int validCount = 0;
// SHA-256�㷨��C++ʵ�֣��������ⲿ��
class SHA256 {
private:
    // SHA-256�㷨�ĳ���
    const static uint32_t K[64];

    // ��ʼ��ϣֵ������SHA-256��׼��
    array<uint32_t, 8> H = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // ���ߺ���������ת
    inline uint32_t rightRotate(uint32_t value, unsigned int count) {
        return (value >> count) | (value << (32 - count));
    }

    // ������512λ�����ݿ�
    void processBlock(const uint8_t* block) {
        // ������Ϣ���ȱ�
        uint32_t W[64];
        for (int t = 0; t < 16; t++) {
            W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) |
                (block[t * 4 + 2] << 8) | (block[t * 4 + 3]);
        }

        // ��չ��Ϣ���ȱ�
        for (int t = 16; t < 64; t++) {
            uint32_t s0 = rightRotate(W[t - 15], 7) ^ rightRotate(W[t - 15], 18) ^ (W[t - 15] >> 3);
            uint32_t s1 = rightRotate(W[t - 2], 17) ^ rightRotate(W[t - 2], 19) ^ (W[t - 2] >> 10);
            W[t] = W[t - 16] + s0 + W[t - 7] + s1;
        }

        // ��ʼ����������
        uint32_t a = H[0];
        uint32_t b = H[1];
        uint32_t c = H[2];
        uint32_t d = H[3];
        uint32_t e = H[4];
        uint32_t f = H[5];
        uint32_t g = H[6];
        uint32_t h = H[7];

        // ��ѭ��
        for (int t = 0; t < 64; t++) {
            uint32_t S1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + K[t] + W[t];
            uint32_t S0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // ���¹�ϣֵ
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

public:
    // �����������ݵ�SHA-256��ϣֵ
    vector<uint8_t> compute(const vector<uint8_t>& message) {
        // ��������ĳ��ȣ�ԭʼ���� + 1�ֽڵ�1 + ���0 + 8�ֽڵĳ��ȣ�
        uint64_t originalBitLength = message.size() * 8;
        uint64_t paddedLength = message.size() + 1 + 8; // ������Ҫ���9���ֽ�
        paddedLength = (paddedLength + 63) & ~63;       // ����Ϊ64�ֽڵı�����512λ��

        // �����������Ϣ
        vector<uint8_t> paddedMessage(paddedLength, 0);
        copy(message.begin(), message.end(), paddedMessage.begin());

        // ���һ��1λ����Ϊһ���ֽڵ�0x80��
        paddedMessage[message.size()] = 0x80;

        // �����Ϣ���ȣ���λΪ��λ�������
        for (int i = 0; i < 8; i++) {
            paddedMessage[paddedLength - 8 + i] = (originalBitLength >> ((7 - i) * 8)) & 0xFF;
        }

        // ���鴦����Ϣ
        for (size_t i = 0; i < paddedLength; i += 64) {
            processBlock(&paddedMessage[i]);
        }

        // �������չ�ϣֵ��32�ֽڣ�
        vector<uint8_t> hash(32);
        for (int i = 0; i < 8; i++) {
            hash[i * 4] = (H[i] >> 24) & 0xFF;
            hash[i * 4 + 1] = (H[i] >> 16) & 0xFF;
            hash[i * 4 + 2] = (H[i] >> 8) & 0xFF;
            hash[i * 4 + 3] = H[i] & 0xFF;
        }

        return hash;
    }

    // ���ù�ϣ״̬
    void reset() {
        H = {
            0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
            0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
        };
    }
};

// SHA-256�㷨�ĳ���������SHA-256��׼��
const uint32_t SHA256::K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

class PasswordLock {
private:
    // ��Python�汾�����saltֵ: b'\xb2S"e}\xdf\xb0\xfe\x9c\xde\xde\xfe\xf3\x1d\xdc>'
    vector<unsigned char> salt = {
        0xb2, 0x53, 0x22, 0x65, 0x7d, 0xdf, 0xb0, 0xfe,
        0x9c, 0xde, 0xde, 0xfe, 0xf3, 0x1d, 0xdc, 0x3e
    };

    // �������������ֽ�����ת��Ϊʮ�������ַ���
    string bytesToHex(const vector<uint8_t>& bytes) {
        stringstream ss;
        for (const auto& byte : bytes) {
            ss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
        }
        return ss.str();
    }

public:
    string hashPassword(const string& password) {
        // ������ת��Ϊ�ֽ���
        vector<unsigned char> passwordBytes(password.begin(), password.end());

        vector<unsigned char> combined;
        combined.insert(combined.end(), salt.begin(), salt.end());
        combined.insert(combined.end(), passwordBytes.begin(), passwordBytes.end());

        SHA256 sha256;
        vector<uint8_t> hashBytes = sha256.compute(combined);

        return bytesToHex(hashBytes);
    }

    // ��֤����
    bool verifyPassword(const string& inputPassword, const string& storedHash) {
        // ʹ����ͬ����ֵ������������й�ϣ
        string calculatedHash = hashPassword(inputPassword);

        // �Ƚϼ�����Ĺ�ϣֵ��洢�Ĺ�ϣֵ
        return calculatedHash == storedHash;
    }
};

// ����Ƿ�Ϊ����
bool isPrime(int num) {
    return (num == 2 || num == 3 || num == 5 || num == 7);
}

// ���������ַ���Ϊ�����б����ֲ��䣩
vector<vector<int>> parseInput(const string& input) {
    vector<vector<int>> rules;
    vector<int> currentRule;
    string numStr = "";
    bool inBracket = false;

    for (char c : input) {
        if (c == '[') {
            inBracket = true;
            currentRule.clear();
            numStr = "";
        }
        else if (c == ']') {
            if (inBracket) {
                if (!numStr.empty()) {
                    currentRule.push_back(stoi(numStr));
                    numStr = "";
                }
                if (!currentRule.empty()) {
                    rules.push_back(currentRule);
                }
            }
            inBracket = false;
        }
        else if (inBracket) {
            if (c == ',' || c == ' ') {
                if (!numStr.empty()) {
                    currentRule.push_back(stoi(numStr));
                    numStr = "";
                }
            }
            else if (isdigit(c) || c == '-') {
                numStr += c;
            }
        }
    }
    return rules;
}

// ��鵱ǰ���������Ƿ����������򣨼�֦������
bool isValid(const vector<int>& partialPassword, const vector<vector<int>>& rules) {
    for (const auto& rule : rules) {
        if (rule.size() == 2) {
            if (rule[0] == -1 && rule[1] == -1) {
                // ���������Ƿ�ȫ�������Ҳ��ظ�
                set<int> digits;
                for (int digit : partialPassword) {
                    if (!isPrime(digit)) return false;
                    digits.insert(digit);
                }
                if (digits.size() != partialPassword.size()) return false;
            }
            else if (rule[0] >= 1 && rule[0] <= 3 && rule[1] == 0) {
                int pos = rule[0] - 1;
                if (pos < partialPassword.size() && partialPassword[pos] % 2 != 0) return false;
            }
            else if (rule[0] >= 1 && rule[0] <= 3 && rule[1] == 1) {
                int pos = rule[0] - 1;
                if (pos < partialPassword.size() && partialPassword[pos] % 2 == 0) return false;
            }
        }


        else if (rule.size() == 3) {
            for (int i = 0; i < min(3, (int)partialPassword.size()); i++) {
                if (rule[i] != -1 && partialPassword[i] != rule[i]) return false;
            }
        }
    }
    return true;
}

// ���ݷ��������з��ϵ�����
void backtrack(vector<int>& current, vector<vector<int>>& validPasswords, const vector<vector<int>>& rules, bool hasPrimeRule) {
    if (current.size() == 3) {
        validPasswords.push_back(current);
        return;
    }

    int start = 0, end = 9;
    if (hasPrimeRule) {//����
        start = 2;
        end = 7;
    }

    for (int digit = start; digit <= end; digit++) {
        if (hasPrimeRule && !isPrime(digit)) continue;
        current.push_back(digit);
        if (isValid(current, rules)) { // ��֦����鵱ǰ�����Ƿ����
            backtrack(current, validPasswords, rules, hasPrimeRule);
        }
        current.pop_back(); // ����
    }
}

vector<vector<int>> lock(string& input, int& userPassword) {
    PasswordLock lock;

    vector<vector<int>> rules = parseInput(input);
    bool hasPrimeRule = false;

    for (const auto& rule : rules) {
        if (rule.size() == 2 && rule[0] == -1 && rule[1] == -1) {
            hasPrimeRule = true;
            break;
        }
    }

    vector<vector<int>> validPasswords;
    vector<int> currentPassword;
    backtrack(currentPassword, validPasswords, rules, hasPrimeRule);
    // �û���������


    // ��������
    string passwordHash = lock.hashPassword(to_string(userPassword));
    cout << "�����Ѽ��ܣ���ϣֵ: " << passwordHash << endl;


    // ��֤����
    cout << "��ʼ��֤������Ч���룺" << endl;
    validCount = 0;
    for (const auto& pwd : validPasswords) {
        string passwordStr;
        for (int digit : pwd) {// ��vector<int>ת��Ϊstring
            passwordStr += to_string(digit);
        }

        cout << "��������: " << passwordStr << " - ";
        if (lock.verifyPassword(passwordStr, passwordHash)) {
            cout << "��֤�ɹ���" << endl;
            break;
        }
        else {
            cout << "��֤ʧ�ܣ�" << endl;
            validCount++;
        }
    }
    return validPasswords;
}

vector<vector<int>> lock(string& input, string& userPassword) {
    PasswordLock lock;

    vector<vector<int>> rules = parseInput(input);
    bool hasPrimeRule = false;

    for (const auto& rule : rules) {
        if (rule.size() == 2 && rule[0] == -1 && rule[1] == -1) {
            hasPrimeRule = true;
            break;
        }
    }

    vector<vector<int>> validPasswords;
    vector<int> currentPassword;
    backtrack(currentPassword, validPasswords, rules, hasPrimeRule);
    // �û���������


    // ��������
    string passwordHash = userPassword;


    // ��֤����
    cout << "��ʼ��֤������Ч���룺" << endl;

    for (const auto& pwd : validPasswords) {
        string passwordStr;
        for (int digit : pwd) {// ��vector<int>ת��Ϊstring
            passwordStr += to_string(digit);
        }

        cout << "��������: " << passwordStr << " - ";
        if (lock.verifyPassword(passwordStr, passwordHash)) {
            cout << "��֤�ɹ���" << endl;
            break;
        }
        else {
            cout << "��֤ʧ�ܣ�" << endl;
            validCount++;
        }
    }
    return validPasswords;
}
