#include "som_c.h"

/* C09476 permute_native_controller_button_bits   [class C, 166 bytes, 94 instructions]
 * Source: src/rom/permute_native_controller_button_bits.s
 * Documented in docs/game-controller-mapping.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: AXYV.
 */
static void permute_native_controller_button_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0002) = a;
    uint8_t y1;
    if ((x & 0xC0) == 0) {
        y1 = y;
    } else {
        RAM8(0x0003) = x & 0xC0;
        uint8_t value = RAM8(0x0002);
        uint8_t value2 = RAM8(0x0003);
        RAM8(0x0003) = (y ^ value) & value2;
        RAM8(0x0002) = ((y ^ value) & value2) ^ value;
        y1 = (uint8_t)((a_hi << 8) | (y ^ RAM8(0x0003)));
    }
    uint8_t y8;
    if ((x & 0x30) == 0) {
        y8 = y1;
    } else {
        uint8_t y7;
        if ((x & 0x20) == 0) {
            uint8_t y3;
            if ((y1 & 0xC0) == 0) {
                y3 = y1;
            } else {
                uint8_t y2;
                if ((y1 & 0xC0) == 0xC0) {
                    y2 = y1;
                } else {
                    y2 = (uint8_t)((a_hi << 8) | (y1 ^ 0xC0));
                }
                y3 = y2;
            }
            y7 = y3;
        } else {
            uint8_t value4 = RAM8(0x0002);
            if ((value4 & 0xC0) != 0) {
                if ((value4 & 0xC0) != 0xC0) {
                    RAM8(0x0002) = value4 ^ 0xC0;
                }
            }
            uint8_t y6;
            if ((x & 0x10) == 0) {
                y6 = y1;
            } else {
                uint8_t y5;
                if ((y1 & 0xC0) == 0) {
                    y5 = y1;
                } else {
                    uint8_t y4;
                    if ((y1 & 0xC0) == 0xC0) {
                        y4 = y1;
                    } else {
                        y4 = (uint8_t)((a_hi << 8) | (y1 ^ 0xC0));
                    }
                    y5 = y4;
                }
                y6 = y5;
            }
            y7 = y6;
        }
        y8 = y7;
    }
    uint8_t y26;
    bool overflow3;
    if ((x & 0x0C) == 0) {
        y26 = y8;
        overflow3 = overflow;
    } else {
        uint8_t y25;
        bool overflow2;
        if ((x & 8) == 0) {
            uint8_t value5 = RAM8(0x0002);
            uint8_t y13;
            if ((value5 & 0x40) == 0) {
                uint8_t y9;
                if (!(y8 & 0x80)) {
                    y9 = y8;
                } else {
                    RAM8(0x0002) = value5 ^ 0x40;
                    y9 = (uint8_t)((a_hi << 8) | (y8 ^ 0x80));
                }
                y13 = y9;
            } else {
                uint8_t y12;
                if (y8 & 0x80) {
                    y12 = y8;
                } else {
                    uint8_t y11;
                    if (!(y8 & 0x80)) {
                        RAM8(0x0002) = value5 ^ 0x40;
                        y11 = (uint8_t)((a_hi << 8) | (y8 ^ 0x80));
                    } else {
                        uint8_t y10;
                        if (!(y8 & 0x80)) {
                            y10 = y8;
                        } else {
                            RAM8(0x0002) = value5 ^ 0x40;
                            y10 = (uint8_t)((a_hi << 8) | (y8 ^ 0x80));
                        }
                        y11 = y10;
                    }
                    y12 = y11;
                }
                y13 = y12;
            }
            y25 = y13;
            overflow2 = overflow;
        } else {
            uint8_t y18;
            bool overflow1;
            if ((y8 & 0x40) == 0) {
                uint8_t value6 = RAM8(0x0002);
                uint8_t y14;
                if (!(value6 & 0x80)) {
                    y14 = y8;
                } else {
                    RAM8(0x0002) = value6 ^ 0x80;
                    y14 = (uint8_t)((a_hi << 8) | (y8 ^ 0x40));
                }
                y18 = y14;
                overflow1 = value6 & 0x40;
            } else {
                uint8_t value7 = RAM8(0x0002);
                uint8_t y17;
                if (value7 & 0x80) {
                    y17 = y8;
                } else {
                    uint8_t y16;
                    if (!(value7 & 0x80)) {
                        RAM8(0x0002) = value7 ^ 0x80;
                        y16 = (uint8_t)((a_hi << 8) | (y8 ^ 0x40));
                    } else {
                        uint8_t y15;
                        if (!(value7 & 0x80)) {
                            y15 = y8;
                        } else {
                            RAM8(0x0002) = value7 ^ 0x80;
                            y15 = (uint8_t)((a_hi << 8) | (y8 ^ 0x40));
                        }
                        y16 = y15;
                    }
                    y17 = y16;
                }
                y18 = y17;
                overflow1 = value7 & 0x40;
            }
            uint8_t y24;
            if ((x & 4) == 0) {
                y24 = y18;
            } else {
                uint8_t value8 = RAM8(0x0002);
                uint8_t y23;
                if ((value8 & 0x40) == 0) {
                    uint8_t y19;
                    if (!(y18 & 0x80)) {
                        y19 = y18;
                    } else {
                        RAM8(0x0002) = value8 ^ 0x40;
                        y19 = (uint8_t)((a_hi << 8) | (y18 ^ 0x80));
                    }
                    y23 = y19;
                } else {
                    uint8_t y22;
                    if (y18 & 0x80) {
                        y22 = y18;
                    } else {
                        uint8_t y21;
                        if (!(y18 & 0x80)) {
                            RAM8(0x0002) = value8 ^ 0x40;
                            y21 = (uint8_t)((a_hi << 8) | (y18 ^ 0x80));
                        } else {
                            uint8_t y20;
                            if (!(y18 & 0x80)) {
                                y20 = y18;
                            } else {
                                RAM8(0x0002) = value8 ^ 0x40;
                                y20 = (uint8_t)((a_hi << 8) | (y18 ^ 0x80));
                            }
                            y21 = y20;
                        }
                        y22 = y21;
                    }
                    y23 = y22;
                }
                y24 = y23;
            }
            y25 = y24;
            overflow2 = overflow1;
        }
        y26 = y25;
        overflow3 = overflow2;
    }
    if ((x & 3) != 0) {
        if (x & 3 & 0x01) {
            uint8_t value9 = RAM8(0x0002);
            if ((value9 & 3) != 0) {
                RAM8(0x0002) = value9 ^ 3;
            }
        }
        if ((x & 2) != 0) {
            uint8_t value10 = RAM8(0x0002);
            if ((value10 & 0x0C) != 0) {
                RAM8(0x0002) = value10 ^ 0x0C;
            }
        }
    }
    SET_A8(r, RAM8(0x0002));
    r->y = y26;
    r->v = overflow3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09476, SOM_RTS, "gen", permute_native_controller_button_bits, 0, L_A | L_X | L_Y | L_V, 1, 1, 1, 166, 94)
