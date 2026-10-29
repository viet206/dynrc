# Dynrc
Là từ viết tắt của "Dynamic Runtime C" . Thư viện này được viết như 1 phần mở rộng của C , hỗ trợ lập trình 1 cách an toàn , linh hoạt , và ngăn chặn phần lớn các lỗi xảy ra trong thời gian chạy .
# cài đặt
- Yêu cầu:
    - 1 môi trường Linux ( hiện tain chỉ hỗ trợ biên dịch trên Linux )
    - 1 trình biên dịch C ( không cần libc kèm theo )
bạn có thể cài đặt thông qua script trung gian `mak`
```sh
sh mak build
```
# Hướng dẫn
Bạn có thể tìm thấy các hướng dẫn trong thư mục `man/` của dự án

## Code mẫu
```c
#include "dynrc.h"
#include <stdio.h>

int main() {
    buf_static_init(buf0,32);

    dyn* d = dyn_new(buf0),"Hello World",STR_LIT);

    puts(d->s);
}
```
# Giấy phép
Dự án được cấp phép theo giấy phép MIT . Xem LICENSE để biết thêm chi tiết
