For uint8_t, this does not apply to printf(), since the uint8_t will always be promoted to int before it is passed to printf().
iis also on avr-gcc?

avr-gcc uint8_t scanf use hhu



printf("%10s part in ", man_p->name);
participate = man_p->participate;
for (i = 0; i < 3; i++) {
    if (participate & 0x01) {
        printf("%8s,", school_p->class[i].name );
    }
    participate = participate>>1;
}
