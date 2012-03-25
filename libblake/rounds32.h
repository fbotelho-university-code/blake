register uint32_t a, b, c, d;
//ROUND :::::::::::: 0
//round : 0 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[0][0]], con[sigma[0][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][0+1]], con[sigma[0][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 0 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[0][2]], con[sigma[0][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][2+1]], con[sigma[0][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 0 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[0][4]], con[sigma[0][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][4+1]], con[sigma[0][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 0 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[0][6]], con[sigma[0][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][6+1]], con[sigma[0][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 0 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[0][8]], con[sigma[0][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][8+1]], con[sigma[0][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 0 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[0][10]], con[sigma[0][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][10+1]], con[sigma[0][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 0 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[0][12]], con[sigma[0][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][12+1]], con[sigma[0][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 0 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[0][14]], con[sigma[0][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[0][14+1]], con[sigma[0][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 1
//round : 1 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[1][0]], con[sigma[1][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][0+1]], con[sigma[1][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 1 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[1][2]], con[sigma[1][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][2+1]], con[sigma[1][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 1 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[1][4]], con[sigma[1][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][4+1]], con[sigma[1][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 1 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[1][6]], con[sigma[1][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][6+1]], con[sigma[1][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 1 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[1][8]], con[sigma[1][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][8+1]], con[sigma[1][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 1 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[1][10]], con[sigma[1][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][10+1]], con[sigma[1][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 1 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[1][12]], con[sigma[1][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][12+1]], con[sigma[1][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 1 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[1][14]], con[sigma[1][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[1][14+1]], con[sigma[1][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 2
//round : 2 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[2][0]], con[sigma[2][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][0+1]], con[sigma[2][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 2 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[2][2]], con[sigma[2][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][2+1]], con[sigma[2][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 2 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[2][4]], con[sigma[2][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][4+1]], con[sigma[2][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 2 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[2][6]], con[sigma[2][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][6+1]], con[sigma[2][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 2 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[2][8]], con[sigma[2][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][8+1]], con[sigma[2][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 2 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[2][10]], con[sigma[2][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][10+1]], con[sigma[2][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 2 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[2][12]], con[sigma[2][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][12+1]], con[sigma[2][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 2 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[2][14]], con[sigma[2][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[2][14+1]], con[sigma[2][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 3
//round : 3 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[3][0]], con[sigma[3][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][0+1]], con[sigma[3][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 3 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[3][2]], con[sigma[3][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][2+1]], con[sigma[3][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 3 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[3][4]], con[sigma[3][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][4+1]], con[sigma[3][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 3 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[3][6]], con[sigma[3][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][6+1]], con[sigma[3][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 3 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[3][8]], con[sigma[3][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][8+1]], con[sigma[3][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 3 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[3][10]], con[sigma[3][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][10+1]], con[sigma[3][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 3 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[3][12]], con[sigma[3][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][12+1]], con[sigma[3][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 3 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[3][14]], con[sigma[3][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[3][14+1]], con[sigma[3][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 4
//round : 4 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[4][0]], con[sigma[4][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][0+1]], con[sigma[4][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 4 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[4][2]], con[sigma[4][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][2+1]], con[sigma[4][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 4 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[4][4]], con[sigma[4][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][4+1]], con[sigma[4][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 4 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[4][6]], con[sigma[4][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][6+1]], con[sigma[4][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 4 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[4][8]], con[sigma[4][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][8+1]], con[sigma[4][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 4 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[4][10]], con[sigma[4][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][10+1]], con[sigma[4][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 4 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[4][12]], con[sigma[4][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][12+1]], con[sigma[4][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 4 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[4][14]], con[sigma[4][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[4][14+1]], con[sigma[4][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 5
//round : 5 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[5][0]], con[sigma[5][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][0+1]], con[sigma[5][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 5 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[5][2]], con[sigma[5][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][2+1]], con[sigma[5][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 5 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[5][4]], con[sigma[5][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][4+1]], con[sigma[5][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 5 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[5][6]], con[sigma[5][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][6+1]], con[sigma[5][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 5 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[5][8]], con[sigma[5][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][8+1]], con[sigma[5][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 5 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[5][10]], con[sigma[5][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][10+1]], con[sigma[5][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 5 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[5][12]], con[sigma[5][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][12+1]], con[sigma[5][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 5 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[5][14]], con[sigma[5][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[5][14+1]], con[sigma[5][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 6
//round : 6 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[6][0]], con[sigma[6][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][0+1]], con[sigma[6][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 6 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[6][2]], con[sigma[6][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][2+1]], con[sigma[6][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 6 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[6][4]], con[sigma[6][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][4+1]], con[sigma[6][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 6 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[6][6]], con[sigma[6][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][6+1]], con[sigma[6][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 6 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[6][8]], con[sigma[6][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][8+1]], con[sigma[6][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 6 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[6][10]], con[sigma[6][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][10+1]], con[sigma[6][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 6 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[6][12]], con[sigma[6][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][12+1]], con[sigma[6][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 6 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[6][14]], con[sigma[6][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[6][14+1]], con[sigma[6][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 7
//round : 7 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[7][0]], con[sigma[7][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][0+1]], con[sigma[7][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 7 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[7][2]], con[sigma[7][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][2+1]], con[sigma[7][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 7 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[7][4]], con[sigma[7][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][4+1]], con[sigma[7][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 7 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[7][6]], con[sigma[7][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][6+1]], con[sigma[7][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 7 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[7][8]], con[sigma[7][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][8+1]], con[sigma[7][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 7 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[7][10]], con[sigma[7][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][10+1]], con[sigma[7][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 7 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[7][12]], con[sigma[7][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][12+1]], con[sigma[7][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 7 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[7][14]], con[sigma[7][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[7][14+1]], con[sigma[7][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 8
//round : 8 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[8][0]], con[sigma[8][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][0+1]], con[sigma[8][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 8 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[8][2]], con[sigma[8][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][2+1]], con[sigma[8][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 8 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[8][4]], con[sigma[8][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][4+1]], con[sigma[8][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 8 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[8][6]], con[sigma[8][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][6+1]], con[sigma[8][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 8 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[8][8]], con[sigma[8][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][8+1]], con[sigma[8][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 8 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[8][10]], con[sigma[8][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][10+1]], con[sigma[8][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 8 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[8][12]], con[sigma[8][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][12+1]], con[sigma[8][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 8 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[8][14]], con[sigma[8][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[8][14+1]], con[sigma[8][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 9
//round : 9 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[9][0]], con[sigma[9][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][0+1]], con[sigma[9][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 9 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[9][2]], con[sigma[9][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][2+1]], con[sigma[9][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 9 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[9][4]], con[sigma[9][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][4+1]], con[sigma[9][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 9 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[9][6]], con[sigma[9][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][6+1]], con[sigma[9][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 9 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[9][8]], con[sigma[9][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][8+1]], con[sigma[9][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 9 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[9][10]], con[sigma[9][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][10+1]], con[sigma[9][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 9 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[9][12]], con[sigma[9][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][12+1]], con[sigma[9][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 9 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[9][14]], con[sigma[9][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[9][14+1]], con[sigma[9][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 10
//round : 10 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[10][0]], con[sigma[10][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][0+1]], con[sigma[10][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 10 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[10][2]], con[sigma[10][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][2+1]], con[sigma[10][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 10 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[10][4]], con[sigma[10][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][4+1]], con[sigma[10][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 10 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[10][6]], con[sigma[10][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][6+1]], con[sigma[10][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 10 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[10][8]], con[sigma[10][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][8+1]], con[sigma[10][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 10 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[10][10]], con[sigma[10][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][10+1]], con[sigma[10][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 10 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[10][12]], con[sigma[10][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][12+1]], con[sigma[10][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 10 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[10][14]], con[sigma[10][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[10][14+1]], con[sigma[10][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 11
//round : 11 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[11][0]], con[sigma[11][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][0+1]], con[sigma[11][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 11 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[11][2]], con[sigma[11][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][2+1]], con[sigma[11][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 11 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[11][4]], con[sigma[11][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][4+1]], con[sigma[11][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 11 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[11][6]], con[sigma[11][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][6+1]], con[sigma[11][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 11 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[11][8]], con[sigma[11][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][8+1]], con[sigma[11][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 11 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[11][10]], con[sigma[11][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][10+1]], con[sigma[11][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 11 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[11][12]], con[sigma[11][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][12+1]], con[sigma[11][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 11 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[11][14]], con[sigma[11][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[11][14+1]], con[sigma[11][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 12
//round : 12 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[12][0]], con[sigma[12][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][0+1]], con[sigma[12][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 12 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[12][2]], con[sigma[12][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][2+1]], con[sigma[12][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 12 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[12][4]], con[sigma[12][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][4+1]], con[sigma[12][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 12 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[12][6]], con[sigma[12][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][6+1]], con[sigma[12][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 12 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[12][8]], con[sigma[12][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][8+1]], con[sigma[12][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 12 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[12][10]], con[sigma[12][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][10+1]], con[sigma[12][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 12 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[12][12]], con[sigma[12][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][12+1]], con[sigma[12][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 12 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[12][14]], con[sigma[12][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[12][14+1]], con[sigma[12][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


