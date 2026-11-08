cmake_minimum_required(VERSION 3.12)
project(dynrc C)

# Thiết lập chuẩn C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Khai báo các tệp nguồn (.c)
set(SOURCES
    src/compat/compat.c
    src/core/core.c
    src/hal/hal_libc.c
)

# 2. Khai báo các tệp tiêu đề (.h)
set(HEADERS
    src/compat/compat.h
    src/core/core.h
    src/dynrc.h
    src/hal/hal.h
)

# 3. Tạo thư viện động
add_library(dynrc SHARED ${SOURCES} ${HEADERS})

# 4. Định nghĩa các đường dẫn include
target_include_directories(dynrc PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/compat>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/core>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/hal>
    $<INSTALL_INTERFACE:include>
)

# ==========================================
# 5. CẤU HÌNH CÀI ĐẶT (INSTALL) VÀO HỆ THỐNG
# ==========================================

# Cài đặt file thư viện (.so, .dll, .dylib)
install(TARGETS dynrc
    EXPORT dynrcTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# Cài đặt các file header (đảm bảo giữ nguyên cấu trúc thư mục hoặc gom về một chỗ)
install(FILES 
    src/dynrc.h
    src/compat/compat.h
    src/core/core.h
    src/hal/hal.h
    DESTINATION include/dynrc
)
