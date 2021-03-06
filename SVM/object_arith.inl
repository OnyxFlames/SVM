#pragma once

#define OBJECT_NUMERIC_BINARY_ARITH32(ret, obj1, obj2, op)\
switch (get_type_pair(obj1.getType(), obj2.getType()))\
{\
case 257: ret = Object(obj1.getData().i8 op obj2.getData().i8);break;\
case 513: ret = Object(obj1.getData().i8 op obj2.getData().u8);break;\
case 769: ret = Object(obj1.getData().i8 op obj2.getData().i16);break;\
case 1025: ret = Object(obj1.getData().i8 op obj2.getData().u16);break;\
case 1281: ret = Object(obj1.getData().i8 op obj2.getData().i32);break;\
case 1537: ret = Object(obj1.getData().i8 op obj2.getData().u32);break;\
case 2305: ret = Object(obj1.getData().i8 op obj2.getData().f32);break;\
case 258: ret = Object(obj1.getData().u8 op obj2.getData().i8);break;\
case 514: ret = Object(obj1.getData().u8 op obj2.getData().u8);break;\
case 770: ret = Object(obj1.getData().u8 op obj2.getData().i16);break;\
case 1026: ret = Object(obj1.getData().u8 op obj2.getData().u16);break;\
case 1282: ret = Object(obj1.getData().u8 op obj2.getData().i32);break;\
case 1538: ret = Object(obj1.getData().u8 op obj2.getData().u32);break;\
case 2306: ret = Object(obj1.getData().u8 op obj2.getData().f32);break;\
case 259: ret = Object(obj1.getData().i16 op obj2.getData().i8);break;\
case 515: ret = Object(obj1.getData().i16 op obj2.getData().u8);break;\
case 771: ret = Object(obj1.getData().i16 op obj2.getData().i16);break;\
case 1027: ret = Object(obj1.getData().i16 op obj2.getData().u16);break;\
case 1283: ret = Object(obj1.getData().i16 op obj2.getData().i32);break;\
case 1539: ret = Object(obj1.getData().i16 op obj2.getData().u32);break;\
case 2307: ret = Object(obj1.getData().i16 op obj2.getData().f32);break;\
case 260: ret = Object(obj1.getData().u16 op obj2.getData().i8);break;\
case 516: ret = Object(obj1.getData().u16 op obj2.getData().u8);break;\
case 772: ret = Object(obj1.getData().u16 op obj2.getData().i16);break;\
case 1028: ret = Object(obj1.getData().u16 op obj2.getData().u16);break;\
case 1284: ret = Object(obj1.getData().u16 op obj2.getData().i32);break;\
case 1540: ret = Object(obj1.getData().u16 op obj2.getData().u32);break;\
case 2308: ret = Object(obj1.getData().u16 op obj2.getData().f32);break;\
case 261: ret = Object(obj1.getData().i32 op obj2.getData().i8);break;\
case 517: ret = Object(obj1.getData().i32 op obj2.getData().u8);break;\
case 773: ret = Object(obj1.getData().i32 op obj2.getData().i16);break;\
case 1029: ret = Object(obj1.getData().i32 op obj2.getData().u16);break;\
case 1285: ret = Object(obj1.getData().i32 op obj2.getData().i32);break;\
case 1541: ret = Object(obj1.getData().i32 op obj2.getData().u32);break;\
case 2309: ret = Object(obj1.getData().i32 op obj2.getData().f32);break;\
case 262: ret = Object(obj1.getData().u32 op obj2.getData().i8);break;\
case 518: ret = Object(obj1.getData().u32 op obj2.getData().u8);break;\
case 774: ret = Object(obj1.getData().u32 op obj2.getData().i16);break;\
case 1030: ret = Object(obj1.getData().u32 op obj2.getData().u16);break;\
case 1286: ret = Object(obj1.getData().u32 op obj2.getData().i32);break;\
case 1542: ret = Object(obj1.getData().u32 op obj2.getData().u32);break;\
case 2310: ret = Object(obj1.getData().u32 op obj2.getData().f32);break;\
case 265: ret = Object(obj1.getData().f32 op obj2.getData().i8);break;\
case 521: ret = Object(obj1.getData().f32 op obj2.getData().u8);break;\
case 777: ret = Object(obj1.getData().f32 op obj2.getData().i16);break;\
case 1033: ret = Object(obj1.getData().f32 op obj2.getData().u16);break;\
case 1289: ret = Object(obj1.getData().f32 op obj2.getData().i32);break;\
case 1545: ret = Object(obj1.getData().f32 op obj2.getData().u32);break;\
case 2313: ret = Object(obj1.getData().f32 op obj2.getData().f32);break;\
default: assert(false && "Reached end of switch"); break;\
}\