//ROUND :::::::::::: 13
//round : 13 , i: 0
a = *v0;
b = *v4;
c = *v8;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[13][0]], con[sigma[13][0+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][0+1]], con[sigma[13][0]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v4 = b;
*v8 = c;
*v12 = d;


//round : 13 , i: 2
a = *v1;
b = *v5;
c = *v9;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[13][2]], con[sigma[13][2+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][2+1]], con[sigma[13][2]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v5 = b;
*v9 = c;
*v13 = d;


//round : 13 , i: 4
a = *v2;
b = *v6;
c = *v10;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[13][4]], con[sigma[13][4+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][4+1]], con[sigma[13][4]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v6 = b;
*v10 = c;
*v14 = d;


//round : 13 , i: 6
a = *v3;
b = *v7;
c = *v11;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[13][6]], con[sigma[13][6+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][6+1]], con[sigma[13][6]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v7 = b;
*v11 = c;
*v15 = d;


//round : 13 , i: 8
a = *v0;
b = *v5;
c = *v10;
d = *v15;
a = ADD32((a),(b))+XOR32(m[sigma[13][8]], con[sigma[13][8+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][8+1]], con[sigma[13][8]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v0 = a;
*v5 = b;
*v10 = c;
*v15 = d;


//round : 13 , i: 10
a = *v1;
b = *v6;
c = *v11;
d = *v12;
a = ADD32((a),(b))+XOR32(m[sigma[13][10]], con[sigma[13][10+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][10+1]], con[sigma[13][10]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v1 = a;
*v6 = b;
*v11 = c;
*v12 = d;


//round : 13 , i: 12
a = *v2;
b = *v7;
c = *v8;
d = *v13;
a = ADD32((a),(b))+XOR32(m[sigma[13][12]], con[sigma[13][12+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][12+1]], con[sigma[13][12]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v2 = a;
*v7 = b;
*v8 = c;
*v13 = d;


//round : 13 , i: 14
a = *v3;
b = *v4;
c = *v9;
d = *v14;
a = ADD32((a),(b))+XOR32(m[sigma[13][14]], con[sigma[13][14+1]]);
d = ROT32(XOR32((d),(a)),16);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)),12);
a = ADD32((a),(b))+XOR32(m[sigma[13][14+1]], con[sigma[13][14]]);
d = ROT32(XOR32((d),(a)), 8);
c = ADD32((c),(d));
b = ROT32(XOR32((b),(c)), 7);
*v3 = a;
*v4 = b;
*v9 = c;
*v14 = d;


