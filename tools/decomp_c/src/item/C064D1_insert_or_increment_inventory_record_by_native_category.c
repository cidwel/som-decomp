#include "som_c.h"

/* C064D1 insert_or_increment_inventory_record_by_native_category   [class B, 195 bytes, 92 instructions]
 * Source: src/rom/insert_or_increment_inventory_record_by_native_category.s
 * Documented in docs/event-vm-inventory-command.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXY.
 */
static void insert_or_increment_inventory_record_by_native_category(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x1820);
    uint8_t a19;
    uint8_t a_hi13;
    uint16_t x18;
    uint16_t y16;
    if (value == 0) {
        a19 = 0;
        a_hi13 = a >> 8;
        x18 = x;
        y16 = 0;
    } else {
        uint8_t a18;
        uint8_t a_hi12;
        uint16_t x17;
        uint16_t y15;
        if (value == 0x15) {
            a18 = 0;
            a_hi12 = a >> 8;
            x17 = x;
            y15 = 0;
        } else {
            uint8_t a17;
            uint8_t a_hi11;
            uint16_t x16;
            uint16_t y14;
            if (value == 0x2A) {
                a17 = 0;
                a_hi11 = a >> 8;
                x16 = x;
                y14 = 0;
            } else {
                uint8_t a16;
                uint8_t a_hi10;
                uint16_t x15;
                uint16_t y13;
                if (value < 0x15) {
                    uint8_t a1 = value;
                    uint8_t a_hi1 = a >> 8;
                    uint16_t x1 = 0x24;
                    uint16_t y1 = 0;
                    for (;;) {
                        uint8_t value2 = RAM8(0xCC00 + x1);
                        uint8_t a2;
                        uint16_t x2;
                        uint16_t y2;
                        if (value2 == 0xFF) {
                            RAM8(0x0000 + sp0) = RAM8(0x1820);
                            RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                            RAM8(0xCC00 + x1) = RAM8(0x0000 + sp0);
                            a2 = 0;
                            x2 = x1;
                            y2 = y1;
                        } else {
                            if ((uint16_t)(y1 + 1) < 0x0B) {
                                a1 = value2;
                                x1 = (uint16_t)(x1 + 1);
                                y1 = (uint16_t)(y1 + 1);
                                continue;
                            }
                            a2 = 1;
                            x2 = (uint16_t)(x1 + 1);
                            y2 = (uint16_t)(y1 + 1);
                        }
                        a1 = a2;
                        x1 = x2;
                        y1 = y2;
                        break;
                    }
                    a16 = a1;
                    a_hi10 = a_hi1;
                    x15 = x1;
                    y13 = y1;
                } else {
                    uint8_t a15;
                    uint8_t a_hi9;
                    uint16_t x14;
                    uint16_t y12;
                    if (value < 0x2A) {
                        uint8_t a3 = value;
                        uint8_t a_hi2 = a >> 8;
                        uint16_t x3 = 0x30;
                        uint16_t y3 = 0;
                        for (;;) {
                            uint8_t value7 = RAM8(0xCC00 + x3);
                            uint8_t a4;
                            uint16_t x4;
                            uint16_t y4;
                            if (value7 == 0xFF) {
                                RAM8(0x0000 + sp0) = RAM8(0x1820);
                                RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                                RAM8(0xCC00 + x3) = RAM8(0x0000 + sp0);
                                a4 = 0;
                                x4 = x3;
                                y4 = y3;
                            } else {
                                if ((uint16_t)(y3 + 1) < 0x0B) {
                                    a3 = value7;
                                    x3 = (uint16_t)(x3 + 1);
                                    y3 = (uint16_t)(y3 + 1);
                                    continue;
                                }
                                a4 = 1;
                                x4 = (uint16_t)(x3 + 1);
                                y4 = (uint16_t)(y3 + 1);
                            }
                            a3 = a4;
                            x3 = x4;
                            y3 = y4;
                            break;
                        }
                        a15 = a3;
                        a_hi9 = a_hi2;
                        x14 = x3;
                        y12 = y3;
                    } else {
                        uint8_t a14;
                        uint8_t a_hi8;
                        uint16_t x13;
                        uint16_t y11;
                        if (value < 0x3F) {
                            uint8_t a5 = value;
                            uint8_t a_hi3 = a >> 8;
                            uint16_t x5 = 0x3C;
                            uint16_t y5 = 0;
                            for (;;) {
                                uint8_t value12 = RAM8(0xCC00 + x5);
                                uint8_t a6;
                                uint16_t x6;
                                uint16_t y6;
                                if (value12 == 0xFF) {
                                    RAM8(0x0000 + sp0) = RAM8(0x1820);
                                    RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                                    RAM8(0xCC00 + x5) = RAM8(0x0000 + sp0);
                                    a6 = 0;
                                    x6 = x5;
                                    y6 = y5;
                                } else {
                                    if ((uint16_t)(y5 + 1) < 0x0B) {
                                        a5 = value12;
                                        x5 = (uint16_t)(x5 + 1);
                                        y5 = (uint16_t)(y5 + 1);
                                        continue;
                                    }
                                    a6 = 1;
                                    x6 = (uint16_t)(x5 + 1);
                                    y6 = (uint16_t)(y5 + 1);
                                }
                                a5 = a6;
                                x5 = x6;
                                y5 = y6;
                                break;
                            }
                            a14 = a5;
                            a_hi8 = a_hi3;
                            x13 = x5;
                            y11 = y5;
                        } else {
                            RAM8(0x1820) = (uint8_t)(value - 0x40);
                            uint8_t a13;
                            uint8_t a_hi7;
                            uint16_t x12;
                            uint16_t y10;
                            if ((uint8_t)(value - 0x40) < 0x0C) {
                                uint8_t a7 = (uint8_t)(value - 0x40);
                                uint8_t a_hi4 = a >> 8;
                                uint16_t x7 = 0x48;
                                uint16_t y7 = 0;
                                for (;;) {
                                    RAM8(0x1821) = 0;
                                    uint8_t value17 = RAM8(0xCC00 + x7);
                                    uint8_t a10;
                                    uint16_t x9;
                                    uint16_t y9;
                                    if (value17 == 0xFF) {
                                        RAM8(0x0000 + sp0) = RAM8(0x1820) | 0x20;
                                        RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                                        RAM8(0xCC00 + x7) = RAM8(0x0000 + sp0);
                                        a10 = 0;
                                        x9 = x7;
                                        y9 = y7;
                                    } else {
                                        uint8_t value22 = RAM8(0x1820);
                                        uint8_t a9;
                                        uint16_t x8;
                                        uint16_t y8;
                                        if ((value17 & 0x1F) == value22) {
                                            uint8_t a8;
                                            if ((uint8_t)(value17 + 0x20) >= 0x9F) {
                                                a8 = 2;
                                            } else {
                                                RAM8(0x0000 + sp0) = (uint8_t)(value17 + 0x20);
                                                RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                                                RAM8(0xCC00 + x7) = RAM8(0x0000 + sp0);
                                                a8 = 0;
                                            }
                                            a9 = a8;
                                            x8 = x7;
                                            y8 = y7;
                                        } else {
                                            if ((uint16_t)(y7 + 1) < 0x0C) {
                                                a7 = value17 & 0x1F;
                                                x7 = (uint16_t)(x7 + 1);
                                                y7 = (uint16_t)(y7 + 1);
                                                continue;
                                            }
                                            a9 = 2;
                                            x8 = (uint16_t)(x7 + 1);
                                            y8 = (uint16_t)(y7 + 1);
                                        }
                                        a10 = a9;
                                        x9 = x8;
                                        y9 = y8;
                                    }
                                    a7 = a10;
                                    x7 = x9;
                                    y7 = y9;
                                    break;
                                }
                                a13 = a7;
                                a_hi7 = a_hi4;
                                x12 = x7;
                                y10 = y7;
                            } else {
                                RAM8(0x1820) = (uint8_t)(value - 0x80);
                                uint8_t a_hi6;
                                uint16_t x11;
                                if ((uint8_t)(value - 0x80) < 0x48) {
                                    uint8_t a11 = (uint8_t)(value - 0x80);
                                    uint8_t a_hi5 = a >> 8;
                                    uint16_t x10 = 0x54;
                                    for (;;) {
                                        if (!((uint8_t)(a11 - 9) & 0x80)) {
                                            a11 = (uint8_t)(a11 - 9);
                                            x10 = (uint16_t)(x10 + 1);
                                            continue;
                                        }
                                        a11 = (uint8_t)(a11 - 9);
                                        break;
                                    }
                                    RAM8(0x1820) = (uint8_t)(a11 + 9);
                                    uint8_t value26 = RAM8(0xCC00 + x10);
                                    uint8_t a12;
                                    if (value26 == 0xFF) {
                                        a12 = RAM8(0x1820);
                                    } else {
                                        a12 = (value26 & 0xC0) | RAM8(0x1820);
                                    }
                                    RAM8(0x0000 + sp0) = a12;
                                    RAM8(0x0000 + sp0) = (uint8_t)(RAM8(0x1821) << 6) | RAM8(0x0000 + sp0);
                                    RAM8(0xCC00 + x10) = RAM8(0x0000 + sp0);
                                    a_hi6 = a_hi5;
                                    x11 = x10;
                                } else {
                                    a_hi6 = a >> 8;
                                    x11 = 0x54;
                                }
                                a13 = 0;
                                a_hi7 = a_hi6;
                                x12 = x11;
                                y10 = 0;
                            }
                            a14 = a13;
                            a_hi8 = a_hi7;
                            x13 = x12;
                            y11 = y10;
                        }
                        a15 = a14;
                        a_hi9 = a_hi8;
                        x14 = x13;
                        y12 = y11;
                    }
                    a16 = a15;
                    a_hi10 = a_hi9;
                    x15 = x14;
                    y13 = y12;
                }
                a17 = a16;
                a_hi11 = a_hi10;
                x16 = x15;
                y14 = y13;
            }
            a18 = a17;
            a_hi12 = a_hi11;
            x17 = x16;
            y15 = y14;
        }
        a19 = a18;
        a_hi13 = a_hi12;
        x18 = x17;
        y16 = y15;
    }
    RAM8(0xCF0F) = a19;
    r->a = (a_hi13 << 8) | a19;
    r->x = x18;
    r->y = y16;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC064D1, SOM_RTS, "gen", insert_or_increment_inventory_record_by_native_category, 0, L_A | L_B | L_X | L_Y, 1, 0, 0, 195, 92)
