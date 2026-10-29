# Giới thiệu
Hướng dẫn này dạy bạn cách sử dụng API của dynrc

## Các khởi tạo 1 kiểu dyn*
Để khởi tạo , ta cần tạo 1 buffer . `buf_init_static` là 1 macro của module core , khởi tạo 1 buffer có kiểu buf* với kích thước nhất định trên bộ nhớ Stack
```c
	// buf_init_static(name_buffer,size);
	buf_init_static(buf0,32);
```
Sau đó ta khởi tạo 1 Object dyn* với 3 kiểu hàm tạo hỗ trợ:
- STR_LIT : hằng chuỗi
- INT : số nguyên
- PTR : con trỏ void*
```c
	// dyn* dyn_new(buffer,data,tag);
	dyn* d = dyn_new(buf0,"Hello World",tag);
```
## Truy cập dyn*
Theo cấu trúc , các thành viên lưu trữ dữ liệu là :
```c
typedef struct {
	dtag tag;
	union {
		int i;
		char* s;
		void* p;
	};
}dyn;
```
nên ta có thể truy cập thành viên dựa trên tag được lưu trữ :
```c
puts(d->s);
```
