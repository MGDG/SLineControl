//len:S曲线的长度，即采样点个数
//FStart：曲线的起始值
//FStop：曲线的结束值
//flexible：曲线的拉伸变换，越大代表压缩的最厉害，中间（x坐标0点周围）加速度越大；越小越接近匀加速。理想的S曲线 flexible的取值为4-6。
//index：曲线索引点，区间[0,len]
//Fcurrent：索引点对应的曲线幅值
//
//当FStart<FStop时，曲线为上升曲线，反之为下降曲线，相等时为平行直线

float motorPower_PowerSLine(float len, float FStart, float FStop, float flexible,uint8_t index)
{
	float deno ; 
	float melo ; 
	float num; 
	float Fcurrent;

	if(index > len)  index = len;
	num = len/2;    
	melo = flexible * (index-num) / num;    
	deno = 1.0 / (1 + expf(-melo));  
	Fcurrent = FStart - (FStart-FStop) * deno;

	return Fcurrent;
}
