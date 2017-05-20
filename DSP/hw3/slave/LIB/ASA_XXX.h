// slave <->  通訊
char XXX_set(char LSByte, char Mask, char shift, char Data);
char XXX_put(char LSByte, char Bytes, void *Data_p);
char XXX_get(char LSByte, char Bytes, void *Data_p);
char XXX_fpt(char LSByte, char Mask, char shift, char Data);
char XXX_fgt(char LSByte, char Mask, char shift, char* Data_p);
