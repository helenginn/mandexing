// Mandexing: a manual indexing program for crystallographic data.
// Copyright (C) 2017-2018 Helen Ginn
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// 
// Please email: vagabond @ hginn.co.uk for more details.

#ifndef __FileReader__
#define __FileReader__

#include <iostream>
#include <string>
#include <vector>
#include <cerrno>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

std::string get_file_contents(std::string filename);

std::vector<std::string> split(const std::string &s, char delim);
bool file_exists(const std::string& name);

std::string getFilename(std::string filename);
std::string getBaseFilename(std::string filename);

std::string i_to_str(int val);
std::string f_to_str(double val, int precision);

/* Random string things */

void trim(std::string& str);
void to_lower(std::string &str);
void to_upper(std::string &str);

class FileReader
{

public:

	inline static void setOutputDirectory(std::string _dir)
	{
		outputDir = _dir;

		DIR *dir = opendir(outputDir.c_str());

		if (dir)
		{
			closedir(dir);
		}
		else if (ENOENT == errno)
		{
			mkdir(outputDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		}

	}

	inline static std::string addOutputDirectory(std::string filename)
	{
		if (!outputDir.length())
		{
			return filename;
		}

		std::string fullPath = "./" + outputDir + "/" + filename;
		return fullPath;
	}

private:
	static std::string outputDir;

};

#endif /* defined(__GameDriver__FileReader__) */
