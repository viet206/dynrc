# Giới thiệu về hướng dẫn uBox ( bản dịch tiếng Việt )
uBox là một chuỗi tiện ích ( utils ) dành cho các lập trình viên C , nhằm bù đắp những điểm yếu của libc và là 1 phần mở rộng của nó . Về mặt tổng quan thì chúng ta sẽ phân tích cả libc và uBox để hiểu được giá trị và vai trò của chúng:
ưu điểm libc:
```
- Wrapper trung gian , bọc các thao tác của OS ( như đọc / ghi tệp , ... ) lại với nhau thống nhất tạo thành 1 giao diện duy nhất
- Hầu hết các OS đều có hỗ trợ libc . từ Windows , Linux , ... cho đến tận FreeRTOS ( có newlib chẳng hạn )
```
nhược điểm libc:
```
- bị phụ thuộc vào OS : tuy OS nào cũng có libc , nhưng hành vi của chúng lại hoàn toàn khác nhau . Windows thì có hành vi riêng ; Các hệ điều hành POSIX thì cũng có hành vi riêng ; rồi newlib cũng có hành vi riêng do ràng buộc tài nguyên trên các vi điều khiển
- Không phải lúc nào cũng an toàn : trong libc vẫn có rất nhiều những hàm thiếu an toàn , hoặc hành vi không đồng nhất . ví dụ điển hình nhất là `gets()` , `strcpy()` , `signal()` ( do hành vi không đồng nhất )
```
Và có thể là nhiều cái khác nữa . vì vậy , uBox sinh ra để giải quyết 2 vấn đề nhức nhối nhất của libc là "đồng nhất thiết kế" , "cung cấp các tiện ích an toàn" .
## Mục Lục
[memory.md](Memory)
[string.md](String)
