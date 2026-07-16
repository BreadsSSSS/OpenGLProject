#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb_image.h>
#include <iostream>


using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) //自定义的窗口大小回调函数
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) //自定义的输入处理函数
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//检测按键
	{
		glfwSetWindowShouldClose(window, true);//关闭窗口
	}
}


int main() {
	/*glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL , NULL);
	if (!window) {
		std::cout << "窗口创建失败" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD初始化失败" << std::endl;
		return -1;
	}

	// 测试GLM
	glm::vec3 pos(1.0f, 2.0f, 3.0f);
	std::cout << "GLM正常：" << pos.x << std::endl;

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;*/

	/*-----------------------------------------------------------------------------------------------------------*/
	glfwInit();//初始化GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//定义使用OpenGL版本为3.3 主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//定义使用OpenGL版本为3.3 次版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//定义使用核心模式
	/*-----------------------------------------------------------------------------------------------------------*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);//用glfw（图形库）创建一个窗口对象
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();//终止GLFW
		return -1;
	}
	glfwMakeContextCurrent(window);//将窗口的上下文设置为当前线程的主上下文
	/*-----------------------------------------------------------------------------------------------------------*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //初始化GLAD，用于管理OpenGL的函数指针，用GLAD加载系统相关的OpenGL函数地址
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	/*-----------------------------------------------------------------------------------------------------------*/
	glViewport(0, 0, 800, 600);//设置视口大小
	//framebuffer_size_callback(window, 800, 600);//设置窗口大小回调函数
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册窗口大小回调函数

	while (!glfwWindowShouldClose(window))//循环渲染
	{
		processInput(window);//处理输入

		glfwSwapBuffers(window);//缓冲区交换，在渲染循环中，先绘制到后台缓冲区，然后交换到前台显示
		glfwPollEvents();//检查有没有触发什么事件（键盘输入、鼠标移动等）

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清空屏幕所用的颜色，这是一个状态设置函数，设置了之后，后续的glClear函数都会使用这个颜色来清空屏幕
		glClear(GL_COLOR_BUFFER_BIT);//清空屏幕的颜色缓冲区，使用glClearColor设置的颜色来清空
	}

	/*在学习此节之前，建议将这三个单词先记下来：

	顶点数组对象：Vertex Array Object，VAO
	顶点缓冲对象：Vertex Buffer Object，VBO
	元素缓冲对象：Element Buffer Object，EBO 或 索引缓冲对象 Index Buffer Object，IBO*/

	float vertices[] = {
		-0.5f,-0.5f,0.0f,//左下角
		0.5f,-0.5f,0.0f,//右下角
		0.0f,0.5f,0.0f//上顶点
	};

	unsigned int VBO;//顶点缓冲对象
	glGenBuffers(1, &VBO);//生成一个顶点缓冲对象
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定顶点缓冲对象,gl_array_buffer是顶点缓冲对象的缓冲类型，VBO是顶点缓冲对象的ID
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//把顶点数据复制到缓冲的内存中，GL_STATIC_DRAW是一个使用模式，表示数据不会或几乎不会改变

	const char* vertexShaderSource = "#version 330 core\n"//将顶点着色器源码写入字符串
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	unsigned int vertexShader;//顶点着色器对象
	vertexShader = glCreateShader(GL_VERTEX_SHADER);//创建一个顶点着色器对象



	glfwTerminate();//终止GLFW
	return 0;
}