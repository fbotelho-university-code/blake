//ROUND :::::::::::: 0
//round : 0 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[0][0]], c[sigma[0][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[0][0+1]], c[sigma[0][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 0 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[0][2]], c[sigma[0][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[0][2+1]], c[sigma[0][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 0 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[0][4]], c[sigma[0][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[0][4+1]], c[sigma[0][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 0 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[0][6]], c[sigma[0][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[0][6+1]], c[sigma[0][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 0 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[0][8]], c[sigma[0][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[0][8+1]], c[sigma[0][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 0 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[0][10]], c[sigma[0][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[0][10+1]], c[sigma[0][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 0 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[0][12]], c[sigma[0][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[0][12+1]], c[sigma[0][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 0 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[0][14]], c[sigma[0][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[0][14+1]], c[sigma[0][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 1
//round : 1 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[1][0]], c[sigma[1][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[1][0+1]], c[sigma[1][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 1 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[1][2]], c[sigma[1][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[1][2+1]], c[sigma[1][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 1 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[1][4]], c[sigma[1][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[1][4+1]], c[sigma[1][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 1 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[1][6]], c[sigma[1][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[1][6+1]], c[sigma[1][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 1 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[1][8]], c[sigma[1][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[1][8+1]], c[sigma[1][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 1 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[1][10]], c[sigma[1][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[1][10+1]], c[sigma[1][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 1 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[1][12]], c[sigma[1][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[1][12+1]], c[sigma[1][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 1 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[1][14]], c[sigma[1][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[1][14+1]], c[sigma[1][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 2
//round : 2 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[2][0]], c[sigma[2][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[2][0+1]], c[sigma[2][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 2 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[2][2]], c[sigma[2][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[2][2+1]], c[sigma[2][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 2 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[2][4]], c[sigma[2][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[2][4+1]], c[sigma[2][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 2 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[2][6]], c[sigma[2][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[2][6+1]], c[sigma[2][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 2 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[2][8]], c[sigma[2][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[2][8+1]], c[sigma[2][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 2 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[2][10]], c[sigma[2][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[2][10+1]], c[sigma[2][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 2 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[2][12]], c[sigma[2][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[2][12+1]], c[sigma[2][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 2 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[2][14]], c[sigma[2][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[2][14+1]], c[sigma[2][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 3
//round : 3 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[3][0]], c[sigma[3][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[3][0+1]], c[sigma[3][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 3 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[3][2]], c[sigma[3][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[3][2+1]], c[sigma[3][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 3 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[3][4]], c[sigma[3][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[3][4+1]], c[sigma[3][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 3 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[3][6]], c[sigma[3][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[3][6+1]], c[sigma[3][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 3 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[3][8]], c[sigma[3][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[3][8+1]], c[sigma[3][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 3 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[3][10]], c[sigma[3][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[3][10+1]], c[sigma[3][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 3 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[3][12]], c[sigma[3][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[3][12+1]], c[sigma[3][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 3 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[3][14]], c[sigma[3][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[3][14+1]], c[sigma[3][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 4
//round : 4 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[4][0]], c[sigma[4][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[4][0+1]], c[sigma[4][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 4 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[4][2]], c[sigma[4][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[4][2+1]], c[sigma[4][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 4 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[4][4]], c[sigma[4][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[4][4+1]], c[sigma[4][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 4 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[4][6]], c[sigma[4][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[4][6+1]], c[sigma[4][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 4 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[4][8]], c[sigma[4][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[4][8+1]], c[sigma[4][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 4 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[4][10]], c[sigma[4][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[4][10+1]], c[sigma[4][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 4 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[4][12]], c[sigma[4][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[4][12+1]], c[sigma[4][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 4 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[4][14]], c[sigma[4][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[4][14+1]], c[sigma[4][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 5
//round : 5 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[5][0]], c[sigma[5][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[5][0+1]], c[sigma[5][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 5 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[5][2]], c[sigma[5][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[5][2+1]], c[sigma[5][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 5 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[5][4]], c[sigma[5][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[5][4+1]], c[sigma[5][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 5 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[5][6]], c[sigma[5][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[5][6+1]], c[sigma[5][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 5 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[5][8]], c[sigma[5][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[5][8+1]], c[sigma[5][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 5 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[5][10]], c[sigma[5][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[5][10+1]], c[sigma[5][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 5 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[5][12]], c[sigma[5][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[5][12+1]], c[sigma[5][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 5 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[5][14]], c[sigma[5][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[5][14+1]], c[sigma[5][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 6
//round : 6 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[6][0]], c[sigma[6][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[6][0+1]], c[sigma[6][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 6 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[6][2]], c[sigma[6][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[6][2+1]], c[sigma[6][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 6 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[6][4]], c[sigma[6][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[6][4+1]], c[sigma[6][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 6 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[6][6]], c[sigma[6][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[6][6+1]], c[sigma[6][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 6 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[6][8]], c[sigma[6][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[6][8+1]], c[sigma[6][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 6 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[6][10]], c[sigma[6][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[6][10+1]], c[sigma[6][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 6 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[6][12]], c[sigma[6][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[6][12+1]], c[sigma[6][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 6 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[6][14]], c[sigma[6][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[6][14+1]], c[sigma[6][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 7
//round : 7 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[7][0]], c[sigma[7][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[7][0+1]], c[sigma[7][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 7 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[7][2]], c[sigma[7][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[7][2+1]], c[sigma[7][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 7 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[7][4]], c[sigma[7][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[7][4+1]], c[sigma[7][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 7 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[7][6]], c[sigma[7][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[7][6+1]], c[sigma[7][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 7 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[7][8]], c[sigma[7][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[7][8+1]], c[sigma[7][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 7 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[7][10]], c[sigma[7][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[7][10+1]], c[sigma[7][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 7 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[7][12]], c[sigma[7][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[7][12+1]], c[sigma[7][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 7 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[7][14]], c[sigma[7][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[7][14+1]], c[sigma[7][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 8
//round : 8 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[8][0]], c[sigma[8][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[8][0+1]], c[sigma[8][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 8 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[8][2]], c[sigma[8][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[8][2+1]], c[sigma[8][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 8 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[8][4]], c[sigma[8][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[8][4+1]], c[sigma[8][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 8 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[8][6]], c[sigma[8][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[8][6+1]], c[sigma[8][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 8 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[8][8]], c[sigma[8][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[8][8+1]], c[sigma[8][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 8 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[8][10]], c[sigma[8][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[8][10+1]], c[sigma[8][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 8 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[8][12]], c[sigma[8][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[8][12+1]], c[sigma[8][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 8 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[8][14]], c[sigma[8][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[8][14+1]], c[sigma[8][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 9
//round : 9 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[9][0]], c[sigma[9][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[9][0+1]], c[sigma[9][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 9 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[9][2]], c[sigma[9][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[9][2+1]], c[sigma[9][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 9 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[9][4]], c[sigma[9][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[9][4+1]], c[sigma[9][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 9 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[9][6]], c[sigma[9][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[9][6+1]], c[sigma[9][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 9 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[9][8]], c[sigma[9][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[9][8+1]], c[sigma[9][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 9 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[9][10]], c[sigma[9][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[9][10+1]], c[sigma[9][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 9 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[9][12]], c[sigma[9][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[9][12+1]], c[sigma[9][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 9 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[9][14]], c[sigma[9][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[9][14+1]], c[sigma[9][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 10
//round : 10 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[10][0]], c[sigma[10][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[10][0+1]], c[sigma[10][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 10 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[10][2]], c[sigma[10][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[10][2+1]], c[sigma[10][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 10 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[10][4]], c[sigma[10][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[10][4+1]], c[sigma[10][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 10 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[10][6]], c[sigma[10][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[10][6+1]], c[sigma[10][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 10 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[10][8]], c[sigma[10][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[10][8+1]], c[sigma[10][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 10 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[10][10]], c[sigma[10][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[10][10+1]], c[sigma[10][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 10 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[10][12]], c[sigma[10][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[10][12+1]], c[sigma[10][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 10 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[10][14]], c[sigma[10][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[10][14+1]], c[sigma[10][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 11
//round : 11 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[11][0]], c[sigma[11][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[11][0+1]], c[sigma[11][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 11 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[11][2]], c[sigma[11][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[11][2+1]], c[sigma[11][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 11 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[11][4]], c[sigma[11][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[11][4+1]], c[sigma[11][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 11 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[11][6]], c[sigma[11][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[11][6+1]], c[sigma[11][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 11 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[11][8]], c[sigma[11][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[11][8+1]], c[sigma[11][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 11 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[11][10]], c[sigma[11][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[11][10+1]], c[sigma[11][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 11 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[11][12]], c[sigma[11][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[11][12+1]], c[sigma[11][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 11 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[11][14]], c[sigma[11][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[11][14+1]], c[sigma[11][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 12
//round : 12 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[12][0]], c[sigma[12][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[12][0+1]], c[sigma[12][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 12 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[12][2]], c[sigma[12][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[12][2+1]], c[sigma[12][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 12 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[12][4]], c[sigma[12][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[12][4+1]], c[sigma[12][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 12 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[12][6]], c[sigma[12][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[12][6+1]], c[sigma[12][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 12 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[12][8]], c[sigma[12][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[12][8+1]], c[sigma[12][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 12 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[12][10]], c[sigma[12][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[12][10+1]], c[sigma[12][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 12 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[12][12]], c[sigma[12][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[12][12+1]], c[sigma[12][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 12 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[12][14]], c[sigma[12][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[12][14+1]], c[sigma[12][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


