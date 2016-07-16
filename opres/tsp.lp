minimize
1x01 + 1x02 + 1x10 + 10x12 + 1x20 + 10x21
subject to
x00 + x01 + x02 + x10 + x11 + x12 + x20 + x21 + x22 = 2
x00 + x01 + x02 + x10 + x11 + x12 + x20 + x21 + x22 = 1
x01 - x10 = 0 
x02 - x20 = 0 
x10 - x01 = 0 
x12 - x21 = 0 
x20 - x02 = 0 
x21 - x12 = 0 
t1 - t1 + 3x11 <= 2
t1 - t2 + 3x12 <= 2
t2 - t1 + 3x21 <= 2
t2 - t2 + 3x22 <= 2
binary
x00 x01 x02 x10 x11 x12 x20 x21 x22 
