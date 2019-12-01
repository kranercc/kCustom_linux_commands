//THIS IS USED TO CREATE A BIN AND A SRC FOLDER WITH AN AUTO-GENERATED RUN.SH FILE FOR EASE OF COMPILE
#include <iostream>
#include <unistd.h>

#include <sys/stat.h> 

#include "helper_functions.hpp"


int main(int argc, char const *argv[])
{
    std::string folderName = get_current_dir_name();

    std::vector<std::string> names = split(folderName, '/');
    
    folderName = names[names.size() - 1];

    std::string compile_command = "g++ ./src/*.cpp -o ./bin/" + folderName + " && ./bin/" + folderName;

    writeToFile("run.sh", compile_command.c_str());
    system("chmod +x run.sh");    
 

    mkdir("./bin", 0777);    
    mkdir("./src", 0777);    

    const char* initMain = "#include <iostream>\
                            \n\nint main()\
                            \n{\
                            \n\tstd::cout << \"inited by krane\";\
                            \n\treturn 0;\
                            \n}";

    writeToFile("./src/main.cpp", initMain);

    std::cout << "Completed.\n";

    return 0;
}
