#ifndef SHDER_H
#define SHDER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class Shader
{
public:
	//程序ID
	unsigned int ID;

	//构造器读取并构建着色器
	Shader(const char* vertexPath, const char* fragmentPath);

	void use(); //使用/激活程序
	//uniform工具函数
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

	Shader(const char* vertexPath, const char* fragmentPath)
	{
		// 1. 从文件路径中获取顶点/片段着色器
		string vertexCode;
		string fragmentCode;
		ifstream vShaderFile;
		ifstream fShaderFile;
		// 确保ifstream对象可以抛出异常：
		vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{

		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		}

	}

};
#endif