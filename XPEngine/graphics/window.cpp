#include "window.h"
namespace XPEngine {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		Window::Window(const char *title, int width, int height)
		{
			_title = title;
			_width = width;
			_height = height;

			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate(); //Terminate
		}

		bool Window::init()
		{
			if (!glfwInit()) {
				std::cout << "Initiliazing Error" << std::endl;
				return false;
			}

			_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

			if (!_window)
			{
				std::cout << "Failed to create window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(_window);
			glfwSetWindowSizeCallback(_window, windowResize);
			return true;
		}

		void Window::clear() const 
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{			
			glfwPollEvents();
			glfwSetKeyCallback(_window, keyCallback);
			glfwSwapBuffers(_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(_window) == 1;
		}

		void windowResize(GLFWwindow *window, int width, int height) 
		{
			glViewport(0, 0, width, height);
		}

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			std::cout << "INPUT" << std::endl;
		}
	}
}