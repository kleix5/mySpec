#include <fstream>

void generate_sample_files() 
{
    std::ofstream f1("data_1.txt");
    f1 << "Hello world! Hello C++!";
    f1.close();
    
    std::ofstream f2("data_2.txt");
    f2 << "Test text. Another test.";
    f2.close();
}


int main()
{

    generate_sample_files();



    return 0;
}
