
// slave <-> master 通訊
char ASA_Slave_set(char LSByte, char Mask, char shift, char Data);
char ASA_Slave_put(char LSByte, char Bytes, void *Data_p);
char ASA_Slave_get(char LSByte, char Bytes, void *Data_p);
char ASA_Slave_fpt(char LSByte, char Mask, char shift, char Data);
char ASA_Slave_fgt(char LSByte, char Mask, char shift, char* Data_p);

char command_run( char CallType, char Bytes, char* Data_p, char* Get_Data_p );
