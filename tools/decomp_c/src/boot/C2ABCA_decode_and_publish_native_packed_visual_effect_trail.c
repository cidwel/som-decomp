#include "som_c.h"

/* C2ABCA decode_and_publish_native_packed_visual_effect_trail   [class B, 222 bytes, 116 instructions]
 * Source: src/rom/decode_and_publish_native_packed_visual_effect_trail.s
 * Documented in docs/actor-visual-effect-point-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void decode_and_publish_native_packed_visual_effect_trail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM8(0x0004) = 0x0A;
    uint16_t value = BUS16_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010), RAM8(0x0012));
    RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) + 1));
    RAM16_SET(0xE114 + x, value & 0x3F);
    uint8_t a_hi1 = x >> 1 >> 8;
    uint16_t x1 = x >> 1;
    uint16_t y1 = value & 0x3F;
    bool carry1 = x & 0x01;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint16_t value2 = BUS16_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010), RAM8(0x0012));
            RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) + 1));
            RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) + 1));
            RAM8(0x0001) = (RAM8(0x0001) >> 1) | (value2 >> 0x0F << 7);
            RAM8(0x0001) = (RAM8(0x0001) >> 1) | ((uint8_t)value2 >> 7 << 7);
            uint8_t a8;
            if ((uint8_t)((uint8_t)value2 << 1) < 0x80) {
                uint8_t value5 = RAM8(0x0005);
                uint8_t a1;
                if (value5 & 0x40) {
                    a1 = (uint8_t)((uint8_t)value2 << 1);
                } else {
                    a1 = (uint8_t)((uint8_t)value2 << 1) >> 1;
                }
                uint8_t value6 = RAM8(0x000B);
                uint8_t value7 = RAM8(0x0002);
                uint8_t a2;
                if (!(value7 & 0x80)) {
                    a2 = (uint8_t)(a1 + value6);
                } else {
                    a2 = (uint8_t)((uint8_t)(a1 + value6) + 0x0F) ^ 0xFF;
                }
                a8 = a2;
            } else {
                uint8_t value8 = RAM8(0x0005);
                uint8_t a3;
                if (value8 & 0x40) {
                    a3 = (uint8_t)((uint8_t)value2 << 1);
                } else {
                    a3 = ((uint8_t)((uint8_t)value2 << 1) >> 1) | (((uint8_t)((uint8_t)value2 << 1) >= 0x80) << 7);
                }
                uint8_t value9 = RAM8(0x000B);
                uint8_t value10 = RAM8(0x0002);
                uint8_t a7;
                if (value10 & 0x80) {
                    a7 = (uint8_t)((uint8_t)(a3 + value9) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a6;
                    if (!(value10 & 0x80)) {
                        a6 = (uint8_t)(a3 + value9);
                    } else {
                        uint8_t a4;
                        if (value8 & 0x40) {
                            a4 = (uint8_t)(a3 + value9);
                        } else {
                            a4 = (uint8_t)(a3 + value9) >> 1;
                        }
                        uint8_t a5;
                        if (!(value10 & 0x80)) {
                            a5 = (uint8_t)(a4 + value9);
                        } else {
                            a5 = (uint8_t)((uint8_t)(a4 + value9) + 0x0F) ^ 0xFF;
                        }
                        a6 = a5;
                    }
                    a7 = a6;
                }
                a8 = a7;
            }
            uint8_t a16;
            if (!((uint8_t)(value2 >> 8 << 1) & 0x80)) {
                uint8_t value11 = RAM8(0x0005);
                uint8_t a9;
                if (value11 & 0x40) {
                    a9 = (uint8_t)(value2 >> 8 << 1);
                } else {
                    a9 = (uint8_t)(value2 >> 8 << 1) >> 1;
                }
                uint8_t value12 = RAM8(0x000A);
                uint8_t value13 = RAM8(0x0002);
                uint8_t a10;
                if (!(value13 & 0x40)) {
                    a10 = (uint8_t)(a9 + value12);
                } else {
                    a10 = (uint8_t)((uint8_t)(a9 + value12) + 0x0F) ^ 0xFF;
                }
                a16 = a10;
            } else {
                uint8_t value14 = RAM8(0x0005);
                uint8_t a11;
                if (value14 & 0x40) {
                    a11 = (uint8_t)(value2 >> 8 << 1);
                } else {
                    a11 = ((uint8_t)(value2 >> 8 << 1) >> 1) | 0x80;
                }
                uint8_t value15 = RAM8(0x000A);
                uint8_t value16 = RAM8(0x0002);
                uint8_t a15;
                if (value16 & 0x40) {
                    a15 = (uint8_t)((uint8_t)(a11 + value15) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a14;
                    if (!(value16 & 0x40)) {
                        a14 = (uint8_t)(a11 + value15);
                    } else {
                        uint8_t a12;
                        if (value14 & 0x40) {
                            a12 = (uint8_t)(a11 + value15);
                        } else {
                            a12 = (uint8_t)(a11 + value15) >> 1;
                        }
                        uint8_t a13;
                        if (!(value16 & 0x40)) {
                            a13 = (uint8_t)(a12 + value15);
                        } else {
                            a13 = (uint8_t)((uint8_t)(a12 + value15) + 0x0F) ^ 0xFF;
                        }
                        a14 = a13;
                    }
                    a15 = a14;
                }
                a16 = a15;
            }
            RAM16_SET(0xC000 + x1, (a8 << 8) | a16);
            RAM8(0xC003 + x1) = ((RAM8(0x0001) ^ RAM8(0x0002)) & 0xC0) | RAM8(0x000D);
            uint8_t value20 = RAM8(0x000C);
            RAM8(0xC002 + x1) = value20;
            uint8_t a17;
            bool carry2;
            bool overflow2;
            if (((uint8_t)(value20 + 2) & 0x10) == 0) {
                a17 = (uint8_t)(value20 + 2);
                carry2 = value20 + 2 > 0xFF;
                overflow2 = ((value20 ^ (uint8_t)(value20 + 2)) & ((uint8_t)(value20 + 2) ^ 2) & 0x80) != 0;
            } else {
                if ((uint8_t)(value20 + 2) + 0x10 + (value20 + 2 > 0xFF) > 0xFF) {
                    RAM8(0x000D)++;
                }
                a17 = (uint8_t)((uint8_t)(value20 + 2) + 0x10 + (value20 + 2 > 0xFF));
                carry2 = (uint8_t)(value20 + 2) + 0x10 + (value20 + 2 > 0xFF) > 0xFF;
                overflow2 = (((uint8_t)(value20 + 2) ^ (uint8_t)((uint8_t)(value20 + 2) + 0x10 + (value20 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value20 + 2) + 0x10 + (value20 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
            }
            RAM8(0x000C) = a17;
            RAM8(0x0004)--;
            uint8_t a_hi3;
            bool carry4;
            bool overflow4;
            if (RAM8(0x0004) != 0) {
                a_hi3 = a8;
                carry4 = carry2;
                overflow4 = overflow2;
            } else {
                RAM8(0x0004) = 0x0A;
                uint16_t value21 = RAM16(0x000C);
                uint8_t a18;
                uint8_t a_hi2;
                bool carry3;
                bool overflow3;
                if (((uint16_t)(value21 - 0x24) & 0x10) == 0) {
                    a18 = (uint8_t)(value21 - 0x24);
                    a_hi2 = (uint16_t)(value21 - 0x24) >> 8;
                    carry3 = value21 >= 0x24;
                    overflow3 = ((value21 ^ 0x24) & (value21 ^ (uint16_t)(value21 - 0x24)) & 0x8000) != 0;
                } else {
                    a18 = (uint8_t)((uint16_t)(value21 - 0x24) - 0x10 - (value21 >= 0x24 ^ 1));
                    a_hi2 = (uint16_t)((uint16_t)(value21 - 0x24) - 0x10 - (value21 >= 0x24 ^ 1)) >> 8;
                    carry3 = (uint16_t)(value21 - 0x24) - 0x10 >= (value21 >= 0x24 ^ 1);
                    overflow3 = (((uint16_t)(value21 - 0x24) ^ 0x10) & ((uint16_t)(value21 - 0x24) ^ (uint16_t)((uint16_t)(value21 - 0x24) - 0x10 - (value21 >= 0x24 ^ 1))) & 0x8000) != 0;
                }
                RAM16_SET(0x000C, (a_hi2 << 8) | a18);
                a_hi3 = a_hi2;
                carry4 = carry3;
                overflow4 = overflow3;
            }
            if ((uint16_t)(y1 - 1) != 0) {
                a_hi1 = a_hi3;
                x1 = (uint16_t)(x1 + 4);
                y1 = (uint16_t)(y1 - 1);
                carry1 = carry4;
                overflow1 = overflow4;
                first_pass = false;
                continue;
            }
            a_hi1 = a_hi3;
            x1 = (uint16_t)(x1 + 4);
            y1 = (uint16_t)(y1 - 1);
            carry1 = carry4;
            overflow1 = overflow4;
            break;
        } else {
            uint16_t value22 = BUS16_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010), RAM8(0x0012));
            RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) + 1));
            RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) + 1));
            RAM8(0x0001) = (RAM8(0x0001) >> 1) | (value22 >> 0x0F << 7);
            RAM8(0x0001) = (RAM8(0x0001) >> 1) | ((uint8_t)value22 >> 7 << 7);
            uint8_t a26;
            if ((uint8_t)((uint8_t)value22 << 1) < 0x80) {
                uint8_t value25 = RAM8(0x0005);
                uint8_t a19;
                if (value25 & 0x40) {
                    a19 = (uint8_t)((uint8_t)value22 << 1);
                } else {
                    a19 = (uint8_t)((uint8_t)value22 << 1) >> 1;
                }
                uint8_t value26 = RAM8(0x000B);
                uint8_t value27 = RAM8(0x0002);
                uint8_t a20;
                if (!(value27 & 0x80)) {
                    a20 = (uint8_t)(a19 + value26);
                } else {
                    a20 = (uint8_t)((uint8_t)(a19 + value26) + 0x0F) ^ 0xFF;
                }
                a26 = a20;
            } else {
                uint8_t value28 = RAM8(0x0005);
                uint8_t a21;
                if (value28 & 0x40) {
                    a21 = (uint8_t)((uint8_t)value22 << 1);
                } else {
                    a21 = ((uint8_t)((uint8_t)value22 << 1) >> 1) | (((uint8_t)((uint8_t)value22 << 1) >= 0x80) << 7);
                }
                uint8_t value29 = RAM8(0x000B);
                uint8_t value30 = RAM8(0x0002);
                uint8_t a25;
                if (value30 & 0x80) {
                    a25 = (uint8_t)((uint8_t)(a21 + value29) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a24;
                    if (!(value30 & 0x80)) {
                        a24 = (uint8_t)(a21 + value29);
                    } else {
                        uint8_t a22;
                        if (value28 & 0x40) {
                            a22 = (uint8_t)(a21 + value29);
                        } else {
                            a22 = (uint8_t)(a21 + value29) >> 1;
                        }
                        uint8_t a23;
                        if (!(value30 & 0x80)) {
                            a23 = (uint8_t)(a22 + value29);
                        } else {
                            a23 = (uint8_t)((uint8_t)(a22 + value29) + 0x0F) ^ 0xFF;
                        }
                        a24 = a23;
                    }
                    a25 = a24;
                }
                a26 = a25;
            }
            uint8_t a34;
            if (!((uint8_t)(value22 >> 8 << 1) & 0x80)) {
                uint8_t value31 = RAM8(0x0005);
                uint8_t a27;
                if (value31 & 0x40) {
                    a27 = (uint8_t)(value22 >> 8 << 1);
                } else {
                    a27 = (uint8_t)(value22 >> 8 << 1) >> 1;
                }
                uint8_t value32 = RAM8(0x000A);
                uint8_t value33 = RAM8(0x0002);
                uint8_t a28;
                if (!(value33 & 0x40)) {
                    a28 = (uint8_t)(a27 + value32);
                } else {
                    a28 = (uint8_t)((uint8_t)(a27 + value32) + 0x0F) ^ 0xFF;
                }
                a34 = a28;
            } else {
                uint8_t value34 = RAM8(0x0005);
                uint8_t a29;
                if (value34 & 0x40) {
                    a29 = (uint8_t)(value22 >> 8 << 1);
                } else {
                    a29 = ((uint8_t)(value22 >> 8 << 1) >> 1) | 0x80;
                }
                uint8_t value35 = RAM8(0x000A);
                uint8_t value36 = RAM8(0x0002);
                uint8_t a33;
                if (value36 & 0x40) {
                    a33 = (uint8_t)((uint8_t)(a29 + value35) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a32;
                    if (!(value36 & 0x40)) {
                        a32 = (uint8_t)(a29 + value35);
                    } else {
                        uint8_t a30;
                        if (value34 & 0x40) {
                            a30 = (uint8_t)(a29 + value35);
                        } else {
                            a30 = (uint8_t)(a29 + value35) >> 1;
                        }
                        uint8_t a31;
                        if (!(value36 & 0x40)) {
                            a31 = (uint8_t)(a30 + value35);
                        } else {
                            a31 = (uint8_t)((uint8_t)(a30 + value35) + 0x0F) ^ 0xFF;
                        }
                        a32 = a31;
                    }
                    a33 = a32;
                }
                a34 = a33;
            }
            RAM16_SET(0xC000 + x1, (a26 << 8) | a34);
            RAM8(0xC003 + x1) = ((RAM8(0x0001) ^ RAM8(0x0002)) & 0xC0) | RAM8(0x000D);
            uint8_t value40 = RAM8(0x000C);
            RAM8(0xC002 + x1) = value40;
            uint8_t a35;
            bool carry5;
            bool overflow5;
            if (((uint8_t)(value40 + 2) & 0x10) == 0) {
                a35 = (uint8_t)(value40 + 2);
                carry5 = value40 + 2 > 0xFF;
                overflow5 = ((value40 ^ (uint8_t)(value40 + 2)) & ((uint8_t)(value40 + 2) ^ 2) & 0x80) != 0;
            } else {
                if ((uint8_t)(value40 + 2) + 0x10 + (value40 + 2 > 0xFF) > 0xFF) {
                    RAM8(0x000D)++;
                }
                a35 = (uint8_t)((uint8_t)(value40 + 2) + 0x10 + (value40 + 2 > 0xFF));
                carry5 = (uint8_t)(value40 + 2) + 0x10 + (value40 + 2 > 0xFF) > 0xFF;
                overflow5 = (((uint8_t)(value40 + 2) ^ (uint8_t)((uint8_t)(value40 + 2) + 0x10 + (value40 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value40 + 2) + 0x10 + (value40 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
            }
            RAM8(0x000C) = a35;
            RAM8(0x0004)--;
            uint8_t a_hi5;
            bool carry7;
            bool overflow7;
            if (RAM8(0x0004) != 0) {
                a_hi5 = a26;
                carry7 = carry5;
                overflow7 = overflow5;
            } else {
                RAM8(0x0004) = 0x0A;
                uint16_t value41 = RAM16(0x000C);
                uint8_t a36;
                uint8_t a_hi4;
                bool carry6;
                bool overflow6;
                if (((uint16_t)(value41 - 0x24) & 0x10) == 0) {
                    a36 = (uint8_t)(value41 - 0x24);
                    a_hi4 = (uint16_t)(value41 - 0x24) >> 8;
                    carry6 = value41 >= 0x24;
                    overflow6 = ((value41 ^ 0x24) & (value41 ^ (uint16_t)(value41 - 0x24)) & 0x8000) != 0;
                } else {
                    a36 = (uint8_t)((uint16_t)(value41 - 0x24) - 0x10 - (value41 >= 0x24 ^ 1));
                    a_hi4 = (uint16_t)((uint16_t)(value41 - 0x24) - 0x10 - (value41 >= 0x24 ^ 1)) >> 8;
                    carry6 = (uint16_t)(value41 - 0x24) - 0x10 >= (value41 >= 0x24 ^ 1);
                    overflow6 = (((uint16_t)(value41 - 0x24) ^ 0x10) & ((uint16_t)(value41 - 0x24) ^ (uint16_t)((uint16_t)(value41 - 0x24) - 0x10 - (value41 >= 0x24 ^ 1))) & 0x8000) != 0;
                }
                RAM16_SET(0x000C, (a_hi4 << 8) | a36);
                a_hi5 = a_hi4;
                carry7 = carry6;
                overflow7 = overflow6;
            }
            if ((uint16_t)(y1 - 1) != 0) {
                a_hi1 = a_hi5;
                x1 = (uint16_t)(x1 + 4);
                y1 = (uint16_t)(y1 - 1);
                carry1 = carry7;
                overflow1 = overflow7;
                continue;
            }
            a_hi1 = a_hi5;
            x1 = (uint16_t)(x1 + 4);
            y1 = (uint16_t)(y1 - 1);
            carry1 = carry7;
            overflow1 = overflow7;
            break;
        }
    }
    uint16_t value42 = RAM16(0x0014);
    RAM8(0xE0C2 + value42) = 0;
    RAM8(0xE0C3 + value42) = 0;
    RAM8(0xE117 + value42) = RAM8(0xE114 + value42);
    RAM8(0xE115 + value42) = 0;
    RAM8(0xE116 + value42) = 0;
    RAM8(0xE126 + value42) = 0;
    RAM8(0xE114 + value42) = 0x40;
    r->a = (a_hi1 << 8) | 0x40;
    r->x = value42;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xACA6, 0xC2ACAC); GUARD_JSR(c, sp_call, 0xACA6); } /* append_or_retire_native_visual_effect_trail_points */
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2ABCA, SOM_RTL, "gen", decode_and_publish_native_packed_visual_effect_trail, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 222, 116)
