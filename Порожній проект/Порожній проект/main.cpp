#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
//���������
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
int main()
{
	// glfw: ����������� �� ��������������
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfw: ��������� ����
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL��� �����", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "�� ������� �������� ���� GLFW" << std::endl;
			glfwTerminate();
			return -1;
		}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// glad: ������������ ��� ��������� �� OpenGL-�������
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "�� ������� ������������ GLAD" << std::endl;
		return -1;
	}
	// ���� ����������
	while (!glfwWindowShouldClose(window))
	{
		// ������� ��������
		processInput(window);
		// ��������� ����������
		glClearColor(0.76f, 1.0f, 0.407f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// glfw: ���� ������ front-� back-������. ³��������� ���� ��������/������ (��
		//���� ��������� / �������� ������, ���������� ������ ���� ����)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: ����������, ��������� ��� ����� ������� GLFW-�������
	glfwTerminate();
	return 0;
}
// ������� ��� ���� ��������: ����� GLFW ��� ����������/���������� ����� ��
//�������� � ������ ���� �� �������� ������� ����� ����
void processInput(GLFWwindow* window)
{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
}
// glfw: ������, ���� ��������� ������ ���� (������������ ��� �����������
//��������), ����������� ���� callback - �������
void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// ������������, �� ���� ��������� ������� ����� ������� ����.
	// ������� �����, ������ ���� �� Retina-�������� ���� ������ ������, ��
	//��������� � �������
		glViewport(0, 0, width, height);
}
