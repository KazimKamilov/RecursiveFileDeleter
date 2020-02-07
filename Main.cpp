/**
	Copyright (c) 2020 Kazim Kamilov

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.
	
	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.
	
	3. This notice may not be removed or altered from any source distribution. 
*/

#include <string>
#include <iostream>
#include <filesystem>


static std::string ext, answer;

void enter_ext()
{
	ext.clear();
	
	std::cout << "Enter a substring to search for.\nMake sure you entered the correct substring." << std::endl;
	std::cout << ">> ";
	
	std::cin >> ext;
}


void enter_answer()
{
	answer.clear();
	
	std::cout << "Are you sure you want to delete files with a substring \"" << ext << "\"?\nEnter \"yes\" to proceed(it completely remove files!) or \"no\" to exit from operation." << std::endl;
	std::cout << ">> ";
	
	std::cin >> answer;
}


void process()
{
	if(answer == "yes")
	{
		std::cout << "Starting..." << std::endl;

		for (auto& it : std::filesystem::recursive_directory_iterator("./"))
		{
			if(it.path().string().find(ext) != std::string::npos)
			{
				std::cout << "Deleting " << it.path() << "..." << std::endl;	
				std::filesystem::remove(it.path());
				std::cout << "Done!\n" << std::endl;
			}
		}
		
		std::cout << "All files with \"" << ext << "\" deleted! Press ENTER..." << std::endl;
	}
	else if(answer == "no")
	{
		std::cout << "Okay... Try again...\n" << std::endl;
		enter_ext();
		enter_answer();
		process();
	}
	else
	{
		std::cout << "Unknown answer. Can be \"yes\" or \"no\" only. Try again...\n" << std::endl;
		enter_ext();
		enter_answer();
		process();
	}
}


int main()
{
	std::cout << "============================================================" << std::endl;
	std::cout << "|                                                           |" << std::endl;
	std::cout << "|               Recursive file deleter v1.0.                |" << std::endl;
	std::cout << "|                Delete files by substring.                 |" << std::endl;
	std::cout << "|  Enter the correct substring to delete the desired files. |" << std::endl;
	std::cout << "|                Kazim Kamilov, 07.02.2020                  |" << std::endl;
	std::cout << "|                                                           |" << std::endl;
	std::cout << "============================================================" << std::endl;
	
	enter_ext();
	enter_answer();
	process();
	
	ext.clear();
	answer.clear();
	std::system("pause");
	
	return 0;
}