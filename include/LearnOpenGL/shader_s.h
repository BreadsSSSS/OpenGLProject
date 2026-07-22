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
			//打开文件
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			stringstream vShaderStream, fShaderStream;
			//读取文件的缓冲内容到数据流中
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			//关闭文本处理器
			vShaderFile.close();
			fShaderFile.close();
			//转数据流到string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		//2.编译着色器
		unsigned int vertex;
		unsigned int fragment;
		int success;
		char infoLog[512];

		vertex = glCreateShader(GL_VERTEX_SHADER);//向OpenGL申请一个着色器对象
		glShaderSource(vertex,1,&vShaderCode,NULL);//把源码附加到着色器对象上
		glCompileShader(vertex);//编译着色器对象
		glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);//打印编译错误，如果有发生
		if (!success) 
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		fragment = glCreateShader(GL_FRAGMENT_SHADER); //向OpenGL申请一个着色器对象
		glShaderSource(fragment, 1, &fShaderCode, NULL);//把源码附加到着色器对象上
		glCompileShader(fragment);//编译着色器对象
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);//打印编译错误，如果有发生
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		ID = glCreateProgram();//创建着色器程序
		glAttachShader(ID, vertex);//附加着色器对象
		glAttachShader(ID, fragment);//附加着色器对象
		glLinkProgram(ID);//连接着色器对象
		// 打印连接错误（如果有的话）
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		//删除着色器，它们已经链接到我们的程序中了，已经不再需要了
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	//使用/激活程序
	void use()
	{
		glUseProgram(ID);
	}
	//uniform工具函数
	void setBool(const std::string& name, bool value) const 
	{
		glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
	}
	void setInt(const std::string& name, int value) const 
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setFloat(const std::string& name, float value) const 
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
};
#endif