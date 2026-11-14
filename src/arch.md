# Thiết kế của ubox
là 1 bộ Utils nhỏ gọn , tiện lợi cho việc code C trên những môi trường không hỗ trợ đầy đủ libc:
- tiện lợi ( không cần cấu hình Build rườm rà , phức tạp )
- dễ dùng
    + API đặt tên theo `[noun]_[verb]`
    + Quy ước tham số : dst , src , option
    + Hệ thống lỗi : 0 , 1 , hoặc địa chỉ
    + được thiết kế để thuần thủ tục , không ràng buộc Pipeline
- không cần cấu trúc phức tạp 
## Quy ước cấu trúc mã nguồn
Chỉ áp dụng đối với các tệp mã nguồn trong thư mục `src/` . Thống nhất:
```
	src/
	+-> string.c 	-- xử lý chuỗi cho ubox
	+-> memory.c 	-- xử lý các thao tác bộ nhớ cho ubox
	+-> ubox.h 		-- định nghĩa các kiểu dữ liệu , header duy nhất của ubox
```
