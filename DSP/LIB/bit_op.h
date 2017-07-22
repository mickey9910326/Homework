#ifndef __bit_op_h__
#define __bit_op_h__

#define bit(m) (1<<(m))
#define bit_set(p,m)   ((p)|=  bit(m))  //set   the bit m of p
#define bit_clear(p,m) ((p)&= ~bit(m))  //clear the bit m of p
// #define bit_is_set(p,m)   ( (p & bit(m))) //test the bit m of p is set(1)
// #define bit_is_clear(p,m) (!(p & bit(m))) //test the bit m of p is clear(0)
#define bit_get(p,m)  (((p)& bit(m)) >>m) //get the bit m of p is 0 or 1

// it's easier to be replaced by bit_set & bit_clear
#define bit_put(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))   //put c into the bit m of p
#define bit_flip(p,m) bit_put((~(bit_get(p,m))),p,m)  //flip the bit m of p, 1->0, 0->1

#define bits_get(dest, mask, shift) (((dest) & (mask)) >> shift)
#define bits_put(dest, data, mask, shift) (dest = (((dest)&(~mask)) | ((data <<shift) & mask)))

#define BITSET(ADDRESS,BIT)    (ADDRESS |= (1<<BIT))
#define BITCLR(ADDRESS,BIT)    (ADDRESS &= ~(1<<BIT))
#define BITCHK(ADDRESS,BIT)    ((ADDRESS & (1<<BIT))==(1<<BIT))

#endif
