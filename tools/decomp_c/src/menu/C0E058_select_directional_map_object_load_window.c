#include "som_c.h"

/* C0E058 select_directional_map_object_load_window   [class C, 330 bytes, 171 instructions]
 * Source: src/rom/select_directional_map_object_load_window.s
 * Documented in docs/map-object-direction-window.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_directional_map_object_load_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00BA);
    uint16_t value2 = RAM16(0xE006 + value);
    uint8_t a39;
    uint8_t a_hi34;
    if (value2 >> 8 != 0) {
        uint8_t a16;
        uint8_t a_hi14;
        if (!(value2 >> 8 & 0x80)) {
            uint8_t a6;
            uint8_t a_hi5;
            if ((uint8_t)value2 == 0) {
                RAM16_SET(0x0000, 0x14FE);
                a6 = 0x12;
                a_hi5 = 6;
            } else {
                uint8_t a5;
                uint8_t a_hi4;
                if ((uint8_t)value2 & 0x80) {
                    RAM16_SET(0x0000, 0x06F8);
                    a5 = 8;
                    a_hi4 = 0x10;
                } else {
                    uint8_t a4;
                    uint8_t a_hi3;
                    if (!((uint8_t)value2 & 0x80)) {
                        RAM16_SET(0x0000, 0x0612);
                        a4 = 8;
                        a_hi3 = 0x10;
                    } else {
                        uint8_t value3 = RAM8(0x00F4);
                        uint8_t a3;
                        uint8_t a_hi2;
                        if (((value3 >> 2) & 3) == 0) {
                            RAM16_SET(0x0000, 0x06F8);
                            a3 = 0xFE;
                            a_hi2 = 0x12;
                        } else {
                            uint8_t a2;
                            uint8_t a_hi1;
                            if ((uint8_t)(((value3 >> 2) & 3) - 1) == 0) {
                                RAM16_SET(0x0000, 0x0612);
                                a2 = 0xFE;
                                a_hi1 = 0x12;
                            } else {
                                uint8_t a1;
                                if ((uint8_t)(((value3 >> 2) & 3) - 2) == 0) {
                                    RAM16_SET(0x0000, 0x14FE);
                                    a1 = 0xF8;
                                } else {
                                    RAM16_SET(0x0000, 0x14FE);
                                    a1 = 0x12;
                                }
                                a2 = a1;
                                a_hi1 = 6;
                            }
                            a3 = a2;
                            a_hi2 = a_hi1;
                        }
                        a4 = a3;
                        a_hi3 = a_hi2;
                    }
                    a5 = a4;
                    a_hi4 = a_hi3;
                }
                a6 = a5;
                a_hi5 = a_hi4;
            }
            a16 = a6;
            a_hi14 = a_hi5;
        } else {
            uint8_t a15;
            uint8_t a_hi13;
            if ((uint8_t)value2 == 0) {
                RAM16_SET(0x0000, 0x14FE);
                a15 = 0xF8;
                a_hi13 = 6;
            } else {
                uint8_t a14;
                uint8_t a_hi12;
                if ((uint8_t)value2 & 0x80) {
                    RAM16_SET(0x0000, 0x06F8);
                    a14 = 0xF8;
                    a_hi12 = 0x10;
                } else {
                    uint8_t a13;
                    uint8_t a_hi11;
                    if (!((uint8_t)value2 & 0x80)) {
                        RAM16_SET(0x0000, 0x0612);
                        a13 = 0xF8;
                        a_hi11 = 0x10;
                    } else {
                        uint8_t a12;
                        uint8_t a_hi10;
                        if (value2 >> 8 == 0) {
                            RAM16_SET(0x0000, 0x14FE);
                            a12 = 0x12;
                            a_hi10 = 6;
                        } else {
                            uint8_t a11;
                            uint8_t a_hi9;
                            if (value2 >> 8 & 0x80) {
                                RAM16_SET(0x0000, 0x06F8);
                                a11 = 8;
                                a_hi9 = 0x10;
                            } else {
                                uint8_t a10;
                                uint8_t a_hi8;
                                if (!(value2 >> 8 & 0x80)) {
                                    RAM16_SET(0x0000, 0x0612);
                                    a10 = 8;
                                    a_hi8 = 0x10;
                                } else {
                                    uint8_t value4 = RAM8(0x00F4);
                                    uint8_t a9;
                                    uint8_t a_hi7;
                                    if (((value4 >> 2) & 3) == 0) {
                                        RAM16_SET(0x0000, 0x06F8);
                                        a9 = 0xFE;
                                        a_hi7 = 0x12;
                                    } else {
                                        uint8_t a8;
                                        uint8_t a_hi6;
                                        if ((uint8_t)(((value4 >> 2) & 3) - 1) == 0) {
                                            RAM16_SET(0x0000, 0x0612);
                                            a8 = 0xFE;
                                            a_hi6 = 0x12;
                                        } else {
                                            uint8_t a7;
                                            if ((uint8_t)(((value4 >> 2) & 3) - 2) == 0) {
                                                RAM16_SET(0x0000, 0x14FE);
                                                a7 = 0xF8;
                                            } else {
                                                RAM16_SET(0x0000, 0x14FE);
                                                a7 = 0x12;
                                            }
                                            a8 = a7;
                                            a_hi6 = 6;
                                        }
                                        a9 = a8;
                                        a_hi7 = a_hi6;
                                    }
                                    a10 = a9;
                                    a_hi8 = a_hi7;
                                }
                                a11 = a10;
                                a_hi9 = a_hi8;
                            }
                            a12 = a11;
                            a_hi10 = a_hi9;
                        }
                        a13 = a12;
                        a_hi11 = a_hi10;
                    }
                    a14 = a13;
                    a_hi12 = a_hi11;
                }
                a15 = a14;
                a_hi13 = a_hi12;
            }
            a16 = a15;
            a_hi14 = a_hi13;
        }
        a39 = a16;
        a_hi34 = a_hi14;
    } else {
        uint8_t a38;
        uint8_t a_hi33;
        if ((uint8_t)value2 == 0) {
            uint8_t value5 = RAM8(0x00F4);
            uint8_t a19;
            uint8_t a_hi16;
            if (((value5 >> 2) & 3) == 0) {
                RAM16_SET(0x0000, 0x06F8);
                a19 = 0xFE;
                a_hi16 = 0x12;
            } else {
                uint8_t a18;
                uint8_t a_hi15;
                if ((uint8_t)(((value5 >> 2) & 3) - 1) == 0) {
                    RAM16_SET(0x0000, 0x0612);
                    a18 = 0xFE;
                    a_hi15 = 0x12;
                } else {
                    uint8_t a17;
                    if ((uint8_t)(((value5 >> 2) & 3) - 2) == 0) {
                        RAM16_SET(0x0000, 0x14FE);
                        a17 = 0xF8;
                    } else {
                        RAM16_SET(0x0000, 0x14FE);
                        a17 = 0x12;
                    }
                    a18 = a17;
                    a_hi15 = 6;
                }
                a19 = a18;
                a_hi16 = a_hi15;
            }
            a38 = a19;
            a_hi33 = a_hi16;
        } else {
            uint8_t a37;
            uint8_t a_hi32;
            if (!((uint8_t)value2 & 0x80)) {
                RAM16_SET(0x0000, 0x0612);
                a37 = 0xFE;
                a_hi32 = 0x12;
            } else {
                uint8_t a36;
                uint8_t a_hi31;
                if ((uint8_t)value2 & 0x80) {
                    RAM16_SET(0x0000, 0x06F8);
                    a36 = 0xFE;
                    a_hi31 = 0x12;
                } else {
                    uint8_t a35;
                    uint8_t a_hi30;
                    if (!((uint8_t)value2 & 0x80)) {
                        uint8_t a25;
                        uint8_t a_hi21;
                        if (value2 >> 8 == 0) {
                            RAM16_SET(0x0000, 0x14FE);
                            a25 = 0x12;
                            a_hi21 = 6;
                        } else {
                            uint8_t a24;
                            uint8_t a_hi20;
                            if (value2 >> 8 & 0x80) {
                                RAM16_SET(0x0000, 0x06F8);
                                a24 = 8;
                                a_hi20 = 0x10;
                            } else {
                                uint8_t a23;
                                uint8_t a_hi19;
                                if (!(value2 >> 8 & 0x80)) {
                                    RAM16_SET(0x0000, 0x0612);
                                    a23 = 8;
                                    a_hi19 = 0x10;
                                } else {
                                    uint8_t value6 = RAM8(0x00F4);
                                    uint8_t a22;
                                    uint8_t a_hi18;
                                    if (((value6 >> 2) & 3) == 0) {
                                        RAM16_SET(0x0000, 0x06F8);
                                        a22 = 0xFE;
                                        a_hi18 = 0x12;
                                    } else {
                                        uint8_t a21;
                                        uint8_t a_hi17;
                                        if ((uint8_t)(((value6 >> 2) & 3) - 1) == 0) {
                                            RAM16_SET(0x0000, 0x0612);
                                            a21 = 0xFE;
                                            a_hi17 = 0x12;
                                        } else {
                                            uint8_t a20;
                                            if ((uint8_t)(((value6 >> 2) & 3) - 2) == 0) {
                                                RAM16_SET(0x0000, 0x14FE);
                                                a20 = 0xF8;
                                            } else {
                                                RAM16_SET(0x0000, 0x14FE);
                                                a20 = 0x12;
                                            }
                                            a21 = a20;
                                            a_hi17 = 6;
                                        }
                                        a22 = a21;
                                        a_hi18 = a_hi17;
                                    }
                                    a23 = a22;
                                    a_hi19 = a_hi18;
                                }
                                a24 = a23;
                                a_hi20 = a_hi19;
                            }
                            a25 = a24;
                            a_hi21 = a_hi20;
                        }
                        a35 = a25;
                        a_hi30 = a_hi21;
                    } else {
                        uint8_t a34;
                        uint8_t a_hi29;
                        if (value2 >> 8 == 0) {
                            RAM16_SET(0x0000, 0x14FE);
                            a34 = 0xF8;
                            a_hi29 = 6;
                        } else {
                            uint8_t a33;
                            uint8_t a_hi28;
                            if (value2 >> 8 & 0x80) {
                                RAM16_SET(0x0000, 0x06F8);
                                a33 = 0xF8;
                                a_hi28 = 0x10;
                            } else {
                                uint8_t a32;
                                uint8_t a_hi27;
                                if (!(value2 >> 8 & 0x80)) {
                                    RAM16_SET(0x0000, 0x0612);
                                    a32 = 0xF8;
                                    a_hi27 = 0x10;
                                } else {
                                    uint8_t a31;
                                    uint8_t a_hi26;
                                    if ((uint8_t)value2 == 0) {
                                        RAM16_SET(0x0000, 0x14FE);
                                        a31 = 0x12;
                                        a_hi26 = 6;
                                    } else {
                                        uint8_t a30;
                                        uint8_t a_hi25;
                                        if ((uint8_t)value2 & 0x80) {
                                            RAM16_SET(0x0000, 0x06F8);
                                            a30 = 8;
                                            a_hi25 = 0x10;
                                        } else {
                                            uint8_t a29;
                                            uint8_t a_hi24;
                                            if (!((uint8_t)value2 & 0x80)) {
                                                RAM16_SET(0x0000, 0x0612);
                                                a29 = 8;
                                                a_hi24 = 0x10;
                                            } else {
                                                uint8_t value7 = RAM8(0x00F4);
                                                uint8_t a28;
                                                uint8_t a_hi23;
                                                if (((value7 >> 2) & 3) == 0) {
                                                    RAM16_SET(0x0000, 0x06F8);
                                                    a28 = 0xFE;
                                                    a_hi23 = 0x12;
                                                } else {
                                                    uint8_t a27;
                                                    uint8_t a_hi22;
                                                    if ((uint8_t)(((value7 >> 2) & 3) - 1) == 0) {
                                                        RAM16_SET(0x0000, 0x0612);
                                                        a27 = 0xFE;
                                                        a_hi22 = 0x12;
                                                    } else {
                                                        uint8_t a26;
                                                        if ((uint8_t)(((value7 >> 2) & 3) - 2) == 0) {
                                                            RAM16_SET(0x0000, 0x14FE);
                                                            a26 = 0xF8;
                                                        } else {
                                                            RAM16_SET(0x0000, 0x14FE);
                                                            a26 = 0x12;
                                                        }
                                                        a27 = a26;
                                                        a_hi22 = 6;
                                                    }
                                                    a28 = a27;
                                                    a_hi23 = a_hi22;
                                                }
                                                a29 = a28;
                                                a_hi24 = a_hi23;
                                            }
                                            a30 = a29;
                                            a_hi25 = a_hi24;
                                        }
                                        a31 = a30;
                                        a_hi26 = a_hi25;
                                    }
                                    a32 = a31;
                                    a_hi27 = a_hi26;
                                }
                                a33 = a32;
                                a_hi28 = a_hi27;
                            }
                            a34 = a33;
                            a_hi29 = a_hi28;
                        }
                        a35 = a34;
                        a_hi30 = a_hi29;
                    }
                    a36 = a35;
                    a_hi31 = a_hi30;
                }
                a37 = a36;
                a_hi32 = a_hi31;
            }
            a38 = a37;
            a_hi33 = a_hi32;
        }
        a39 = a38;
        a_hi34 = a_hi33;
    }
    RAM8(0x0009) = a_hi34;
    RAM8(0x0008) = RAM8(0x0001);
    RAM8(0x0001) = a39;
    uint16_t value9 = RAM16(0x00A8);
    uint8_t value10 = RAM8(0x0000);
    uint8_t a42;
    if (!(value10 & 0x80)) {
        uint8_t value11 = RAM8(0x009C);
        uint8_t a40;
        if ((uint8_t)((uint8_t)(value9 >> 4) + value10) < value11) {
            a40 = (uint8_t)((uint8_t)(value9 >> 4) + value10);
        } else {
            a40 = (uint8_t)((uint8_t)((uint8_t)(value9 >> 4) + value10) - value11 - ((uint8_t)((uint8_t)(value9 >> 4) + value10) >= value11 ^ 1));
        }
        a42 = a40;
    } else {
        uint8_t a41;
        if (!((uint8_t)((uint8_t)(value9 >> 4) + value10) & 0x80)) {
            a41 = (uint8_t)((uint8_t)(value9 >> 4) + value10);
        } else {
            a41 = (uint8_t)((uint8_t)((uint8_t)(value9 >> 4) + value10) + RAM8(0x009C) + ((uint8_t)(value9 >> 4) + value10 > 0xFF));
        }
        a42 = a41;
    }
    RAM8(0x0004) = a42;
    uint16_t value13 = RAM16(0x00AA);
    uint8_t value14 = RAM8(0x0001);
    uint8_t a45;
    if (!(value14 & 0x80)) {
        uint8_t value15 = RAM8(0x009D);
        uint8_t a43;
        if ((uint8_t)((uint8_t)(value13 >> 4) + value14) < value15) {
            a43 = (uint8_t)((uint8_t)(value13 >> 4) + value14);
        } else {
            a43 = (uint8_t)((uint8_t)((uint8_t)(value13 >> 4) + value14) - value15 - ((uint8_t)((uint8_t)(value13 >> 4) + value14) >= value15 ^ 1));
        }
        a45 = a43;
    } else {
        uint8_t a44;
        if (!((uint8_t)((uint8_t)(value13 >> 4) + value14) & 0x80)) {
            a44 = (uint8_t)((uint8_t)(value13 >> 4) + value14);
        } else {
            a44 = (uint8_t)((uint8_t)((uint8_t)(value13 >> 4) + value14) + RAM8(0x009D) + ((uint8_t)(value13 >> 4) + value14 > 0xFF));
        }
        a45 = a44;
    }
    RAM8(0x0005) = a45;
    uint16_t value17 = RAM16(0x00AC);
    uint8_t a48;
    if (!(value10 & 0x80)) {
        uint8_t value18 = RAM8(0x00A0);
        uint8_t a46;
        if ((uint8_t)((uint8_t)(value17 >> 4) + value10) < value18) {
            a46 = (uint8_t)((uint8_t)(value17 >> 4) + value10);
        } else {
            a46 = (uint8_t)((uint8_t)((uint8_t)(value17 >> 4) + value10) - value18 - ((uint8_t)((uint8_t)(value17 >> 4) + value10) >= value18 ^ 1));
        }
        a48 = a46;
    } else {
        uint8_t a47;
        if (!((uint8_t)((uint8_t)(value17 >> 4) + value10) & 0x80)) {
            a47 = (uint8_t)((uint8_t)(value17 >> 4) + value10);
        } else {
            a47 = (uint8_t)((uint8_t)((uint8_t)(value17 >> 4) + value10) + RAM8(0x00A0) + ((uint8_t)(value17 >> 4) + value10 > 0xFF));
        }
        a48 = a47;
    }
    RAM8(0x0006) = a48;
    uint16_t value20 = RAM16(0x00AE);
    uint8_t a51;
    bool carry3;
    bool overflow3;
    if (!(value14 & 0x80)) {
        uint8_t value21 = RAM8(0x00A1);
        uint8_t a49;
        bool carry1;
        bool overflow1;
        if ((uint8_t)((uint8_t)(value20 >> 4) + value14) < value21) {
            a49 = (uint8_t)((uint8_t)(value20 >> 4) + value14);
            carry1 = (uint8_t)((uint8_t)(value20 >> 4) + value14) >= value21;
            overflow1 = (((uint8_t)(value20 >> 4) ^ (uint8_t)((uint8_t)(value20 >> 4) + value14)) & (value14 ^ (uint8_t)((uint8_t)(value20 >> 4) + value14)) & 0x80) != 0;
        } else {
            a49 = (uint8_t)((uint8_t)((uint8_t)(value20 >> 4) + value14) - value21 - ((uint8_t)((uint8_t)(value20 >> 4) + value14) >= value21 ^ 1));
            carry1 = (uint8_t)((uint8_t)(value20 >> 4) + value14) - value21 >= ((uint8_t)((uint8_t)(value20 >> 4) + value14) >= value21 ^ 1);
            overflow1 = (((uint8_t)((uint8_t)(value20 >> 4) + value14) ^ value21) & ((uint8_t)((uint8_t)(value20 >> 4) + value14) ^ (uint8_t)((uint8_t)((uint8_t)(value20 >> 4) + value14) - value21 - ((uint8_t)((uint8_t)(value20 >> 4) + value14) >= value21 ^ 1))) & 0x80) != 0;
        }
        a51 = a49;
        carry3 = carry1;
        overflow3 = overflow1;
    } else {
        uint8_t a50;
        bool carry2;
        bool overflow2;
        if (!((uint8_t)((uint8_t)(value20 >> 4) + value14) & 0x80)) {
            a50 = (uint8_t)((uint8_t)(value20 >> 4) + value14);
            carry2 = (uint8_t)(value20 >> 4) + value14 > 0xFF;
            overflow2 = (((uint8_t)(value20 >> 4) ^ (uint8_t)((uint8_t)(value20 >> 4) + value14)) & (value14 ^ (uint8_t)((uint8_t)(value20 >> 4) + value14)) & 0x80) != 0;
        } else {
            uint8_t value22 = RAM8(0x00A1);
            a50 = (uint8_t)((uint8_t)((uint8_t)(value20 >> 4) + value14) + value22 + ((uint8_t)(value20 >> 4) + value14 > 0xFF));
            carry2 = (uint8_t)((uint8_t)(value20 >> 4) + value14) + value22 + ((uint8_t)(value20 >> 4) + value14 > 0xFF) > 0xFF;
            overflow2 = (((uint8_t)((uint8_t)(value20 >> 4) + value14) ^ (uint8_t)((uint8_t)((uint8_t)(value20 >> 4) + value14) + value22 + ((uint8_t)(value20 >> 4) + value14 > 0xFF))) & (value22 ^ (uint8_t)((uint8_t)((uint8_t)(value20 >> 4) + value14) + value22 + ((uint8_t)(value20 >> 4) + value14 > 0xFF))) & 0x80) != 0;
        }
        a51 = a50;
        carry3 = carry2;
        overflow3 = overflow2;
    }
    RAM8(0x0007) = a51;
    r->a = (r->a & 0x00FF) | ((value20 >> 4 >> 8) << 8);
    r->y = value;
    r->c = carry3;
    r->v = overflow3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E058, SOM_RTS, "gen", select_directional_map_object_load_window, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 330, 171)
