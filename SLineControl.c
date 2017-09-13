//S型曲线的方程 y = 1/(1+exp(-x));
//扩展：y = A + B(1+exp(-a*x+b));
//加速过程：Fcurrent = Fmin + (Fmax - Fmin)/(1+exp(-Flexible*(i-num)/num));
//减速过程：Fcurrent = Fmax - (Fmax - Fmin)/(1+exp(-Flexible*(i-num)/num));
//len：1000，整个变化区间的长度
//Fmin: 起始值，曲线的最低点
//Fmax：结束值，曲线的最高点
//index：循环计数索引，区间(0,len)
//num ：1000/2，可以使曲线对称
//-Flexible*(i-num)/num：是对S型曲线进行拉伸变化，其中flexible代表S曲线区间
//						（越大代表压缩的最厉害，中间（x坐标0点周围）加速度越
//						 大；越小越接近匀加速。理想的S曲线 flexible的取值为4-6），

// return 根据返回值 设定步进电机的换相速度 或者 设定pwm占空比

//S曲线加速
float SLineUP(float len, float Fmax, float Fmin, float flexible,int index)
{
	float deno ;
	float melo ;
	float num;
	float Fcurrent;

	num = len/2;										//num ：1000/2，可以使曲线对称
	melo = flexible * (index-num) / num;
	deno = 1.0 / (1 + expf(-melo));   //expf is a library function of exponential(e)
	Fcurrent = Fmin + (Fmax-Fmin) * deno;

	return Fcurrent;
}

 //S曲线减速
float SLineDOWN(float len, float Fmax, float Fmin, float flexible,int index)
{
	float deno ;
	float melo ;
	float num;
	float Fcurrent;

	num = len/2;										//num ：1000/2，可以使曲线对称
    melo = flexible * (index-num) / num;
    deno = 1.0 / (1 + expf(-melo));   //expf is a library function of exponential(e)
    Fcurrent = Fmax - (Fmax-Fmin) * deno;

	return Fcurrent;
}
