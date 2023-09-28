#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
//Константи
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
int main()
{
	// glfw: ініціалізація та конфігурування
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfw: створення вікна
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGLдля тесту", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Не вдалося створити вікно GLFW" << std::endl;
			glfwTerminate();
			return -1;
		}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// glad: завантаження всіх покажчиків на OpenGL-функції
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Не вдалося ініціалізувати GLAD" << std::endl;
		return -1;
	}
	// Цикл візуалізації
	while (!glfwWindowShouldClose(window))
	{
		// Обробка введення
		processInput(window);
		// Виконання рендерингу
		glClearColor(0.76f, 1.0f, 0.407f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// glfw: обмін вмістом front-і back-буферів. Відстеження подій введення/виводу (чи
		//була натиснута / відпущена кнопка, переміщений курсор миші тощо)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: завершення, звільнення всіх раніше задіяних GLFW-ресурсів
	glfwTerminate();
	return 0;
}
// Обробка всіх подій введення: запит GLFW про натискання/відпускання клавіш на
//клавіатурі в даному кадрі та відповідна обробка даних подій
void processInput(GLFWwindow* window)
{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
}
// glfw: щоразу, коли змінюються розміри вікна (користувачем або операційною
//системою), викликається дана callback - функція
void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// Переконуємось, що вікно перегляду відповідає новим розмірам вікна.
	// Зверніть увагу, висота вікна на Retina-дисплеях буде значно більшою, ніж
	//зазначено в програмі
		glViewport(0, 0, width, height);
}
