#include "som_c.h"

/* C18E93 steer_native_actor_effect_toward_target_with_fractional_sine_motion   [class C, 371 bytes, 198 instructions]
 * Source: src/rom/steer_native_actor_effect_toward_target_with_fractional_sine_motion.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XCV.
 */
static void steer_native_actor_effect_toward_target_with_fractional_sine_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(((uint16_t)((RAM16(0xE074 + y) & 0x7F) + RAM16(0xE045 + y)) ^ 0xFFFF) + RAM16(0xE022 + y) + 1) - RAM16(0x0006)));
    uint16_t value5 = RAM16(0xE020 + y);
    uint16_t value6 = RAM16(0x0004);
    RAM16_SET(0x000A, (uint16_t)(value5 - value6));
    uint8_t a3;
    if (!((uint16_t)(value5 - value6) & 0x8000)) {
        uint16_t value7 = RAM16(0x0008);
        uint8_t a1;
        if (!(value7 & 0x8000)) {
            a1 = 0;
        } else {
            RAM16_SET(0x0008, (uint16_t)((value7 ^ 0xFFFF) + 1));
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = 0xC0;
            uint16_t value8 = RAM16(0x000A);
            RAM8(0x0000 + sp0 - 2) = value8 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)value8;
            RAM16_SET(0x000A, RAM16(0x0008));
            RAM16_SET(0x0008, value8);
            a1 = 0xC0;
        }
        a3 = a1;
    } else {
        RAM16_SET(0x000A, (uint16_t)(((uint16_t)(value5 - value6) ^ 0xFFFF) + 1));
        uint16_t value10 = RAM16(0x0008);
        uint8_t a2;
        if (value10 & 0x8000) {
            RAM16_SET(0x0008, (uint16_t)((value10 ^ 0xFFFF) + 1));
            a2 = 0x80;
        } else {
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = 0x40;
            uint16_t value11 = RAM16(0x000A);
            RAM8(0x0000 + sp0 - 2) = value11 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)value11;
            RAM16_SET(0x000A, RAM16(0x0008));
            RAM16_SET(0x0008, value11);
            a2 = 0x40;
        }
        a3 = a2;
    }
    RAM16_SET(0x0000, a3);
    uint16_t value13 = RAM16(0x0008);
    uint16_t value14 = RAM16(0x000A);
    uint8_t a4;
    uint8_t a_hi1;
    if (value13 < value14) {
        a4 = (uint8_t)value13;
        a_hi1 = value13 >> 8;
    } else {
        RAM8(0x0000 + sp0) = value13 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value13;
        RAM16_SET(0x0008, RAM16(0x000A));
        RAM16_SET(0x000A, value13);
        RAM16_SET(0x0000, RAM16(0x0000) | 0x8000);
        uint16_t value17 = RAM16(0x0008);
        a4 = (uint8_t)value17;
        a_hi1 = value17 >> 8;
    }
    BUS16_SET(c, 0x004204, (uint16_t)(((a_hi1 << 8) | a4) << 4));
    uint8_t value18 = RAM8(0x000A);
    if (value18 >= 0x18) {
        BUS8_SET(c, 0x004206, value18);
        uint8_t a5;
        if ((value18 ^ 0xFF) >> 5 >= 3) {
            a5 = (value18 ^ 0xFF) >> 5;
        } else {
            a5 = 3;
        }
        RAM8(0x000A) = a5;
        uint8_t value19 = BUS8(c, 0x004214);
        uint8_t a6;
        if (value19 < 0x11) {
            a6 = value19;
        } else {
            a6 = 0x10;
        }
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint8_t value20 = RAM8(0x0003);
        if (value20 >= 0x20) {
            uint8_t value21 = BUS8(c, 0x019006 + a6);
            uint8_t value22 = RAM8(0x0001);
            uint8_t a7;
            if (!(value22 & 0x80)) {
                a7 = value21;
            } else {
                a7 = value21 ^ 0x3F;
            }
            uint8_t value23 = RAM8(0x0000);
            uint8_t value24 = RAM8(0x0002);
            if ((uint8_t)((a7 | value23) - value24) != 0) {
                if (!((uint8_t)((a7 | value23) - value24) & 0x80)) {
                    uint8_t a8;
                    bool carry1;
                    if ((uint8_t)((a7 | value23) - value24) < 5) {
                        a8 = (uint8_t)((a7 | value23) - value24);
                        carry1 = (uint8_t)((a7 | value23) - value24) >= 5;
                    } else {
                        a8 = RAM8(0x000A);
                        carry1 = 0;
                    }
                    RAM8(0x0002) = (uint8_t)(a8 + value24 + carry1);
                } else {
                    if ((uint8_t)((a7 | value23) - value24) >= 0xFB) {
                        RAM8(0x0002) = (uint8_t)((uint8_t)((a7 | value23) - value24) + value24);
                    } else {
                        RAM8(0x0002) = (uint8_t)(value24 - RAM8(0x000A));
                    }
                }
            }
        }
        BUS8_SET(c, 0x004202, value20);
        uint16_t value27 = RAM16(0x0002);
        RAM8(0x0000 + sp0 - 2) = y >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
        uint16_t value28 = RAM16(0x0001);
        uint16_t x1;
        uint16_t y1;
        if (!(value28 & 0x4000)) {
            x1 = (value27 & 0x3F) << 1 << 1 << 1;
            y1 = (((value27 & 0x3F) << 1 << 1 << 1) ^ 0x01FE) + 2;
        } else {
            RAM8(0x0000 + sp0 - 4) = (((value27 & 0x3F) << 1 << 1 << 1) ^ 0x01FE) + 2 >> 8;
            RAM8(0x0000 + sp0 - 5) = (uint8_t)((((value27 & 0x3F) << 1 << 1 << 1) ^ 0x01FE) + 2);
            RAM8(0x0000 + sp0 - 6) = (value27 & 0x3F) << 1 << 1 << 1 >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)((value27 & 0x3F) << 1 << 1 << 1);
            x1 = (((value27 & 0x3F) << 1 << 1 << 1) ^ 0x01FE) + 2;
            y1 = (value27 & 0x3F) << 1 << 1 << 1;
        }
        uint16_t value29 = BUS16(c, 0x00FD22 + x1);
        RAM16_SET(0x000A, value29 >> 1);
        uint16_t value30 = BUS16(c, 0x00FD22 + y1);
        BUS8_SET(c, 0x004203, (uint8_t)(value30 >> 1));
        uint8_t value31 = RAM8(0x0002);
        uint8_t a13;
        uint8_t a_hi6;
        if (!(value31 & 0x80)) {
            uint8_t a9;
            uint8_t a_hi2;
            if (!(value31 & 0x40)) {
                uint8_t value32 = BUS8(c, 0x004217);
                uint8_t value33 = RAM8(0x000C);
                RAM8(0x000C) = (uint8_t)(value32 + value33);
                a9 = (uint8_t)(value32 + value33) >> 3;
                a_hi2 = 0;
            } else {
                uint8_t value34 = BUS8(c, 0x004217);
                uint8_t value35 = RAM8(0x000C);
                RAM8(0x000C) = (uint8_t)(value34 + value35);
                a9 = (uint8_t)((((uint8_t)(value34 + value35) >> 3) ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)((((uint8_t)(value34 + value35) >> 3) ^ 0xFFFF) + 1) >> 8;
            }
            a13 = a9;
            a_hi6 = a_hi2;
        } else {
            uint8_t a12;
            uint8_t a_hi5;
            if (value31 & 0x40) {
                uint8_t value36 = BUS8(c, 0x004217);
                uint8_t value37 = RAM8(0x000C);
                RAM8(0x000C) = (uint8_t)(value36 + value37);
                a12 = (uint8_t)(value36 + value37) >> 3;
                a_hi5 = 0;
            } else {
                uint8_t a11;
                uint8_t a_hi4;
                if (!(value31 & 0x40)) {
                    uint8_t value38 = BUS8(c, 0x004217);
                    uint8_t value39 = RAM8(0x000C);
                    RAM8(0x000C) = (uint8_t)(value38 + value39);
                    a11 = (uint8_t)((((uint8_t)(value38 + value39) >> 3) ^ 0xFFFF) + 1);
                    a_hi4 = (uint16_t)((((uint8_t)(value38 + value39) >> 3) ^ 0xFFFF) + 1) >> 8;
                } else {
                    uint8_t a10;
                    uint8_t a_hi3;
                    if (!(value31 & 0x40)) {
                        uint8_t value40 = BUS8(c, 0x004217);
                        uint8_t value41 = RAM8(0x000C);
                        RAM8(0x000C) = (uint8_t)(value40 + value41);
                        a10 = (uint8_t)(value40 + value41) >> 3;
                        a_hi3 = 0;
                    } else {
                        uint8_t value42 = BUS8(c, 0x004217);
                        uint8_t value43 = RAM8(0x000C);
                        RAM8(0x000C) = (uint8_t)(value42 + value43);
                        a10 = (uint8_t)((((uint8_t)(value42 + value43) >> 3) ^ 0xFFFF) + 1);
                        a_hi3 = (uint16_t)((((uint8_t)(value42 + value43) >> 3) ^ 0xFFFF) + 1) >> 8;
                    }
                    a11 = a10;
                    a_hi4 = a_hi3;
                }
                a12 = a11;
                a_hi5 = a_hi4;
            }
            a13 = a12;
            a_hi6 = a_hi5;
        }
        RAM16_SET(0x0004, (a_hi6 << 8) | a13);
        BUS8_SET(c, 0x004203, RAM8(0x000A));
        uint8_t a14;
        uint8_t a_hi7;
        bool overflow1;
        if (!(value31 & 0x80)) {
            uint8_t value45 = BUS8(c, 0x004217);
            uint8_t value46 = RAM8(0x000D);
            RAM8(0x000D) = (uint8_t)(value45 + value46);
            a14 = (uint8_t)(value45 + value46) >> 3;
            a_hi7 = 0;
            overflow1 = ((value45 ^ (uint8_t)(value45 + value46)) & (value46 ^ (uint8_t)(value45 + value46)) & 0x80) != 0;
        } else {
            uint8_t value47 = BUS8(c, 0x004217);
            uint8_t value48 = RAM8(0x000D);
            RAM8(0x000D) = (uint8_t)(value47 + value48);
            a14 = (uint8_t)((((uint8_t)(value47 + value48) >> 3) ^ 0xFFFF) + 1);
            a_hi7 = (uint16_t)((((uint8_t)(value47 + value48) >> 3) ^ 0xFFFF) + 1) >> 8;
            overflow1 = ((value47 ^ (uint8_t)(value47 + value48)) & (value48 ^ (uint8_t)(value47 + value48)) & 0x80) != 0;
        }
        RAM16_SET(0x0006, (a_hi7 << 8) | a14);
        r->c = 1;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    r->c = 0;
    r->v = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18E93, SOM_RTS, "gen", steer_native_actor_effect_toward_target_with_fractional_sine_motion, 0, L_X | L_C | L_V, 8, 0, 0, 371, 198)