#define OBJECT_INTEGRAL_BINARY_ARITH32(ret, obj1, obj2, op)\
switch (get_type_pair(obj1.getType(), obj2.getType()))\
{\
case 257: ret = Object(obj1.getData().i8 op obj2.getData().i8);break;\
case 513: ret = Object(obj1.getData().i8 op obj2.getData().u8);break;\
case 769: ret = Object(obj1.getData().i8 op obj2.getData().i16);break;\
case 1025: ret = Object(obj1.getData().i8 op obj2.getData().u16);break;\
case 1281: ret = Object(obj1.getData().i8 op obj2.getData().i32);break;\
case 1537: ret = Object(obj1.getData().i8 op obj2.getData().u32);break;\
case 258: ret = Object(obj1.getData().u8 op obj2.getData().i8);break;\
case 514: ret = Object(obj1.getData().u8 op obj2.getData().u8);break;\
case 770: ret = Object(obj1.getData().u8 op obj2.getData().i16);break;\
case 1026: ret = Object(obj1.getData().u8 op obj2.getData().u16);break;\
case 1282: ret = Object(obj1.getData().u8 op obj2.getData().i32);break;\
case 1538: ret = Object(obj1.getData().u8 op obj2.getData().u32);break;\
case 259: ret = Object(obj1.getData().i16 op obj2.getData().i8);break;\
case 515: ret = Object(obj1.getData().i16 op obj2.getData().u8);break;\
case 771: ret = Object(obj1.getData().i16 op obj2.getData().i16);break;\
case 1027: ret = Object(obj1.getData().i16 op obj2.getData().u16);break;\
case 1283: ret = Object(obj1.getData().i16 op obj2.getData().i32);break;\
case 1539: ret = Object(obj1.getData().i16 op obj2.getData().u32);break;\
case 260: ret = Object(obj1.getData().u16 op obj2.getData().i8);break;\
case 516: ret = Object(obj1.getData().u16 op obj2.getData().u8);break;\
case 772: ret = Object(obj1.getData().u16 op obj2.getData().i16);break;\
case 1028: ret = Object(obj1.getData().u16 op obj2.getData().u16);break;\
case 1284: ret = Object(obj1.getData().u16 op obj2.getData().i32);break;\
case 1540: ret = Object(obj1.getData().u16 op obj2.getData().u32);break;\
case 261: ret = Object(obj1.getData().i32 op obj2.getData().i8);break;\
case 517: ret = Object(obj1.getData().i32 op obj2.getData().u8);break;\
case 773: ret = Object(obj1.getData().i32 op obj2.getData().i16);break;\
case 1029: ret = Object(obj1.getData().i32 op obj2.getData().u16);break;\
case 1285: ret = Object(obj1.getData().i32 op obj2.getData().i32);break;\
case 1541: ret = Object(obj1.getData().i32 op obj2.getData().u32);break;\
case 262: ret = Object(obj1.getData().u32 op obj2.getData().i8);break;\
case 518: ret = Object(obj1.getData().u32 op obj2.getData().u8);break;\
case 774: ret = Object(obj1.getData().u32 op obj2.getData().i16);break;\
case 1030: ret = Object(obj1.getData().u32 op obj2.getData().u16);break;\
case 1286: ret = Object(obj1.getData().u32 op obj2.getData().i32);break;\
case 1542: ret = Object(obj1.getData().u32 op obj2.getData().u32);break;\
default: assert(false && "Reached end of switch"); break;\
}\

