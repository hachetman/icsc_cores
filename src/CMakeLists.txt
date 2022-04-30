
add_executable(test_spi_controller test_spi_controller.cpp spi_controller.cpp)
svc_target(test_spi_controller ELAB_TOP tb.dut)

add_executable(test_rgb_matrix_ctrl test_rgb_matrix_ctrl.cpp rgb_matrix_ctrl.cpp)
svc_target(test_rgb_matrix_ctrl ELAB_TOP tb.dut)
