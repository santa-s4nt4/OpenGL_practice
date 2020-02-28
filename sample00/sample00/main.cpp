#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	// GLFW��������
	if (glfwInit() == GL_FALSE) {
		// �������Ɏ��s
		std::cerr << "Can't initialize GLFW." << std::endl;
		return 1;
	}

	// �v���O�����I�����̏�����o�^����
	atexit(glfwTerminate);

	// OpenGl Version 3.2 Core Profile��I��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window���쐬
	GLFWwindow *const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
	if (window == NULL) {
		// window���쐬�ł��Ȃ�����
		std::cerr << "Can't create GLFW window." << std::endl;
		glfwTerminate();
		return 1;
	}

	// �����window��OpenGL�̏����Ώۂɂ���
	glfwMakeContextCurrent(window);

	// GLEW������������
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		// GLEW�̏������Ɏ��s
		std::cerr << "Can't initialize GLEW" << std::endl;
		return 1;
	}

	// ���������̃^�C�~���O��҂�
	glfwSwapInterval(1);

	// �w�i�F���w��
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// window���J���Ă���ԌJ��Ԃ�
	while (glfwWindowShouldClose(window) == GL_FALSE) {
		// window������
		glClear(GL_COLOR_BUFFER_BIT);

		//
		// �����ŕ`�揈�����s��
		//

		// �J���[�o�b�t�@�����ւ���
		glfwSwapBuffers(window);

		// �C�x���g�����o��
		glfwWaitEvents();

		//glfwTerminate();
	}
}