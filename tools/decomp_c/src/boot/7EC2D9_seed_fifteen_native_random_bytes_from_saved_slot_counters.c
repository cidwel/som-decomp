#include "som_c.h"

/* 7EC2D9 seed_fifteen_native_random_bytes_from_saved_slot_counters   [class B, 116 bytes, 64 instructions]
 * Source: src/boot/seed_fifteen_native_random_bytes_from_saved_slot_counters.s
 * Documented in docs/boot-native-task-resources.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BXYCZNV.
 */
static void seed_fifteen_native_random_bytes_from_saved_slot_counters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 8) = 0x7F;
    uint8_t a1;
    uint8_t a_hi1;
    if (x != 0) {
        a1 = (uint8_t)x;
        a_hi1 = x >> 8;
    } else {
        a1 = 0x24;
        a_hi1 = 0x75;
    }
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (a_hi1 << 8) | a1);
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = x;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x0F;
            uint8_t a_hi3 = a_hi2;
            uint16_t x2 = 0x02E5;
            bool first_pass2 = true;
            for (;;) {
                if (first_pass2) {
                    uint16_t value = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                    uint8_t a3;
                    uint8_t a_hi5;
                    if ((value & 0x4001) == 0) {
                        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value >> 1);
                        a3 = (uint8_t)(value >> 1);
                        a_hi5 = value >> 1 >> 8;
                    } else {
                        uint8_t a2;
                        uint8_t a_hi4;
                        if (((value & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value >> 1);
                            a2 = (uint8_t)(value >> 1);
                            a_hi4 = value >> 1 >> 8;
                        } else {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (value | 0x8000) >> 1);
                            a2 = (uint8_t)((value | 0x8000) >> 1);
                            a_hi4 = (value | 0x8000) >> 1 >> 8;
                        }
                        a3 = a2;
                        a_hi5 = a_hi4;
                    }
                    if ((((a_hi5 << 8) | a3) & 1) == 0) {
                        a_hi3 = a_hi5;
                        first_pass2 = false;
                        continue;
                    }
                    RAM8(0x10000 + x2) = (uint8_t)(((a_hi5 << 8) | a3) >> 1);
                    RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                    if (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0) {
                        a_hi3 = ((a_hi5 << 8) | a3) >> 1 >> 8;
                        x2 = (uint16_t)(x2 + 1);
                        continue;
                    }
                    a_hi3 = ((a_hi5 << 8) | a3) >> 1 >> 8;
                    x2 = (uint16_t)(x2 + 1);
                    break;
                } else {
                    uint16_t value2 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                    uint8_t a5;
                    uint8_t a_hi7;
                    if ((value2 & 0x4001) == 0) {
                        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value2 >> 1);
                        a5 = (uint8_t)(value2 >> 1);
                        a_hi7 = value2 >> 1 >> 8;
                    } else {
                        uint8_t a4;
                        uint8_t a_hi6;
                        if (((value2 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value2 >> 1);
                            a4 = (uint8_t)(value2 >> 1);
                            a_hi6 = value2 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (value2 | 0x8000) >> 1);
                            a4 = (uint8_t)((value2 | 0x8000) >> 1);
                            a_hi6 = (value2 | 0x8000) >> 1 >> 8;
                        }
                        a5 = a4;
                        a_hi7 = a_hi6;
                    }
                    if ((((a_hi7 << 8) | a5) & 1) == 0) {
                        a_hi3 = a_hi7;
                        continue;
                    }
                    RAM8(0x10000 + x2) = (uint8_t)(((a_hi7 << 8) | a5) >> 1);
                    RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                    if (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0) {
                        a_hi3 = ((a_hi7 << 8) | a5) >> 1 >> 8;
                        x2 = (uint16_t)(x2 + 1);
                        first_pass2 = true;
                        continue;
                    }
                    a_hi3 = ((a_hi7 << 8) | a5) >> 1 >> 8;
                    x2 = (uint16_t)(x2 + 1);
                    break;
                }
            }
            RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x0F;
            uint8_t a6 = 0;
            uint8_t a_hi8 = a_hi3;
            uint16_t x3 = 0x02E5;
            do {
                uint8_t value3 = RAM8(0x10000 + x3);
                RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                a6 = a6 | value3;
                x3 = (uint16_t)(x3 + 1);
            } while (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0);
            if (a6 != 0xFF) {
                a_hi2 = a_hi8;
                x1 = x3;
                first_pass = false;
                continue;
            }
            a_hi2 = a_hi8;
            x1 = x3;
            break;
        } else {
            RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x0F;
            uint8_t a_hi9 = a_hi2;
            uint16_t x4 = 0x02E5;
            bool first_pass3 = true;
            for (;;) {
                if (first_pass3) {
                    uint16_t value4 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                    uint8_t a8;
                    uint8_t a_hi11;
                    if ((value4 & 0x4001) == 0) {
                        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value4 >> 1);
                        a8 = (uint8_t)(value4 >> 1);
                        a_hi11 = value4 >> 1 >> 8;
                    } else {
                        uint8_t a7;
                        uint8_t a_hi10;
                        if (((value4 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value4 >> 1);
                            a7 = (uint8_t)(value4 >> 1);
                            a_hi10 = value4 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (value4 | 0x8000) >> 1);
                            a7 = (uint8_t)((value4 | 0x8000) >> 1);
                            a_hi10 = (value4 | 0x8000) >> 1 >> 8;
                        }
                        a8 = a7;
                        a_hi11 = a_hi10;
                    }
                    if ((((a_hi11 << 8) | a8) & 1) == 0) {
                        a_hi9 = a_hi11;
                        first_pass3 = false;
                        continue;
                    }
                    RAM8(0x10000 + x4) = (uint8_t)(((a_hi11 << 8) | a8) >> 1);
                    RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                    if (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0) {
                        a_hi9 = ((a_hi11 << 8) | a8) >> 1 >> 8;
                        x4 = (uint16_t)(x4 + 1);
                        continue;
                    }
                    a_hi9 = ((a_hi11 << 8) | a8) >> 1 >> 8;
                    x4 = (uint16_t)(x4 + 1);
                    break;
                } else {
                    uint16_t value5 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                    uint8_t a10;
                    uint8_t a_hi13;
                    if ((value5 & 0x4001) == 0) {
                        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value5 >> 1);
                        a10 = (uint8_t)(value5 >> 1);
                        a_hi13 = value5 >> 1 >> 8;
                    } else {
                        uint8_t a9;
                        uint8_t a_hi12;
                        if (((value5 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value5 >> 1);
                            a9 = (uint8_t)(value5 >> 1);
                            a_hi12 = value5 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (value5 | 0x8000) >> 1);
                            a9 = (uint8_t)((value5 | 0x8000) >> 1);
                            a_hi12 = (value5 | 0x8000) >> 1 >> 8;
                        }
                        a10 = a9;
                        a_hi13 = a_hi12;
                    }
                    if ((((a_hi13 << 8) | a10) & 1) == 0) {
                        a_hi9 = a_hi13;
                        continue;
                    }
                    RAM8(0x10000 + x4) = (uint8_t)(((a_hi13 << 8) | a10) >> 1);
                    RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                    if (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0) {
                        a_hi9 = ((a_hi13 << 8) | a10) >> 1 >> 8;
                        x4 = (uint16_t)(x4 + 1);
                        first_pass3 = true;
                        continue;
                    }
                    a_hi9 = ((a_hi13 << 8) | a10) >> 1 >> 8;
                    x4 = (uint16_t)(x4 + 1);
                    break;
                }
            }
            RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x0F;
            uint8_t a11 = 0;
            uint8_t a_hi14 = a_hi9;
            uint16_t x5 = 0x02E5;
            do {
                uint8_t value6 = RAM8(0x10000 + x5);
                RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
                a11 = a11 | value6;
                x5 = (uint16_t)(x5 + 1);
            } while (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0);
            if (a11 != 0xFF) {
                a_hi2 = a_hi14;
                x1 = x5;
                continue;
            }
            a_hi2 = a_hi14;
            x1 = x5;
            break;
        }
    }
    RAM8(0x102E4) = 0;
    uint8_t value10 = RAM8(0x0000 + sp0 - 3);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | value10;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->z = ((value12 << 8) | value11) == 0;
    r->n = ((value12 << 8) | value11) & 0x8000;
    r->v = overflow;
    r->dp = (value12 << 8) | value11;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC2D9, SOM_RTS, "gen", seed_fifteen_native_random_bytes_from_saved_slot_counters, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 0, 0, 116, 64)
