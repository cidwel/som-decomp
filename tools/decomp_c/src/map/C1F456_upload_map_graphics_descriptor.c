#include "som_c.h"

/* C1F456 upload_map_graphics_descriptor   [class D, 376 bytes, 195 instructions]
 * Source: src/rom/upload_map_graphics_descriptor.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXV.
 */
static void upload_map_graphics_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y, value);
    RAM8(0x0009) = 0;
    RAM8(0x0008) = (uint8_t)(value + 1);
    if ((uint8_t)(value + 1) == 0) {
        RAM8(0x0009)++;
    }
    RAM8(0x0004) = 0;
    uint16_t x3;
    if (((a >> 8) & 0xE0) >= 0x80) {
        uint16_t x2;
        if (((a >> 8) & 0xE0) >= 0xC0) {
            uint16_t x1;
            if (((a >> 8) & 0xE0) != 0xC0) {
                x1 = 9;
            } else {
                x1 = 6;
            }
            x2 = x1;
        } else {
            uint8_t a1;
            if (((a >> 8) & 0x20) == 0) {
                a1 = (a >> 8) & 0x20;
            } else {
                a1 = 0xFF;
            }
            RAM8(0x0000) = a1;
            x2 = 3;
        }
        x3 = x2;
    } else {
        uint8_t a2;
        if (((a >> 8) & 0x40) == 0) {
            a2 = (a >> 8) & 0x40;
        } else {
            a2 = 0xFF;
        }
        RAM8(0x0000) = a2;
        uint8_t a3;
        if (((a >> 8) & 0x20) == 0) {
            a3 = (a >> 8) & 0x20;
        } else {
            a3 = 0xFF;
        }
        RAM8(0x0001) = a3;
        x3 = 0;
    }
    if (x3 != 9) {
        if (x3 != 6) {
            if (x3 != 0) {
                RAM16_SET(0x0004, (a & 0x1FFF) << 1 << 1 << 1);
                RAM8(0x0006) = (a & 0x1FFF) << 1 << 1 << 1 >> 0x0F;
                uint16_t value2 = RAM16(0x0004);
                bool carry1;
                if ((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2 <= 0xFFFF) {
                    carry1 = (uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2 > 0xFFFF;
                } else {
                    RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                    carry1 = 0;
                }
                uint16_t value3;
                BUS16_OK(c, 0xCCE270 + x3, value3);
                RAM16_SET(0x0004, 0);
                uint8_t value4;
                BUS8_OK(c, 0xCCE272 + x3, value4);
                uint8_t value5 = RAM8(0x0006);
                RAM8(0x0006) = (uint8_t)((value4 | 0xC0) + value5 + ((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1 > 0xFFFF));
                uint8_t a4 = (uint8_t)((value4 | 0xC0) + value5 + ((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1 > 0xFFFF));
                uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1) >> 8;
                uint16_t x4 = x3;
                uint16_t y1 = (uint16_t)((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1);
                do {
                    uint8_t a_hi2 = a_hi1;
                    uint16_t x5 = 8;
                    uint16_t y2 = y1;
                    for (;;) {
                        uint16_t value6;
                        BUS16_OK(c, (RAM8(0x0006) << 0x10) + RAM16(0x0004) + y2, value6);
                        BUS16_SET(c, 0x002118, value6);
                        if ((uint16_t)(y2 + 1) == 0) {
                            RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                        }
                        if ((uint16_t)(y2 + 2) == 0) {
                            RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                        }
                        a_hi2 = value6 >> 8;
                        x5 = (uint16_t)(x5 - 1);
                        y2 = (uint16_t)(y2 + 2);
                        if (!(x5 != 0)) break;
                    }
                    uint8_t value7 = RAM8(0x0000);
                    uint8_t a5 = a_hi2;
                    uint8_t a_hi3 = value7;
                    uint16_t x6 = 8;
                    uint16_t y3 = y2;
                    bool first_pass = true;
                    for (;;) {
                        if (first_pass) {
                            uint8_t value8;
                            BUS8_OK(c, (RAM8(0x0006) << 0x10) + RAM16(0x0004) + y3, value8);
                            BUS16_SET(c, 0x002118, (a_hi3 << 8) | value8);
                            if ((uint16_t)(y3 + 1) == 0) {
                                RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                            }
                            if ((uint16_t)(x6 - 1) != 0) {
                                a5 = value8;
                                x6 = (uint16_t)(x6 - 1);
                                y3 = (uint16_t)(y3 + 1);
                                first_pass = false;
                                continue;
                            }
                            a5 = value8;
                            x6 = (uint16_t)(x6 - 1);
                            y3 = (uint16_t)(y3 + 1);
                            break;
                        } else {
                            uint8_t value9;
                            BUS8_OK(c, (RAM8(0x0006) << 0x10) + RAM16(0x0004) + y3, value9);
                            BUS16_SET(c, 0x002118, (a_hi3 << 8) | value9);
                            if ((uint16_t)(y3 + 1) == 0) {
                                RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                            }
                            if ((uint16_t)(x6 - 1) != 0) {
                                a5 = value9;
                                x6 = (uint16_t)(x6 - 1);
                                y3 = (uint16_t)(y3 + 1);
                                continue;
                            }
                            a5 = value9;
                            x6 = (uint16_t)(x6 - 1);
                            y3 = (uint16_t)(y3 + 1);
                            break;
                        }
                    }
                    RAM16_SET(0x0008, (uint16_t)(RAM16(0x0008) - 1));
                    a4 = a5;
                    a_hi1 = a_hi3;
                    x4 = x6;
                    y1 = y3;
                } while (RAM16(0x0008) != 0);
                r->a = (a_hi1 << 8) | a4;
                r->x = x4;
                r->v = (((value4 | 0xC0) ^ (uint8_t)((value4 | 0xC0) + value5 + ((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1 > 0xFFFF))) & (value5 ^ (uint8_t)((value4 | 0xC0) + value5 + ((uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value2) + value3 + carry1 > 0xFFFF))) & 0x80) != 0;
                RETURN_RTS(c);
            }
            uint16_t value10;
            BUS16_OK(c, 0xCCE270 + x3, value10);
            RAM16_SET(0x0004, 0);
            uint8_t value11;
            BUS8_OK(c, 0xCCE272 + x3, value11);
            RAM8(0x0006) = (uint8_t)((value11 | 0xC0) + ((a & 0x1FFF) << 1 << 1 << 1 >> 0x0F));
            uint8_t a6 = (uint8_t)((value11 | 0xC0) + ((a & 0x1FFF) << 1 << 1 << 1 >> 0x0F));
            uint8_t a_hi4 = (uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value10) >> 8;
            uint16_t x7 = x3;
            uint16_t y4 = (uint16_t)((uint16_t)((a & 0x1FFF) << 1 << 1 << 1 << 1) + value10);
            do {
                uint8_t a_hi5 = a_hi4;
                uint16_t x8 = 8;
                uint16_t y5 = y4;
                for (;;) {
                    uint16_t value12;
                    BUS16_OK(c, (RAM8(0x0006) << 0x10) + RAM16(0x0004) + y5, value12);
                    BUS16_SET(c, 0x002118, value12);
                    if ((uint16_t)(y5 + 1) == 0) {
                        RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                    }
                    if ((uint16_t)(y5 + 2) == 0) {
                        RAM16_SET(0x0006, (uint16_t)(RAM16(0x0006) + 1));
                    }
                    a_hi5 = value12 >> 8;
                    x8 = (uint16_t)(x8 - 1);
                    y5 = (uint16_t)(y5 + 2);
                    if (!(x8 != 0)) break;
                }
                uint16_t value13 = RAM16(0x0000);
                uint16_t x9 = 8;
                for (;;) {
                    BUS16_SET(c, 0x002118, value13);
                    x9 = (uint16_t)(x9 - 1);
                    if (!(x9 != 0)) break;
                }
                RAM16_SET(0x0008, (uint16_t)(RAM16(0x0008) - 1));
                a6 = (uint8_t)value13;
                a_hi4 = value13 >> 8;
                x7 = x9;
                y4 = y5;
            } while (RAM16(0x0008) != 0);
            r->a = (a_hi4 << 8) | a6;
            r->x = x7;
            r->v = (((value11 | 0xC0) ^ (uint8_t)((value11 | 0xC0) + ((a & 0x1FFF) << 1 << 1 << 1 >> 0x0F))) & (uint8_t)((value11 | 0xC0) + ((a & 0x1FFF) << 1 << 1 << 1 >> 0x0F)) & 0x80) != 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x0003, 0);
        RAM16_SET(0x0003, (RAM16(0x0003) >> 1) | ((a & 1) << 0x0F));
        RAM16_SET(0x0003, (RAM16(0x0003) >> 1) | (((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) & 1) << 0x0F));
        RAM16_SET(0x0003, (RAM16(0x0003) >> 1) | (((((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 9 << 8) | (uint8_t)((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 1)) & 1) << 0x0F));
        RAM16_SET(0x0005, ((((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 9 << 8) | (uint8_t)((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 1)) >> 9 << 8) | (uint8_t)((((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 9 << 8) | (uint8_t)((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 1)) >> 1));
        BUS16_SET(c, 0x004375, (uint16_t)(RAM16(0x0008) << 5));
        uint16_t value18;
        BUS16_OK(c, 0xCCE270 + x3, value18);
        uint16_t value19 = RAM16(0x0004);
        BUS16_SET(c, 0x004372, (uint16_t)(value18 + value19));
        uint8_t value20;
        BUS8_OK(c, 0xCCE272 + x3, value20);
        BUS8_SET(c, 0x004374, (uint8_t)((value20 | 0xC0) + RAM8(0x0006) + (value18 + value19 > 0xFFFF)));
        uint16_t value22 = BUS16(c, 0x004372);
        uint16_t value23 = BUS16(c, 0x004375);
        if (value22 + value23 > 0xFFFF) {
            if ((uint16_t)(value22 + value23) != 0) {
                uint8_t value24 = BUS8(c, 0x004374);
                uint16_t value25 = BUS16(c, 0x004372);
                BUS16_SET(c, 0x004375, (uint16_t)((value25 ^ 0xFFFF) + 1));
                BUS8_SET(c, 0x00420B, 0x80);
                BUS8_SET(c, 0x004374, (uint8_t)(value24 + 1));
                BUS16_SET(c, 0x004375, (uint16_t)(value22 + value23));
            }
        }
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = ((uint16_t)(value22 + value23) >> 8 << 8) | 0x80;
        r->x = x3;
        r->v = ((value22 ^ (uint16_t)(value22 + value23)) & (value23 ^ (uint16_t)(value22 + value23)) & 0x8000) != 0;
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0003, 0);
    RAM16_SET(0x0003, (RAM16(0x0003) >> 1) | ((a & 1) << 0x0F));
    RAM16_SET(0x0003, (RAM16(0x0003) >> 1) | (((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) & 1) << 0x0F));
    RAM16_SET(0x0005, ((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 9 << 8) | (uint8_t)((((a & 0x1FFF) >> 9 << 8) | (uint8_t)((a & 0x1FFF) >> 1)) >> 1));
    BUS16_SET(c, 0x004375, (uint16_t)(RAM16(0x0008) << 6));
    uint16_t value29;
    BUS16_OK(c, 0xCCE270 + x3, value29);
    uint16_t value30 = RAM16(0x0004);
    BUS16_SET(c, 0x004372, (uint16_t)(value29 + value30));
    uint8_t value31;
    BUS8_OK(c, 0xCCE272 + x3, value31);
    BUS8_SET(c, 0x004374, (uint8_t)((value31 | 0xC0) + RAM8(0x0006) + (value29 + value30 > 0xFFFF)));
    uint16_t value33 = BUS16(c, 0x004372);
    uint16_t value34 = BUS16(c, 0x004375);
    if (value33 + value34 > 0xFFFF) {
        if ((uint16_t)(value33 + value34) != 0) {
            uint8_t value35 = BUS8(c, 0x004374);
            uint16_t value36 = BUS16(c, 0x004372);
            BUS16_SET(c, 0x004375, (uint16_t)((value36 ^ 0xFFFF) + 1));
            BUS8_SET(c, 0x00420B, 0x80);
            BUS8_SET(c, 0x004374, (uint8_t)(value35 + 1));
            BUS16_SET(c, 0x004375, (uint16_t)(value33 + value34));
        }
    }
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = ((uint16_t)(value33 + value34) >> 8 << 8) | 0x80;
    r->x = x3;
    r->v = ((value33 ^ (uint16_t)(value33 + value34)) & (value34 ^ (uint16_t)(value33 + value34)) & 0x8000) != 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F456, SOM_RTS, "hand", upload_map_graphics_descriptor, 0, L_A | L_B | L_X | L_V, 3, 0, 0, 376, 195)
