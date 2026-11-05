# Kiến trúc dynrc
Kiến trúc dynrc được chia làm 3 module là core , module HAL , và module compat .
```
	+---------------+	 +------------+	   +-------------+
	|			    |	 |			  |    |			 |
	| Module compat |--->| Module HAL |--->| Module core |
	|			    |	 |			  |	   |			 |
	+---------------+	 +------------+	   +-------------+
		
```
## Module core
Là module cung cấp cho C các tính năng hiện đại như Dynamic Type , kiểm tra lỗi trong runtime và có độ tin cậy cao.
## Module HAL
chủ yếu là lớp tương thích giữa các nền tảng Windows , Linux , vân vân . cung cấp các hàm I/O , Signal OS
## Module Compat
Đây là module được thiết kế để tương thích với C , sở hữu tốc độ cao , và là nền móng cho xử lý trong module core