//ROUND :::::::::::: 13
//round : 13 , i: 0
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[13][0]], c[sigma[13][0+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[4] ))+XOR32(m[sigma[13][0+1]], c[sigma[13][0]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[0] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[12] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[8] )), 7);


//round : 13 , i: 2
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[13][2]], c[sigma[13][2+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[5] ))+XOR32(m[sigma[13][2+1]], c[sigma[13][2]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[1] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[13] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[9] )), 7);


//round : 13 , i: 4
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[13][4]], c[sigma[13][4+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[6] ))+XOR32(m[sigma[13][4+1]], c[sigma[13][4]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[2] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[14] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[10] )), 7);


//round : 13 , i: 6
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[13][6]], c[sigma[13][6+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[7] ))+XOR32(m[sigma[13][6+1]], c[sigma[13][6]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[3] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[15] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[11] )), 7);


//round : 13 , i: 8
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[13][8]], c[sigma[13][8+1]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )),16);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )),12);
 state32[0]  = ADD32(( state32[0] ),( state32[5] ))+XOR32(m[sigma[13][8+1]], c[sigma[13][8]]);
 state32[15]  = ROT32(XOR32(( state32[15] ),( state32[0] )), 8);
 state32[10]  = ADD32(( state32[10] ),( state32[15] ));
 state32[5]  = ROT32(XOR32(( state32[5] ),( state32[10] )), 7);