#define OBJECT_NUMERIC_BINARY_ARITH64(ret, obj1, obj2, op)\
switch (get_type_pair(obj1.getType(), obj2.getType()))\
{\
case 257: ret = Object(obj1.getData().i8 op obj2.getData().i8);break;\
case 513: ret = Object(obj1.getData().i8 op obj2.getData().u8);break;\
case 769: ret = Object(obj1.getData().i8 op obj2.getData().i16);break;\
case 1025: ret = Object(obj1.getData().i8 op obj2.getData().u16);break;\
case 1281: ret = Object(obj1.getData().i8 op obj2.getData().i32);break;\
case 1537: ret = Object(obj1.getData().i8 op obj2.getData().u32);break;\
case 1793: ret = Object(obj1.getData().i8 op obj2.getData().i64);break;\
case 2049: ret = Object(obj1.getData().i8 op obj2.getData().u64);break;\
case 2305: ret = Object(obj1.getData().i8 op obj2.getData().f32);break;\
case 2561: ret = Object(obj1.getData().i8 op obj2.getData().f64);break;\
case 258: ret = Object(obj1.getData().u8 op obj2.getData().i8);break;\
case 514: ret = Object(obj1.getData().u8 op obj2.getData().u8);break;\
case 770: ret = Object(obj1.getData().u8 op obj2.getData().i16);break;\
case 1026: ret = Object(obj1.getData().u8 op obj2.getData().u16);break;\
case 1282: ret = Object(obj1.getData().u8 op obj2.getData().i32);break;\
case 1538: ret = Object(obj1.getData().u8 op obj2.getData().u32);break;\
case 1794: ret = Object(obj1.getData().u8 op obj2.getData().i64);break;\
case 2050: ret = Object(obj1.getData().u8 op obj2.getData().u64);break;\
case 2306: ret = Object(obj1.getData().u8 op obj2.getData().f32);break;\
case 2562: ret = Object(obj1.getData().u8 op obj2.getData().f64);break;\
case 259: ret = Object(obj1.getData().i16 op obj2.getData().i8);break;\
case 515: ret = Object(obj1.getData().i16 op obj2.getData().u8);break;\
case 771: ret = Object(obj1.getData().i16 op obj2.getData().i16);break;\
case 1027: ret = Object(obj1.getData().i16 op obj2.getData().u16);break;\
case 1283: ret = Object(obj1.getData().i16 op obj2.getData().i32);break;\
case 1539: ret = Object(obj1.getData().i16 op obj2.getData().u32);break;\
case 1795: ret = Object(obj1.getData().i16 op obj2.getData().i64);break;\
case 2051: ret = Object(obj1.getData().i16 op obj2.getData().u64);break;\
case 2307: ret = Object(obj1.getData().i16 op obj2.getData().f32);break;\
case 2563: ret = Object(obj1.getData().i16 op obj2.getData().f64);break;\
case 260: ret = Object(obj1.getData().u16 op obj2.getData().i8);break;\
case 516: ret = Object(obj1.getData().u16 op obj2.getData().u8);break;\
case 772: ret = Object(obj1.getData().u16 op obj2.getData().i16);break;\
case 1028: ret = Object(obj1.getData().u16 op obj2.getData().u16);break;\
case 1284: ret = Object(obj1.getData().u16 op obj2.getData().i32);break;\
case 1540: ret = Object(obj1.getData().u16 op obj2.getData().u32);break;\
case 1796: ret = Object(obj1.getData().u16 op obj2.getData().i64);break;\
case 2052: ret = Object(obj1.getData().u16 op obj2.getData().u64);break;\
case 2308: ret = Object(obj1.getData().u16 op obj2.getData().f32);break;\
case 2564: ret = Object(obj1.getData().u16 op obj2.getData().f64);break;\
case 261: ret = Object(obj1.getData().i32 op obj2.getData().i8);break;\
case 517: ret = Object(obj1.getData().i32 op obj2.getData().u8);break;\
case 773: ret = Object(obj1.getData().i32 op obj2.getData().i16);break;\
case 1029: ret = Object(obj1.getData().i32 op obj2.getData().u16);break;\
case 1285: ret = Object(obj1.getData().i32 op obj2.getData().i32);break;\
case 1541: ret = Object(obj1.getData().i32 op obj2.getData().u32);break;\
case 1797: ret = Object(obj1.getData().i32 op obj2.getData().i64);break;\
case 2053: ret = Object(obj1.getData().i32 op obj2.getData().u64);break;\
case 2309: ret = Object(obj1.getData().i32 op obj2.getData().f32);break;\
case 2565: ret = Object(obj1.getData().i32 op obj2.getData().f64);break;\
case 262: ret = Object(obj1.getData().u32 op obj2.getData().i8);break;\
case 518: ret = Object(obj1.getData().u32 op obj2.getData().u8);break;\
case 774: ret = Object(obj1.getData().u32 op obj2.getData().i16);break;\
case 1030: ret = Object(obj1.getData().u32 op obj2.getData().u16);break;\
case 1286: ret = Object(obj1.getData().u32 op obj2.getData().i32);break;\
case 1542: ret = Object(obj1.getData().u32 op obj2.getData().u32);break;\
case 1798: ret = Object(obj1.getData().u32 op obj2.getData().i64);break;\
case 2054: ret = Object(obj1.getData().u32 op obj2.getData().u64);break;\
case 2310: ret = Object(obj1.getData().u32 op obj2.getData().f32);break;\
case 2566: ret = Object(obj1.getData().u32 op obj2.getData().f64);break;\
case 263: ret = Object(obj1.getData().i64 op obj2.getData().i8);break;\
case 519: ret = Object(obj1.getData().i64 op obj2.getData().u8);break;\
case 775: ret = Object(obj1.getData().i64 op obj2.getData().i16);break;\
case 1031: ret = Object(obj1.getData().i64 op obj2.getData().u16);break;\
case 1287: ret = Object(obj1.getData().i64 op obj2.getData().i32);break;\
case 1543: ret = Object(obj1.getData().i64 op obj2.getData().u32);break;\
case 1799: ret = Object(obj1.getData().i64 op obj2.getData().i64);break;\
case 2055: ret = Object(obj1.getData().i64 op obj2.getData().u64);break;\
case 2311: ret = Object(obj1.getData().i64 op obj2.getData().f32);break;\
case 2567: ret = Object(obj1.getData().i64 op obj2.getData().f64);break;\
case 264: ret = Object(obj1.getData().u64 op obj2.getData().i8);break;\
case 520: ret = Object(obj1.getData().u64 op obj2.getData().u8);break;\
case 776: ret = Object(obj1.getData().u64 op obj2.getData().i16);break;\
case 1032: ret = Object(obj1.getData().u64 op obj2.getData().u16);break;\
case 1288: ret = Object(obj1.getData().u64 op obj2.getData().i32);break;\
case 1544: ret = Object(obj1.getData().u64 op obj2.getData().u32);break;\
case 1800: ret = Object(obj1.getData().u64 op obj2.getData().i64);break;\
case 2056: ret = Object(obj1.getData().u64 op obj2.getData().u64);break;\
case 2312: ret = Object(obj1.getData().u64 op obj2.getData().f32);break;\
case 2568: ret = Object(obj1.getData().u64 op obj2.getData().f64);break;\
case 265: ret = Object(obj1.getData().f32 op obj2.getData().i8);break;\
case 521: ret = Object(obj1.getData().f32 op obj2.getData().u8);break;\
case 777: ret = Object(obj1.getData().f32 op obj2.getData().i16);break;\
case 1033: ret = Object(obj1.getData().f32 op obj2.getData().u16);break;\
case 1289: ret = Object(obj1.getData().f32 op obj2.getData().i32);break;\
case 1545: ret = Object(obj1.getData().f32 op obj2.getData().u32);break;\
case 1801: ret = Object(obj1.getData().f32 op obj2.getData().i64);break;\
case 2057: ret = Object(obj1.getData().f32 op obj2.getData().u64);break;\
case 2313: ret = Object(obj1.getData().f32 op obj2.getData().f32);break;\
case 2569: ret = Object(obj1.getData().f32 op obj2.getData().f64);break;\
case 266: ret = Object(obj1.getData().f64 op obj2.getData().i8);break;\
case 522: ret = Object(obj1.getData().f64 op obj2.getData().u8);break;\
case 778: ret = Object(obj1.getData().f64 op obj2.getData().i16);break;\
case 1034: ret = Object(obj1.getData().f64 op obj2.getData().u16);break;\
case 1290: ret = Object(obj1.getData().f64 op obj2.getData().i32);break;\
case 1546: ret = Object(obj1.getData().f64 op obj2.getData().u32);break;\
case 1802: ret = Object(obj1.getData().f64 op obj2.getData().i64);break;\
case 2058: ret = Object(obj1.getData().f64 op obj2.getData().u64);break;\
case 2314: ret = Object(obj1.getData().f64 op obj2.getData().f32);break;\
case 2570: ret = Object(obj1.getData().f64 op obj2.getData().f64);break;\
default: assert(false && "Reached end of switch"); break;\
}\

