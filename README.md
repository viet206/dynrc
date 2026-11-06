# Dynrc

Dynrc là viết tắt của “Dynamic Runtime C”. Đây là thư viện mở rộng cho C, hướng đến việc hỗ trợ lập trình an toàn và linh hoạt.

## Cài đặt

Yêu cầu:

- Môi trường Linux (hiện tại chỉ hỗ trợ biên dịch trên Linux).
- Trình biên dịch C (không cần libc đi kèm).

Bạn có thể cài đặt thông qua script trung gian `mak`:

```sh
sh mak build
```

## Hướng dẫn

Bạn có thể tìm thấy các hướng dẫn trong thư mục [`man`](https://github.com/viet206/dynrc/tree/main/man) của dự án.

### Code mẫu

```c
#include "dynrc.h"
#include <stdio.h>

int main() {
    buf_static_init(buf0,32);

    dyn* d = dyn_new(buf0,"Hello World",STR_LIT);

    puts(d->s);
}
```

## Giấy phép

Dự án được cấp phép theo giấy phép MIT. Xem [LICENSE](LICENSE) để biết thêm chi tiết.