//round : 13 , i: 10
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[13][10]], c[sigma[13][10+1]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )),16);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )),12);
 state32[1]  = ADD32(( state32[1] ),( state32[6] ))+XOR32(m[sigma[13][10+1]], c[sigma[13][10]]);
 state32[12]  = ROT32(XOR32(( state32[12] ),( state32[1] )), 8);
 state32[11]  = ADD32(( state32[11] ),( state32[12] ));
 state32[6]  = ROT32(XOR32(( state32[6] ),( state32[11] )), 7);


//round : 13 , i: 12
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[13][12]], c[sigma[13][12+1]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )),16);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )),12);
 state32[2]  = ADD32(( state32[2] ),( state32[7] ))+XOR32(m[sigma[13][12+1]], c[sigma[13][12]]);
 state32[13]  = ROT32(XOR32(( state32[13] ),( state32[2] )), 8);
 state32[8]  = ADD32(( state32[8] ),( state32[13] ));
 state32[7]  = ROT32(XOR32(( state32[7] ),( state32[8] )), 7);


//round : 13 , i: 14
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[13][14]], c[sigma[13][14+1]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )),16);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )),12);
 state32[3]  = ADD32(( state32[3] ),( state32[4] ))+XOR32(m[sigma[13][14+1]], c[sigma[13][14]]);
 state32[14]  = ROT32(XOR32(( state32[14] ),( state32[3] )), 8);
 state32[9]  = ADD32(( state32[9] ),( state32[14] ));
 state32[4]  = ROT32(XOR32(( state32[4] ),( state32[9] )), 7);


