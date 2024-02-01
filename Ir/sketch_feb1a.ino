/*
  【Arduino】168种传感器模块系列实验（资料代码+仿真编程+图形编程）
  程序二：模块接到A0模拟口，串口波形，可以测量距离
*/

int tcrt;

void setup() {
  pinMode(A0, INPUT);  // 模块连接引脚A0，并设置为输入模式
  pinMode(13, OUTPUT);
  Serial.begin(9600); // 设置串口波特率为9600
}

void loop(){
  tcrt = analogRead(A0);//读取寻迹传感器输出的值
  analogWrite(13, tcrt / 4);
  
  Serial.println(tcrt);
  delay(500);// 延时500毫秒
}
