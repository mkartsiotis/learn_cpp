#include <iostream>
using namespace std;
int main(void)
{
    string url = "PEOS huehf  PEOS";
    int has_gaps = url.find(' ');
    while (has_gaps != -1)
    {
        // If we want to avoid extra gaps we just need to skip them and shorten the string
        int cnt = 1;
        for (int i = has_gaps + 1; ((size_t)i < url.length() && url[i] == ' '); i++)
        {
            url.erase(i, 1);
            i--;
            cnt++;
        }
        string percent = "%" + to_string(cnt);
        url.replace(has_gaps, 1, percent);
        has_gaps = url.find(' ');
    }
    cout << url << endl;
}
