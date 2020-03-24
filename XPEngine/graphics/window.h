#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

namespace XPEngine {
	namespace graphics {

		class Window {
		private: 
			const char *_title;
			int _width, _height;
			GLFWwindow *_window;
			bool _closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return _width; }
			inline int getHeight() const { return _height; }
		private:
			bool init();
		};

	}
}