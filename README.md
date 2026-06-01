# Add2NumCpp

Project thực hiện bài intern challenge: cộng hai số nguyên không âm rất lớn được biểu diễn bằng chuỗi, theo cách cộng từng chữ số từ phải sang trái giống học sinh Tiểu học.

## Thông tin nộp bài

- Tên repository: `Add2NumCpp`
- URL trên GitHub: `https://github.com/iAmHuyyy/Add2NumCpp`
- Phiên bản đánh giá: branch `0.0.1`
- Có thể tạo thêm tag `0.0.1` để người đánh giá dễ checkout đúng phiên bản.

## Yêu cầu môi trường

- C++17
- CMake >= 3.10
- Trình biên dịch C++: GCC, Clang hoặc MSVC

## Cấu trúc thư mục

```text
Add2NumCpp/
├── CMakeLists.txt
├── README.md
├── include/
│   └── MyBigNumber.h
├── src/
│   ├── MyBigNumber.cpp
│   └── main.cpp
└── tests/
    └── test_my_big_number.cpp
```

## Chức năng chính

Lớp core nằm trong `include/MyBigNumber.h` và `src/MyBigNumber.cpp`.

```cpp
class MyBigNumber {
public:
    std::string sum(const std::string& stn1, const std::string& stn2);
};
```

Hàm `sum` nhận hai số nguyên không âm dạng chuỗi và trả về kết quả cộng cũng ở dạng chuỗi.

Giả định theo đề bài: input chỉ chứa ký số hợp lệ, chưa cần xử lý lỗi dữ liệu.

## Build project

### Linux / macOS

```bash
cmake -S . -B build
cmake --build build
```

### Windows PowerShell

```powershell
cmake -S . -B build
cmake --build build --config Release
```

## Chạy chương trình demo

### Linux / macOS

```bash
./build/add2num
```

### Windows PowerShell

Nếu dùng generator mặc định của Visual Studio:

```powershell
.\build\Release\add2num.exe
```

Nếu dùng MinGW Makefiles hoặc Ninja:

```powershell
.\build\add2num.exe
```

## Chạy unit test

### Linux / macOS

```bash
ctest --test-dir build --output-on-failure
```

hoặc:

```bash
./build/test_my_big_number
```

### Windows PowerShell

Nếu dùng Visual Studio:

```powershell
ctest --test-dir build -C Release --output-on-failure
```

hoặc:

```powershell
.\build\Release\test_my_big_number.exe
```

## Ví dụ kết quả demo

Với input:

```text
stn1 = 1234
stn2 = 897
```

Kết quả:

```text
Result: 1234 + 897 = 2131
```

Trong quá trình cộng, chương trình có ghi log từng bước, ví dụ lấy từng chữ số từ phải sang trái, cộng với số nhớ, ghi chữ số kết quả và cập nhật số nhớ.

## Kiểm tra lại như người đánh giá

### Windows

```powershell
mkdir D:\Projects\github.com\iAmHuyyy
cd D:\Projects\github.com\iAmHuyyy
git clone -b 0.0.1 https://github.com/iAmHuyyy/Add2NumCpp.git
cd Add2NumCpp
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

### Linux / macOS

```bash
mkdir -p ~/Projects/github.com/iAmHuyyy
cd ~/Projects/github.com/iAmHuyyy
git clone -b 0.0.1 https://github.com/iAmHuyyy/Add2NumCpp.git
cd Add2NumCpp
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```
