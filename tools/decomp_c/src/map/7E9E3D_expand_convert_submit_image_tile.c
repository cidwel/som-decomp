#include "som_c.h"

/* 7E9E3D expand_convert_submit_image_tile   [class C, 311 bytes, 170 instructions]
 * Source: src/boot/expand_convert_submit_image_tile.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCV.
 */
static void expand_convert_submit_image_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0E) + 0xB > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0E), x);
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0E), y);
    uint8_t value = RAM8(0x0008 + (uint16_t)(sp0 - 0x0E));
    RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value + 0x70);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0E)) = 4;
    uint8_t a_hi1 = (uint16_t)(sp0 - 0x0E) >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x0100;
    bool carry1 = value + 0x70 > 0xFF;
    bool overflow1 = ((value ^ (uint8_t)(value + 0x70)) & ((uint8_t)(value + 0x70) ^ 0x70) & 0x80) != 0;
    for (;;) {
        RAM8(0x0002 + (uint16_t)(sp0 - 0x0E)) = 2;
        uint8_t a1 = 2;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            RAM8(0x0003 + (uint16_t)(sp0 - 0x0E)) = 4;
            uint8_t a2 = 4;
            uint8_t a_hi3 = a_hi2;
            uint16_t x3 = x2;
            uint16_t y3 = y2;
            for (;;) {
                RAM8(0x0004 + (uint16_t)(sp0 - 0x0E)) = 2;
                uint8_t a3 = 2;
                uint8_t a_hi4 = a_hi3;
                uint16_t x4 = x3;
                uint16_t y4 = y3;
                for (;;) {
                    uint16_t value2 = RAM16(0x007E + x4);
                    RAM8(0x000A + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value2 >> 2);
                    RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = 0;
                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) = 3;
                    RAM8(0x0008 + (uint16_t)(sp0 - 0x0E))--;
                    uint8_t a_hi5 = value2 >> 2 >> 8;
                    uint16_t y5 = (uint16_t)(y4 - 1);
                    bool overflow2 = 0;
                    do {
                        RAM8(0x0008 + (uint16_t)(sp0 - 0x0E))--;
                        uint8_t value3 = BUS8_RDP(c, RAM16(0x0008 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000);
                        uint8_t value4 = RAM8(0x000A + (uint16_t)(sp0 - 0x0E));
                        BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y5 - 1), (uint8_t)(value3 + value4));
                        if (((uint8_t)(value3 + value4) & 0x80) != 0) {
                            if ((uint8_t)((uint8_t)(value3 + value4) - RAM8(0x000B + (uint16_t)(sp0 - 0x0E))) & 0x80) {
                                if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) == 0) {
                                    RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                }
                            } else {
                                if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0) {
                                    RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                }
                            }
                        }
                        if ((uint8_t)(value3 + value4) != 0x3F) {
                            if ((uint8_t)((uint8_t)(value3 + value4) - 0x3F) & 0x80) {
                                if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0) {
                                    uint8_t value6 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                    if ((uint8_t)(value3 + value4) != value6) {
                                        if ((uint8_t)((uint8_t)(value3 + value4) - value6) & 0x80) {
                                            if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0) {
                                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                            }
                                        } else {
                                            if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) == 0) {
                                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) == 0) {
                                    uint8_t value7 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                    if ((uint8_t)(value3 + value4) != value7) {
                                        if ((uint8_t)((uint8_t)(value3 + value4) - value7) & 0x80) {
                                            if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0) {
                                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                            }
                                        } else {
                                            if (((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) == 0) {
                                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value3 + value4);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                        y5 = (uint16_t)(y5 - 1);
                        overflow2 = ((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0;
                    } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) = 3;
                    uint8_t value8 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                    uint8_t a_hi14;
                    uint16_t y14;
                    if (value8 == 0) {
                        uint8_t a_hi6 = a_hi5;
                        uint16_t y6 = (uint16_t)(y5 + 3);
                        do {
                            uint8_t value9 = BUS8_RDP(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y6 - 1));
                            BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y6 - 1), value9 >> 1);
                            RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                            y6 = (uint16_t)(y6 - 1);
                        } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                        a_hi14 = a_hi6;
                        y14 = y6;
                    } else {
                        uint8_t a_hi13;
                        uint16_t y13;
                        if ((uint8_t)(value8 - 0x3F) & 0x80) {
                            uint8_t a_hi9;
                            uint16_t y9;
                            if (!overflow2) {
                                uint8_t a_hi7 = a_hi5;
                                uint16_t y7 = (uint16_t)(y5 + 3);
                                bool overflow3 = overflow2;
                                do {
                                    uint8_t value10 = BUS8_RDP(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y7 - 1));
                                    uint8_t a12;
                                    bool overflow6;
                                    if (value10 & 0x80) {
                                        uint8_t a7;
                                        bool overflow4;
                                        if (overflow3) {
                                            uint8_t value11 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            uint8_t a6;
                                            if ((uint8_t)(value10 + value11) & 0x80) {
                                                uint8_t a4;
                                                if (((value10 ^ (uint8_t)(value10 + value11)) & (value11 ^ (uint8_t)(value10 + value11)) & 0x80) != 0) {
                                                    a4 = (uint8_t)(value10 + value11);
                                                } else {
                                                    a4 = 0;
                                                }
                                                a6 = a4;
                                            } else {
                                                uint8_t a5;
                                                if (((value10 ^ (uint8_t)(value10 + value11)) & (value11 ^ (uint8_t)(value10 + value11)) & 0x80) == 0) {
                                                    a5 = (uint8_t)(value10 + value11);
                                                } else {
                                                    a5 = 0;
                                                }
                                                a6 = a5;
                                            }
                                            a7 = a6;
                                            overflow4 = ((value10 ^ (uint8_t)(value10 + value11)) & (value11 ^ (uint8_t)(value10 + value11)) & 0x80) != 0;
                                        } else {
                                            uint8_t value12 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            a7 = (uint8_t)(value10 - value12);
                                            overflow4 = ((value10 ^ value12) & (value10 ^ (uint8_t)(value10 - value12)) & 0x80) != 0;
                                        }
                                        a12 = a7;
                                        overflow6 = overflow4;
                                    } else {
                                        uint8_t a11;
                                        bool overflow5;
                                        if (!overflow3) {
                                            uint8_t value13 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            uint8_t a10;
                                            if ((uint8_t)(value10 + value13) & 0x80) {
                                                uint8_t a8;
                                                if (((value10 ^ (uint8_t)(value10 + value13)) & (value13 ^ (uint8_t)(value10 + value13)) & 0x80) != 0) {
                                                    a8 = (uint8_t)(value10 + value13);
                                                } else {
                                                    a8 = 0;
                                                }
                                                a10 = a8;
                                            } else {
                                                uint8_t a9;
                                                if (((value10 ^ (uint8_t)(value10 + value13)) & (value13 ^ (uint8_t)(value10 + value13)) & 0x80) == 0) {
                                                    a9 = (uint8_t)(value10 + value13);
                                                } else {
                                                    a9 = 0;
                                                }
                                                a10 = a9;
                                            }
                                            a11 = a10;
                                            overflow5 = ((value10 ^ (uint8_t)(value10 + value13)) & (value13 ^ (uint8_t)(value10 + value13)) & 0x80) != 0;
                                        } else {
                                            uint8_t value14 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            a11 = (uint8_t)(value10 - value14);
                                            overflow5 = ((value10 ^ value14) & (value10 ^ (uint8_t)(value10 - value14)) & 0x80) != 0;
                                        }
                                        a12 = a11;
                                        overflow6 = overflow5;
                                    }
                                    BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y7 - 1), a12 >> 1);
                                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                                    y7 = (uint16_t)(y7 - 1);
                                    overflow3 = overflow6;
                                } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                                a_hi9 = a_hi7;
                                y9 = y7;
                            } else {
                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value8 - 0x3F);
                                uint8_t a_hi8 = a_hi5;
                                uint16_t y8 = (uint16_t)(y5 + 3);
                                bool overflow7 = ((value8 ^ 0x3F) & (value8 ^ (uint8_t)(value8 - 0x3F)) & 0x80) != 0;
                                do {
                                    uint8_t value15 = BUS8_RDP(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y8 - 1));
                                    uint8_t a28;
                                    bool overflow11;
                                    if (value15 == 0x3F) {
                                        uint8_t value16 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                        uint8_t a16;
                                        if ((uint8_t)(value15 + value16) == 0x3F) {
                                            a16 = (uint8_t)(value15 + value16);
                                        } else {
                                            uint8_t a15;
                                            if ((uint8_t)((uint8_t)(value15 + value16) - 0x3F) & 0x80) {
                                                uint8_t a13;
                                                if (((value15 ^ (uint8_t)(value15 + value16)) & (value16 ^ (uint8_t)(value15 + value16)) & 0x80) == 0) {
                                                    a13 = (uint8_t)(value15 + value16);
                                                } else {
                                                    a13 = 0x3F;
                                                }
                                                a15 = a13;
                                            } else {
                                                uint8_t a14;
                                                if (((value15 ^ (uint8_t)(value15 + value16)) & (value16 ^ (uint8_t)(value15 + value16)) & 0x80) != 0) {
                                                    a14 = (uint8_t)(value15 + value16);
                                                } else {
                                                    a14 = 0x3F;
                                                }
                                                a15 = a14;
                                            }
                                            a16 = a15;
                                        }
                                        a28 = a16;
                                        overflow11 = ((value15 ^ (uint8_t)(value15 + value16)) & (value16 ^ (uint8_t)(value15 + value16)) & 0x80) != 0;
                                    } else {
                                        uint8_t a27;
                                        bool overflow10;
                                        if ((uint8_t)(value15 - 0x3F) & 0x80) {
                                            uint8_t a21;
                                            bool overflow8;
                                            if (!overflow7) {
                                                uint8_t value17 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                uint8_t a20;
                                                if ((uint8_t)(value15 + value17) == 0x3F) {
                                                    a20 = (uint8_t)(value15 + value17);
                                                } else {
                                                    uint8_t a19;
                                                    if ((uint8_t)((uint8_t)(value15 + value17) - 0x3F) & 0x80) {
                                                        uint8_t a17;
                                                        if (((value15 ^ (uint8_t)(value15 + value17)) & (value17 ^ (uint8_t)(value15 + value17)) & 0x80) == 0) {
                                                            a17 = (uint8_t)(value15 + value17);
                                                        } else {
                                                            a17 = 0x3F;
                                                        }
                                                        a19 = a17;
                                                    } else {
                                                        uint8_t a18;
                                                        if (((value15 ^ (uint8_t)(value15 + value17)) & (value17 ^ (uint8_t)(value15 + value17)) & 0x80) != 0) {
                                                            a18 = (uint8_t)(value15 + value17);
                                                        } else {
                                                            a18 = 0x3F;
                                                        }
                                                        a19 = a18;
                                                    }
                                                    a20 = a19;
                                                }
                                                a21 = a20;
                                                overflow8 = ((value15 ^ (uint8_t)(value15 + value17)) & (value17 ^ (uint8_t)(value15 + value17)) & 0x80) != 0;
                                            } else {
                                                uint8_t value18 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                a21 = (uint8_t)(value15 - value18);
                                                overflow8 = ((value15 ^ value18) & (value15 ^ (uint8_t)(value15 - value18)) & 0x80) != 0;
                                            }
                                            a27 = a21;
                                            overflow10 = overflow8;
                                        } else {
                                            uint8_t a26;
                                            bool overflow9;
                                            if (overflow7) {
                                                uint8_t value19 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                uint8_t a25;
                                                if ((uint8_t)(value15 + value19) == 0x3F) {
                                                    a25 = (uint8_t)(value15 + value19);
                                                } else {
                                                    uint8_t a24;
                                                    if ((uint8_t)((uint8_t)(value15 + value19) - 0x3F) & 0x80) {
                                                        uint8_t a22;
                                                        if (((value15 ^ (uint8_t)(value15 + value19)) & (value19 ^ (uint8_t)(value15 + value19)) & 0x80) == 0) {
                                                            a22 = (uint8_t)(value15 + value19);
                                                        } else {
                                                            a22 = 0x3F;
                                                        }
                                                        a24 = a22;
                                                    } else {
                                                        uint8_t a23;
                                                        if (((value15 ^ (uint8_t)(value15 + value19)) & (value19 ^ (uint8_t)(value15 + value19)) & 0x80) != 0) {
                                                            a23 = (uint8_t)(value15 + value19);
                                                        } else {
                                                            a23 = 0x3F;
                                                        }
                                                        a24 = a23;
                                                    }
                                                    a25 = a24;
                                                }
                                                a26 = a25;
                                                overflow9 = ((value15 ^ (uint8_t)(value15 + value19)) & (value19 ^ (uint8_t)(value15 + value19)) & 0x80) != 0;
                                            } else {
                                                uint8_t value20 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                a26 = (uint8_t)(value15 - value20);
                                                overflow9 = ((value15 ^ value20) & (value15 ^ (uint8_t)(value15 - value20)) & 0x80) != 0;
                                            }
                                            a27 = a26;
                                            overflow10 = overflow9;
                                        }
                                        a28 = a27;
                                        overflow11 = overflow10;
                                    }
                                    BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y8 - 1), a28 >> 1);
                                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                                    y8 = (uint16_t)(y8 - 1);
                                    overflow7 = overflow11;
                                } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                                a_hi9 = a_hi8;
                                y9 = y8;
                            }
                            a_hi13 = a_hi9;
                            y13 = y9;
                        } else {
                            uint8_t a_hi12;
                            uint16_t y12;
                            if (overflow2) {
                                uint8_t a_hi10 = a_hi5;
                                uint16_t y10 = (uint16_t)(y5 + 3);
                                bool overflow12 = overflow2;
                                do {
                                    uint8_t value21 = BUS8_RDP(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y10 - 1));
                                    uint8_t a37;
                                    bool overflow15;
                                    if (value21 & 0x80) {
                                        uint8_t a32;
                                        bool overflow13;
                                        if (overflow12) {
                                            uint8_t value22 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            uint8_t a31;
                                            if ((uint8_t)(value21 + value22) & 0x80) {
                                                uint8_t a29;
                                                if (((value21 ^ (uint8_t)(value21 + value22)) & (value22 ^ (uint8_t)(value21 + value22)) & 0x80) != 0) {
                                                    a29 = (uint8_t)(value21 + value22);
                                                } else {
                                                    a29 = 0;
                                                }
                                                a31 = a29;
                                            } else {
                                                uint8_t a30;
                                                if (((value21 ^ (uint8_t)(value21 + value22)) & (value22 ^ (uint8_t)(value21 + value22)) & 0x80) == 0) {
                                                    a30 = (uint8_t)(value21 + value22);
                                                } else {
                                                    a30 = 0;
                                                }
                                                a31 = a30;
                                            }
                                            a32 = a31;
                                            overflow13 = ((value21 ^ (uint8_t)(value21 + value22)) & (value22 ^ (uint8_t)(value21 + value22)) & 0x80) != 0;
                                        } else {
                                            uint8_t value23 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            a32 = (uint8_t)(value21 - value23);
                                            overflow13 = ((value21 ^ value23) & (value21 ^ (uint8_t)(value21 - value23)) & 0x80) != 0;
                                        }
                                        a37 = a32;
                                        overflow15 = overflow13;
                                    } else {
                                        uint8_t a36;
                                        bool overflow14;
                                        if (!overflow12) {
                                            uint8_t value24 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            uint8_t a35;
                                            if ((uint8_t)(value21 + value24) & 0x80) {
                                                uint8_t a33;
                                                if (((value21 ^ (uint8_t)(value21 + value24)) & (value24 ^ (uint8_t)(value21 + value24)) & 0x80) != 0) {
                                                    a33 = (uint8_t)(value21 + value24);
                                                } else {
                                                    a33 = 0;
                                                }
                                                a35 = a33;
                                            } else {
                                                uint8_t a34;
                                                if (((value21 ^ (uint8_t)(value21 + value24)) & (value24 ^ (uint8_t)(value21 + value24)) & 0x80) == 0) {
                                                    a34 = (uint8_t)(value21 + value24);
                                                } else {
                                                    a34 = 0;
                                                }
                                                a35 = a34;
                                            }
                                            a36 = a35;
                                            overflow14 = ((value21 ^ (uint8_t)(value21 + value24)) & (value24 ^ (uint8_t)(value21 + value24)) & 0x80) != 0;
                                        } else {
                                            uint8_t value25 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                            a36 = (uint8_t)(value21 - value25);
                                            overflow14 = ((value21 ^ value25) & (value21 ^ (uint8_t)(value21 - value25)) & 0x80) != 0;
                                        }
                                        a37 = a36;
                                        overflow15 = overflow14;
                                    }
                                    BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y10 - 1), a37 >> 1);
                                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                                    y10 = (uint16_t)(y10 - 1);
                                    overflow12 = overflow15;
                                } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                                a_hi12 = a_hi10;
                                y12 = y10;
                            } else {
                                RAM8(0x000B + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value8 - 0x3F);
                                uint8_t a_hi11 = a_hi5;
                                uint16_t y11 = (uint16_t)(y5 + 3);
                                bool overflow16 = ((value8 ^ 0x3F) & (value8 ^ (uint8_t)(value8 - 0x3F)) & 0x80) != 0;
                                do {
                                    uint8_t value26 = BUS8_RDP(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y11 - 1));
                                    uint8_t a53;
                                    bool overflow20;
                                    if (value26 == 0x3F) {
                                        uint8_t value27 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                        uint8_t a41;
                                        if ((uint8_t)(value26 + value27) == 0x3F) {
                                            a41 = (uint8_t)(value26 + value27);
                                        } else {
                                            uint8_t a40;
                                            if ((uint8_t)((uint8_t)(value26 + value27) - 0x3F) & 0x80) {
                                                uint8_t a38;
                                                if (((value26 ^ (uint8_t)(value26 + value27)) & (value27 ^ (uint8_t)(value26 + value27)) & 0x80) == 0) {
                                                    a38 = (uint8_t)(value26 + value27);
                                                } else {
                                                    a38 = 0x3F;
                                                }
                                                a40 = a38;
                                            } else {
                                                uint8_t a39;
                                                if (((value26 ^ (uint8_t)(value26 + value27)) & (value27 ^ (uint8_t)(value26 + value27)) & 0x80) != 0) {
                                                    a39 = (uint8_t)(value26 + value27);
                                                } else {
                                                    a39 = 0x3F;
                                                }
                                                a40 = a39;
                                            }
                                            a41 = a40;
                                        }
                                        a53 = a41;
                                        overflow20 = ((value26 ^ (uint8_t)(value26 + value27)) & (value27 ^ (uint8_t)(value26 + value27)) & 0x80) != 0;
                                    } else {
                                        uint8_t a52;
                                        bool overflow19;
                                        if ((uint8_t)(value26 - 0x3F) & 0x80) {
                                            uint8_t a46;
                                            bool overflow17;
                                            if (!overflow16) {
                                                uint8_t value28 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                uint8_t a45;
                                                if ((uint8_t)(value26 + value28) == 0x3F) {
                                                    a45 = (uint8_t)(value26 + value28);
                                                } else {
                                                    uint8_t a44;
                                                    if ((uint8_t)((uint8_t)(value26 + value28) - 0x3F) & 0x80) {
                                                        uint8_t a42;
                                                        if (((value26 ^ (uint8_t)(value26 + value28)) & (value28 ^ (uint8_t)(value26 + value28)) & 0x80) == 0) {
                                                            a42 = (uint8_t)(value26 + value28);
                                                        } else {
                                                            a42 = 0x3F;
                                                        }
                                                        a44 = a42;
                                                    } else {
                                                        uint8_t a43;
                                                        if (((value26 ^ (uint8_t)(value26 + value28)) & (value28 ^ (uint8_t)(value26 + value28)) & 0x80) != 0) {
                                                            a43 = (uint8_t)(value26 + value28);
                                                        } else {
                                                            a43 = 0x3F;
                                                        }
                                                        a44 = a43;
                                                    }
                                                    a45 = a44;
                                                }
                                                a46 = a45;
                                                overflow17 = ((value26 ^ (uint8_t)(value26 + value28)) & (value28 ^ (uint8_t)(value26 + value28)) & 0x80) != 0;
                                            } else {
                                                uint8_t value29 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                a46 = (uint8_t)(value26 - value29);
                                                overflow17 = ((value26 ^ value29) & (value26 ^ (uint8_t)(value26 - value29)) & 0x80) != 0;
                                            }
                                            a52 = a46;
                                            overflow19 = overflow17;
                                        } else {
                                            uint8_t a51;
                                            bool overflow18;
                                            if (overflow16) {
                                                uint8_t value30 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                uint8_t a50;
                                                if ((uint8_t)(value26 + value30) == 0x3F) {
                                                    a50 = (uint8_t)(value26 + value30);
                                                } else {
                                                    uint8_t a49;
                                                    if ((uint8_t)((uint8_t)(value26 + value30) - 0x3F) & 0x80) {
                                                        uint8_t a47;
                                                        if (((value26 ^ (uint8_t)(value26 + value30)) & (value30 ^ (uint8_t)(value26 + value30)) & 0x80) == 0) {
                                                            a47 = (uint8_t)(value26 + value30);
                                                        } else {
                                                            a47 = 0x3F;
                                                        }
                                                        a49 = a47;
                                                    } else {
                                                        uint8_t a48;
                                                        if (((value26 ^ (uint8_t)(value26 + value30)) & (value30 ^ (uint8_t)(value26 + value30)) & 0x80) != 0) {
                                                            a48 = (uint8_t)(value26 + value30);
                                                        } else {
                                                            a48 = 0x3F;
                                                        }
                                                        a49 = a48;
                                                    }
                                                    a50 = a49;
                                                }
                                                a51 = a50;
                                                overflow18 = ((value26 ^ (uint8_t)(value26 + value30)) & (value30 ^ (uint8_t)(value26 + value30)) & 0x80) != 0;
                                            } else {
                                                uint8_t value31 = RAM8(0x000B + (uint16_t)(sp0 - 0x0E));
                                                a51 = (uint8_t)(value26 - value31);
                                                overflow18 = ((value26 ^ value31) & (value26 ^ (uint8_t)(value26 - value31)) & 0x80) != 0;
                                            }
                                            a52 = a51;
                                            overflow19 = overflow18;
                                        }
                                        a53 = a52;
                                        overflow20 = overflow19;
                                    }
                                    BUS8_SET(c, RAM16(0x0006 + (uint16_t)(sp0 - 0x0E)) + 0x7E0000 + (uint16_t)(y11 - 1), a53 >> 1);
                                    RAM8(0x0005 + (uint16_t)(sp0 - 0x0E))--;
                                    y11 = (uint16_t)(y11 - 1);
                                    overflow16 = overflow20;
                                } while (RAM8(0x0005 + (uint16_t)(sp0 - 0x0E)) != 0);
                                a_hi12 = a_hi11;
                                y12 = y11;
                            }
                            a_hi13 = a_hi12;
                            y13 = y12;
                        }
                        a_hi14 = a_hi13;
                        y14 = y13;
                    }
                    uint8_t value32 = RAM8(0x0008 + (uint16_t)(sp0 - 0x0E));
                    RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(value32 + 4);
                    RAM8(0x0004 + (uint16_t)(sp0 - 0x0E))--;
                    if (RAM8(0x0004 + (uint16_t)(sp0 - 0x0E)) != 0) {
                        a3 = (uint8_t)(value32 + 4);
                        a_hi4 = a_hi14;
                        x4 = (uint16_t)(x4 - 2);
                        y4 = y14;
                        continue;
                    }
                    a3 = (uint8_t)(value32 + 4);
                    a_hi4 = a_hi14;
                    x4 = (uint16_t)(x4 - 2);
                    y4 = y14;
                    break;
                }
                RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(a3 - 4);
                RAM8(0x0003 + (uint16_t)(sp0 - 0x0E))--;
                if (RAM8(0x0003 + (uint16_t)(sp0 - 0x0E)) != 0) {
                    a2 = (uint8_t)(a3 - 4);
                    a_hi3 = a_hi4;
                    x3 = x4;
                    y3 = y4;
                    continue;
                }
                a2 = (uint8_t)(a3 - 4);
                a_hi3 = a_hi4;
                x3 = x4;
                y3 = y4;
                break;
            }
            RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(a2 + 0x10);
            RAM8(0x0002 + (uint16_t)(sp0 - 0x0E))--;
            if (RAM8(0x0002 + (uint16_t)(sp0 - 0x0E)) != 0) {
                a1 = (uint8_t)(a2 + 0x10);
                a_hi2 = a_hi3;
                x2 = x3;
                y2 = y3;
                continue;
            }
            a1 = (uint8_t)(a2 + 0x10);
            a_hi2 = a_hi3;
            x2 = x3;
            y2 = y3;
            break;
        }
        RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)(a1 - 0x20);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0E))--;
        if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0E)) != 0) {
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            carry1 = a1 >= 0x20;
            overflow1 = ((a1 ^ 0x20) & (a1 ^ (uint8_t)(a1 - 0x20)) & 0x80) != 0;
            continue;
        }
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        carry1 = a1 >= 0x20;
        overflow1 = ((a1 ^ 0x20) & (a1 ^ (uint8_t)(a1 - 0x20)) & 0x80) != 0;
        break;
    }
    uint16_t value33 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0E));
    r->x = value33;
    r->y = y1;
    r->c = carry1;
    r->z = value33 == 0;
    r->n = value33 & 0x8000;
    r->v = overflow1;
    r->dp = (uint16_t)(sp0 - 0x0E);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F68, 0x7E9D1E); GUARD_JSR(c, sp_call, 0x9F68); } /* convert_components_to_planar_tile */
    r->sp += 14;
    uint8_t value34 = RAM8(0x0000 + sp0 - 2);
    uint8_t value35 = RAM8(0x0000 + sp0 - 1);
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->c = value34 & 0x01;
    r->v = value34 & 0x40;
    r->mf = value34 & 0x20;
    r->xf = value34 & 0x10;
    r->dp = (value36 << 8) | value35;
    r->i = value34 & 0x04;
    r->d = value34 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9E3D, SOM_RTS, "gen", expand_convert_submit_image_tile, 0, L_X | L_Y | L_C | L_V, 14, 1, 0, 311, 170)
