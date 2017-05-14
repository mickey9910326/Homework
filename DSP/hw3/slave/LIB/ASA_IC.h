#ifndef __ASA_IC_h__
#define __ASA_IC_h__

// slave <-> ic 通訊
char ic_set(char LSByte, char Mask, char shift, char Data);
char ic_put(char LSByte, char Bytes, void *Data_p);
char ic_get(char LSByte, char Bytes, void *Data_p);
char ic_fpt(char LSByte, char Mask, char shift, char Data);
char ic_fgt(char LSByte, char Mask, char shift, char* Data_p);

#endif
