#include <iostream>
#include <string>

using namespace std;

bool IsKPeriodic(const string& txt, unsigned int k) {

    size_t size = txt.size();
    if (k <= 0 || k > size || size % k || txt == "") {
        return false;
    }
    else if (k == size) {
        return true;
    }

    string pat;//� ��������� �������� � ���������� ������ � ���������
    for (unsigned int ik = 0; ik < k; ++ik) {
        pat += txt[ik];
    }

    //��������� �� ������� txt, ������� � �-��� �������� � �������� ���������
    unsigned int i = k, j, indIJ;
    while (i < size) {
        j = 0;
        while (j < k) {
            indIJ = i + j;
            if (txt[indIJ] == pat[j]) {
                ++j;
            }
            else {
                return false;
            }
        }
        i += k;
    }
    return true;
}

int main()
{
    string text1 = "abcabcabcabcabcabc";
    cout << "(" << text1 << ") K = 3 => " << IsKPeriodic(text1, 3) << endl;
    cout << "(" << text1 << ") K = 6 => " << IsKPeriodic(text1, 6) << endl;
    cout << "(" << text1 << ") K = 9 => " << IsKPeriodic(text1, 5) << endl;
    string text2 = "aaabaaabaaabaaab";
    cout << "(" << text2 << ") K = 4 => " << IsKPeriodic(text2, 4) << endl;
    cout << "(" << text2 << ") K = 3 => " << IsKPeriodic(text2, 3) << endl;
    string text3 = "adabadabadabadab";
    cout << "(" << text3 << ") K = 4 => " << IsKPeriodic(text3, 4) << endl;
    cout << "(" << text3 << ") K = 2 => " << IsKPeriodic(text3, 2) << endl;
    string text4 = "++/==/ ++/==/ ";
    cout << "(" << text4 << ") K = 7 => " << IsKPeriodic(text4, 7) << endl;
    string text5 = "1.2, 1.2, 1.2, 1.2, ";
    cout << "(" << text5 << ") K = 5 => " << IsKPeriodic(text5, 5) << endl;
    string text6 = "ZZZZZZZZ";
    cout << "(" << text6 << ") K = -1 => " << IsKPeriodic(text6, -1) << endl;
    cout << "(" << text6 << ") K = 0 => " << IsKPeriodic(text6, 0) << endl;
    cout << "(" << text6 << ") K = 1 => " << IsKPeriodic(text6, 1) << endl;
    cout << "(" << text6 << ") K = 2 => " << IsKPeriodic(text6, 2) << endl;
    cout << "(" << text6 << ") K = 4 => " << IsKPeriodic(text6, 4) << endl;
    cout << "(" << text6 << ") K = 6 => " << IsKPeriodic(text6, 6) << endl;
    cout << "(" << text6 << ") K = 8 => " << IsKPeriodic(text6, 8) << endl;
    cout << "(" << text6 << ") K = 10 => " << IsKPeriodic(text6, 10) << endl;
            
    while (true) {

        string text;
        cout << "\nVvedite text: ";      
        getline(cin, text);

        int K;
        cout << "Vvedite K (K > 0): ";
        cin >> K;
        if (cin.fail()) {                 // ���� �������� ���������� �� ���������
            cin.clear();                  // �� ���������� ��� ������� ����� ��������� 
            cin.ignore(32767, '\n');      // ������� ����� �� ������ 
            cout << "Oshibka. K - chiclo.\n";                  // ������ ������������ ������ ��������� ��� ��� 
            continue;
        }

        cin.ignore(32767, '\n');          // ������� ���� �����, ������� ������� � ������ ����� ����������
        if (std::cin.gcount() > 1) {      // ���� �� �������� ����� ������ ������� 
            cout << "Nekorrektniy vvod\n";
            continue;                     // �� ���� ���� ��������� ������������, � �� ������
        }                                 // ������������ ������ ��������� ��� ���

        if (K <= 0) {                     // ����������, ��� K �������� ������������� ������ 
            cout << "Nekorrektniy vvod (K > 0).\n";
            continue;
        }

        cout << "(" << text << ") K = " << K << " => " << IsKPeriodic(text, K) << endl;

        cout << "Povtorit - lyuboy simvol, \nVihod - 0.\n";
        char out;
        cin >> out;
        if (out == '0')
            return 0;

        cin.ignore(32767, '\n');
    }   

    return 0;
}