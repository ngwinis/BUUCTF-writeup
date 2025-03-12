# reverse1

### **Solve:**

- Load file PE vào IDA và thực hiện tạo mã giả, thấy yêu cầu từ chương trình: Input flag đúng và in ra màn hình `this is the right flag!`
![alt text](../../../images/reverse1-1.png)

- Flag là chuỗi `Str2` được mã hoá theo cách: Nếu ký tự thứ i là ký tự 'o' thì sửa thành ký tự số '0'. Chuỗi `Str2` là '{hello_world}'. Ta chỉ cần sửa 'o' thành ký tự số '0' thì sẽ có được flag
![alt text](../../../images/reverse1-2.png)

> **flag:** flag{hell0_w0rld}