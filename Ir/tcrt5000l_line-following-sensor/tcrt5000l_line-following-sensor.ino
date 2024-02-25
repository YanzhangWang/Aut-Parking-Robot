// 定义连接到TRCT500的引脚（根据实际情况修改）
const int trct500Pin = A0; // 假设TRCT500连接到模拟输入A0

void setup() {
  // 初始化串口通信
  Serial.begin(9600);
  // 初始化TRCT500模块的引脚（如果需要的话）
  pinMode(trct500Pin, INPUT);
}

void loop() {
  // 读取来自TRCT500的数据
  int data = analogRead(trct500Pin);

  // 打印数据到串口监视器
  Serial.print("读取到的数据: ");
  Serial.println(data);

  // 稍作延迟，以便观察
  delay(1000);
}