#define OBJECT_INTEGRAL_BINARY_ARITH64(ret, obj1, obj2, op)\
switch (get_type_pair(obj1.getType(), obj2.getType()))\
{\
case 257: ret = Object(obj1.getData().i8 op obj2.getData().i8);break;\
case 513: ret = Object(obj1.getData().i8 op obj2.getData().u8);break;\
case 769: ret = Object(obj1.getData().i8 op obj2.getData().i16);break;\
case 1025: ret = Object(obj1.getData().i8 op obj2.getData().u16);break;\
case 1281: ret = Object(obj1.getData().i8 op obj2.getData().i32);break;\
case 1537: ret = Object(obj1.getData().i8 op obj2.getData().u32);break;\
case 1793: ret = Object(obj1.getData().i8 op obj2.getData().i64);break;\
case 2049: ret = Object(obj1.getData().i8 op obj2.getData().u64);break;\
case 258: ret = Object(obj1.getData().u8 op obj2.getData().i8);break;\
case 514: ret = Object(obj1.getData().u8 op obj2.getData().u8);break;\
case 770: ret = Object(obj1.getData().u8 op obj2.getData().i16);break;\
case 1026: ret = Object(obj1.getData().u8 op obj2.getData().u16);break;\
case 1282: ret = Object(obj1.getData().u8 op obj2.getData().i32);break;\
case 1538: ret = Object(obj1.getData().u8 op obj2.getData().u32);break;\
case 1794: ret = Object(obj1.getData().u8 op obj2.getData().i64);break;\
case 2050: ret = Object(obj1.getData().u8 op obj2.getData().u64);break;\
case 259: ret = Object(obj1.getData().i16 op obj2.getData().i8);break;\
case 515: ret = Object(obj1.getData().i16 op obj2.getData().u8);break;\
case 771: ret = Object(obj1.getData().i16 op obj2.getData().i16);break;\
case 1027: ret = Object(obj1.getData().i16 op obj2.getData().u16);break;\
case 1283: ret = Object(obj1.getData().i16 op obj2.getData().i32);break;\
case 1539: ret = Object(obj1.getData().i16 op obj2.getData().u32);break;\
case 1795: ret = Object(obj1.getData().i16 op obj2.getData().i64);break;\
case 2051: ret = Object(obj1.getData().i16 op obj2.getData().u64);break;\
case 260: ret = Object(obj1.getData().u16 op obj2.getData().i8);break;\
case 516: ret = Object(obj1.getData().u16 op obj2.getData().u8);break;\
case 772: ret = Object(obj1.getData().u16 op obj2.getData().i16);break;\
case 1028: ret = Object(obj1.getData().u16 op obj2.getData().u16);break;\
case 1284: ret = Object(obj1.getData().u16 op obj2.getData().i32);break;\
case 1540: ret = Object(obj1.getData().u16 op obj2.getData().u32);break;\
case 1796: ret = Object(obj1.getData().u16 op obj2.getData().i64);break;\
case 2052: ret = Object(obj1.getData().u16 op obj2.getData().u64);break;\
case 261: ret = Object(obj1.getData().i32 op obj2.getData().i8);break;\
case 517: ret = Object(obj1.getData().i32 op obj2.getData().u8);break;\
case 773: ret = Object(obj1.getData().i32 op obj2.getData().i16);break;\
case 1029: ret = Object(obj1.getData().i32 op obj2.getData().u16);break;\
case 1285: ret = Object(obj1.getData().i32 op obj2.getData().i32);break;\
case 1541: ret = Object(obj1.getData().i32 op obj2.getData().u32);break;\
case 1797: ret = Object(obj1.getData().i32 op obj2.getData().i64);break;\
case 2053: ret = Object(obj1.getData().i32 op obj2.getData().u64);break;\
case 262: ret = Object(obj1.getData().u32 op obj2.getData().i8);break;\
case 518: ret = Object(obj1.getData().u32 op obj2.getData().u8);break;\
case 774: ret = Object(obj1.getData().u32 op obj2.getData().i16);break;\
case 1030: ret = Object(obj1.getData().u32 op obj2.getData().u16);break;\
case 1286: ret = Object(obj1.getData().u32 op obj2.getData().i32);break;\
case 1542: ret = Object(obj1.getData().u32 op obj2.getData().u32);break;\
case 1798: ret = Object(obj1.getData().u32 op obj2.getData().i64);break;\
case 2054: ret = Object(obj1.getData().u32 op obj2.getData().u64);break;\
case 263: ret = Object(obj1.getData().i64 op obj2.getData().i8);break;\
case 519: ret = Object(obj1.getData().i64 op obj2.getData().u8);break;\
case 775: ret = Object(obj1.getData().i64 op obj2.getData().i16);break;\
case 1031: ret = Object(obj1.getData().i64 op obj2.getData().u16);break;\
case 1287: ret = Object(obj1.getData().i64 op obj2.getData().i32);break;\
case 1543: ret = Object(obj1.getData().i64 op obj2.getData().u32);break;\
case 1799: ret = Object(obj1.getData().i64 op obj2.getData().i64);break;\
case 2055: ret = Object(obj1.getData().i64 op obj2.getData().u64);break;\
case 264: ret = Object(obj1.getData().u64 op obj2.getData().i8);break;\
case 520: ret = Object(obj1.getData().u64 op obj2.getData().u8);break;\
case 776: ret = Object(obj1.getData().u64 op obj2.getData().i16);break;\
case 1032: ret = Object(obj1.getData().u64 op obj2.getData().u16);break;\
case 1288: ret = Object(obj1.getData().u64 op obj2.getData().i32);break;\
case 1544: ret = Object(obj1.getData().u64 op obj2.getData().u32);break;\
case 1800: ret = Object(obj1.getData().u64 op obj2.getData().i64);break;\
case 2056: ret = Object(obj1.getData().u64 op obj2.getData().u64);break;\
default: assert(false && "Reached end of switch"); break;\
}\

