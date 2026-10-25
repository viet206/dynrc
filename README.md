# Dynrc
Là từ viết tắt của "Dynamic Runtime C" . Thư viện này được viết như 1 phần mở rộng của C , hỗ trợ lập trình 1 cách an toàn , linh hoạt , và ngăn chặn phần lớn các lỗi xảy ra trong thời gian chạy .
# cài đặt
- Yêu cầu:
    - 1 trình thông dịch Lua
    - 1 trình biên dịch C ( không cần libc kèm theo )
bạn có thể cài đặt thông qua script trung gian `mak.lua`
```lua
lua mak.lua
```
Để biên dịch ra thư viện:
```lua
lua mak.lua -b
```
# Hướng dẫn
⚠️  Lưu ý : Chưa có tài liệu . bạn có thể đóng góp cho dự án
Code mẫu :
```c
#include "dynrc.h"

int main() {
    new_static_buf(my,32);

    dyn_t* d = dyn_str(my,"Hello World",20);

    puts(d->s.p);
}
```
# Giấy phép
Dự án được cấp phép theo giấy phép MIT . Xem LICENSE để biết thêm chi tiết
