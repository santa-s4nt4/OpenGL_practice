#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	// GLFWを初期化
	if (glfwInit() == GL_FALSE) {
		// 初期化に失敗
		std::cerr << "Can't initialize GLFW." << std::endl;
		return 1;
	}

	// プログラム終了時の処理を登録する
	atexit(glfwTerminate);

	// OpenGl Version 3.2 Core Profileを選択
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// windowを作成
	GLFWwindow *const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
	if (window == NULL) {
		// windowが作成できなかった
		std::cerr << "Can't create GLFW window." << std::endl;
		glfwTerminate();
		return 1;
	}

	// 作ったwindowをOpenGLの処理対象にする
	glfwMakeContextCurrent(window);

	// GLEWを初期化する
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		// GLEWの初期化に失敗
		std::cerr << "Can't initialize GLEW" << std::endl;
		return 1;
	}

	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	// 背景色を指定
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// windowが開いている間繰り返す
	while (glfwWindowShouldClose(window) == GL_FALSE) {
		// windowを消去
		glClear(GL_COLOR_BUFFER_BIT);

		//
		// ここで描画処理を行う
		//

		// カラーバッファを入れ替える
		glfwSwapBuffers(window);

		// イベントを取り出す
		glfwWaitEvents();

		//glfwTerminate();
	}
}