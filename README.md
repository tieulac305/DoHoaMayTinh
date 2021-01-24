# Đồ họa máy tính

Đồ họa máy tính cơ bản sử dụng graphics.h đã lỗi thời, các bạn có thể tìm hiểu các thư viện khác để code đồ họa cho C++ ví dụ như OpenGL ... (khá là nhiều tùy mục đích sẽ có nhiều lựa chọn khác nhau)\
\
_Liên hệ: m.me/tieulac305_

**Chú ý: graphics.h không hoạt động với codeblock từ 20.03 trở đi**

## Cách cài graphics.h

B1: Tải các file cần thiết: http://winbgim.codecutter.org/V6_0/WinBGIm_Library6_0_Nov2005.zip  
B2: Đối với devC và CodeBlocks:\
    Copy 2 mục .h vào mục include, với CodeBlocks là MinGW/include\
    Copy file libbgi.a vào mục lib, với CodeBlocks là MinGW/lib\
    \
    - Với DevC:
    Gõ Alt-P và paste những mục sau vào Linker:\
    ```
    -lbgi
    -lgdi32
    -lcomdlg32
    -luuid
    -loleaut32
    -lole32
    ```
    \
    - Với CodeBlocks: Mở cài đặt như sau:\
    \
    `Settings > Compiler > Linker Settings`\
    \
    Tại tab `Link Libraries`: Chọn `Add` sau đó tìm đến đường dẫn chứa `libbgi.a` để thêm vào.\
    \
    Tại tab `Other linker options`: Paste những mục sau:\
    ```-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32```
    Đối với các IDE khác xem hướng dẫn tại: www.cs.colorado.edu/~main/bgi.

B3: Khi này, ta đã có thể include thư viện graphics.h tuy nhiên có thể thư viện sẽ phát sinh lỗi ở dòng 302 do có 2 biến right (nếu mình nhớ k nhầm), mở `graphics.h` ra và sửa dòng đó:
```int left=0, int top=0, int right=INT_MAX, int bottom=INT_MAX;```
Khi lưu lại, thư viện đã có thể sử dụng.

**Lưu ý: graphics.h chỉ hoạt động với file .cpp**

*Đừng chú ý: repo này kiểu code lại thư viện graphics nhưng lại là bản cùi hơn graphics và phải dùng thư viện graphics để code?*