#define OBJECT_NUMERIC_UNARY_ARITH32(ret, obj, op)\
switch (obj.getType())\
{\
case 1: ret = Object(obj.getData().i8 op );break;\
case 2: ret = Object(obj.getData().u8 op );break;\
case 3: ret = Object(obj.getData().i16 op );break;\
case 4: ret = Object(obj.getData().u16 op );break;\
case 5: ret = Object(obj.getData().i32 op );break;\
case 6: ret = Object(obj.getData().u32 op );break;\
case 9: ret = Object(obj.getData().f32 op );break;\
default: assert(false && "Reached end of switch"); break;\
}\

#define OBJECT_NUMERIC_UNARY_ARITH64(ret, obj, op)\
switch (obj.getType())\
{\
case 1: ret = Object(obj.getData().i8 op );break;\
case 2: ret = Object(obj.getData().u8 op );break;\
case 3: ret = Object(obj.getData().i16 op );break;\
case 4: ret = Object(obj.getData().u16 op );break;\
case 5: ret = Object(obj.getData().i32 op );break;\
case 6: ret = Object(obj.getData().u32 op );break;\
case 7: ret = Object(obj.getData().i64 op );break;\
case 8: ret = Object(obj.getData().u64 op );break;\
case 9: ret = Object(obj.getData().f32 op );break;\
case 10: ret = Object(obj.getData().f64 op );break;\
default: assert(false && "Reached end of switch"); break;\
}\

