#include "som_c.h"

/* C038CE clear_cast_queues_and_seed_fifteen_byte_random_pool   [class B, 144 bytes, 72 instructions]
 * Source: src/rom/clear_cast_queues_and_seed_fifteen_byte_random_pool.s
 * Documented in docs/boss-cast-queue-initialize.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void clear_cast_queues_and_seed_fifteen_byte_random_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t x1 = 0;
    uint16_t y1 = 0x10;
    for (;;) {
        RAM16_SET(0x0380 + x1, 0);
        RAM16_SET(0x03A0 + x1, 0);
        RAM16_SET(0x03C0 + x1, 0);
        RAM16_SET(0x03E0 + x1, 0);
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    uint16_t x2 = 0xFE00;
    uint16_t y2 = 0x63;
    for (;;) {
        RAM16_SET(0x0000 + x2, 0);
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 - 1);
        if (!(y2 != 0)) break;
    }
    RAM16_SET(0x03B4, a);
    uint8_t a1;
    uint8_t a_hi1;
    if (a != 0) {
        a1 = (uint8_t)a;
        a_hi1 = a >> 8;
    } else {
        a1 = 0x24;
        a_hi1 = 0x75;
    }
    RAM16_SET(0x03B4, (a_hi1 << 8) | a1);
    uint8_t a_hi2 = a_hi1;
    uint16_t x3 = x2;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            RAM8(0x03B2) = 0x0F;
            uint8_t a_hi3 = a_hi2;
            uint16_t x4 = 0x03F1;
            bool first_pass2 = true;
            for (;;) {
                if (first_pass2) {
                    uint16_t value = RAM16(0x03B4);
                    uint8_t a3;
                    uint8_t a_hi5;
                    if ((value & 0x4001) == 0) {
                        RAM16_SET(0x03B4, value >> 1);
                        a3 = (uint8_t)(value >> 1);
                        a_hi5 = value >> 1 >> 8;
                    } else {
                        uint8_t a2;
                        uint8_t a_hi4;
                        if (((value & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x03B4, value >> 1);
                            a2 = (uint8_t)(value >> 1);
                            a_hi4 = value >> 1 >> 8;
                        } else {
                            RAM16_SET(0x03B4, (value | 0x8000) >> 1);
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
                    RAM8(0x0000 + x4) = (uint8_t)(((a_hi5 << 8) | a3) >> 1);
                    RAM8(0x03B2)--;
                    if (RAM8(0x03B2) != 0) {
                        a_hi3 = ((a_hi5 << 8) | a3) >> 1 >> 8;
                        x4 = (uint16_t)(x4 + 1);
                        continue;
                    }
                    a_hi3 = ((a_hi5 << 8) | a3) >> 1 >> 8;
                    x4 = (uint16_t)(x4 + 1);
                    break;
                } else {
                    uint16_t value2 = RAM16(0x03B4);
                    uint8_t a5;
                    uint8_t a_hi7;
                    if ((value2 & 0x4001) == 0) {
                        RAM16_SET(0x03B4, value2 >> 1);
                        a5 = (uint8_t)(value2 >> 1);
                        a_hi7 = value2 >> 1 >> 8;
                    } else {
                        uint8_t a4;
                        uint8_t a_hi6;
                        if (((value2 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x03B4, value2 >> 1);
                            a4 = (uint8_t)(value2 >> 1);
                            a_hi6 = value2 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x03B4, (value2 | 0x8000) >> 1);
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
                    RAM8(0x0000 + x4) = (uint8_t)(((a_hi7 << 8) | a5) >> 1);
                    RAM8(0x03B2)--;
                    if (RAM8(0x03B2) != 0) {
                        a_hi3 = ((a_hi7 << 8) | a5) >> 1 >> 8;
                        x4 = (uint16_t)(x4 + 1);
                        first_pass2 = true;
                        continue;
                    }
                    a_hi3 = ((a_hi7 << 8) | a5) >> 1 >> 8;
                    x4 = (uint16_t)(x4 + 1);
                    break;
                }
            }
            RAM8(0x03B2) = 0x0F;
            uint8_t a6 = 0;
            uint8_t a_hi8 = a_hi3;
            uint16_t x5 = 0x03F1;
            do {
                uint8_t value3 = RAM8(0x0000 + x5);
                RAM8(0x03B2)--;
                a6 = a6 | value3;
                x5 = (uint16_t)(x5 + 1);
            } while (RAM8(0x03B2) != 0);
            if (a6 != 0xFF) {
                a_hi2 = a_hi8;
                x3 = x5;
                first_pass = false;
                continue;
            }
            a_hi2 = a_hi8;
            x3 = x5;
            break;
        } else {
            RAM8(0x03B2) = 0x0F;
            uint8_t a_hi9 = a_hi2;
            uint16_t x6 = 0x03F1;
            bool first_pass3 = true;
            for (;;) {
                if (first_pass3) {
                    uint16_t value4 = RAM16(0x03B4);
                    uint8_t a8;
                    uint8_t a_hi11;
                    if ((value4 & 0x4001) == 0) {
                        RAM16_SET(0x03B4, value4 >> 1);
                        a8 = (uint8_t)(value4 >> 1);
                        a_hi11 = value4 >> 1 >> 8;
                    } else {
                        uint8_t a7;
                        uint8_t a_hi10;
                        if (((value4 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x03B4, value4 >> 1);
                            a7 = (uint8_t)(value4 >> 1);
                            a_hi10 = value4 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x03B4, (value4 | 0x8000) >> 1);
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
                    RAM8(0x0000 + x6) = (uint8_t)(((a_hi11 << 8) | a8) >> 1);
                    RAM8(0x03B2)--;
                    if (RAM8(0x03B2) != 0) {
                        a_hi9 = ((a_hi11 << 8) | a8) >> 1 >> 8;
                        x6 = (uint16_t)(x6 + 1);
                        continue;
                    }
                    a_hi9 = ((a_hi11 << 8) | a8) >> 1 >> 8;
                    x6 = (uint16_t)(x6 + 1);
                    break;
                } else {
                    uint16_t value5 = RAM16(0x03B4);
                    uint8_t a10;
                    uint8_t a_hi13;
                    if ((value5 & 0x4001) == 0) {
                        RAM16_SET(0x03B4, value5 >> 1);
                        a10 = (uint8_t)(value5 >> 1);
                        a_hi13 = value5 >> 1 >> 8;
                    } else {
                        uint8_t a9;
                        uint8_t a_hi12;
                        if (((value5 & 0x4001) ^ 0x4001) == 0) {
                            RAM16_SET(0x03B4, value5 >> 1);
                            a9 = (uint8_t)(value5 >> 1);
                            a_hi12 = value5 >> 1 >> 8;
                        } else {
                            RAM16_SET(0x03B4, (value5 | 0x8000) >> 1);
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
                    RAM8(0x0000 + x6) = (uint8_t)(((a_hi13 << 8) | a10) >> 1);
                    RAM8(0x03B2)--;
                    if (RAM8(0x03B2) != 0) {
                        a_hi9 = ((a_hi13 << 8) | a10) >> 1 >> 8;
                        x6 = (uint16_t)(x6 + 1);
                        first_pass3 = true;
                        continue;
                    }
                    a_hi9 = ((a_hi13 << 8) | a10) >> 1 >> 8;
                    x6 = (uint16_t)(x6 + 1);
                    break;
                }
            }
            RAM8(0x03B2) = 0x0F;
            uint8_t a11 = 0;
            uint8_t a_hi14 = a_hi9;
            uint16_t x7 = 0x03F1;
            do {
                uint8_t value6 = RAM8(0x0000 + x7);
                RAM8(0x03B2)--;
                a11 = a11 | value6;
                x7 = (uint16_t)(x7 + 1);
            } while (RAM8(0x03B2) != 0);
            if (a11 != 0xFF) {
                a_hi2 = a_hi14;
                x3 = x7;
                continue;
            }
            a_hi2 = a_hi14;
            x3 = x7;
            break;
        }
    }
    RAM8(0x03F0) = 0;
    r->x = x3;
    r->y = y2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC038CE, SOM_RTL, "gen", clear_cast_queues_and_seed_fifteen_byte_random_pool, 0, L_X | L_Y, 6, 0, 0, 144, 72)
