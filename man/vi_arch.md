# Kiến trúc dynrc

Kiến trúc dynrc được chia thành 3 mô-đun: core, HAL và compat.

```text
+---------------+     +------------+     +-------------+
| Module compat | --->| Module HAL | --->| Module core |
+---------------+     +------------+     +-------------+
```

## Module core

Đây là mô-đun cung cấp cho C các tính năng hiện đại như dynamic type, kiểm tra lỗi khi chạy (runtime) và độ tin cậy cao.

## Module HAL

Mô-đun này chủ yếu là lớp tương thích giữa các nền tảng Windows, Linux, v.v.; đồng thời cung cấp các hàm I/O và signal của hệ điều hành.

## Module compat

Đây là mô-đun được thiết kế để tương thích với C, có tốc độ cao và là nền móng cho xử lý trong mô-đun core.
