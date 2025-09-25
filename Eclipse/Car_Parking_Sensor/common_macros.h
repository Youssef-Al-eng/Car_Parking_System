#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(REG, BIT)        ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG, BIT)      ((REG) &= ~(1 << (BIT)))
#define TOGGLE_BIT(REG, BIT)     ((REG) ^= (1 << (BIT)))
#define GET_BIT(REG, BIT)        (((REG) >> (BIT)) & 0x01)
#define CLEAR_REG(REG)           ((REG) = 0)
#define WRITE_REG(REG, VALUE)    ((REG) = (VALUE))
#define ROR(REG, NUM)            ((REG) = ((REG) >> (NUM)) | ((REG) << (8 - (NUM))))
#define ROL(REG, NUM)            ((REG) = ((REG) << (NUM)) | ((REG) >> (8 - (NUM))))
#define BIT_IS_SET(REG, BIT)     ((REG) & (1 << (BIT)))
#define BIT_IS_CLEAR(REG, BIT)   (!((REG) & (1 << (BIT))))

#endif /* COMMON_MACROS_H_ */
