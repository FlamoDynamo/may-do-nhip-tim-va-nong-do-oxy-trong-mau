#ifndef SensorData_h
#define SensorData_h

#include <Arduino.h>
#include <queue>

class SensorData {
public:
    SensorData(int redPin, int irPin, int bufferSize = 100); // Constructor
    void update(); // Cập nhật dữ liệu từ cảm biến
    int getHeartRate(); // Trả về nhịp tim
    int getSpO2(); // Trả về SpO2
    void calibrate(); // Hiệu chỉnh cảm biến (nếu cần)

private:
    int redPin, irPin;
    int bufferSize; // Kích thước bộ đệm
    std::queue<int> redBuffer, irBuffer; // Hàng đợi cho dữ liệu RED và IR
    std::queue<int> hrBuffer, spo2Buffer; // Hàng đợi cho nhịp tim và SpO2

    int readRedValue(); // Đọc giá trị RED từ cảm biến
    int readIrValue(); // Đọc giá trị IR từ cảm biến
    void filterData(); // Lọc nhiễu dữ liệu
    void calculateHeartRate(); // Tính toán nhịp tim
    void calculateSpO2(); // Tính toán SpO2
    void findPeaks(); // Tìm các đỉnh trong tín hiệu
};

#endif
