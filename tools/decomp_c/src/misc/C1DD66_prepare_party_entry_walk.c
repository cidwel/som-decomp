#include "som_c.h"

/* C1DD66 prepare_party_entry_walk   [class C, 381 bytes, 168 instructions]
 * Source: src/rom/prepare_party_entry_walk.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void prepare_party_entry_walk(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00D4);
    uint8_t value2 = RAM8(0x00E8);
    if ((value2 & 3) != 0) {
        uint8_t a1;
        if ((value2 & 2) != 0) {
            a1 = 0xA8;
        } else {
            a1 = 0x28;
        }
        RAM8(0xE00F) = a1;
        RAM8(0xE20F) = a1;
        RAM8(0xE40F) = a1;
        uint8_t value3 = RAM8(0x00D5);
        if (value3 == 0) {
            RAM8(0xE206) = 0x82;
            RAM8(0xE406) = 0x82;
            RAM8(0xE40A) = 8;
            RAM8(0xE20A) = 0x12;
            r->x = value;
            RETURN_RTS(c);
        }
        if (value3 == 2) {
            RAM8(0xE406) = 0x82;
            RAM8(0xE006) = 0x82;
            RAM8(0xE00A) = 8;
            RAM8(0xE40A) = 0x12;
            r->x = value;
            r->c = value3 >= 2;
            RETURN_RTS(c);
        }
        RAM8(0xE206) = 0x82;
        RAM8(0xE006) = 0x82;
        RAM8(0xE00A) = 8;
        RAM8(0xE20A) = 0x12;
        r->x = value;
        r->c = value3 >= 2;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x00E1);
    if (value4 != 0) {
        RAM8(0x0000 + sp0) = value4;
        RAM8(0x00FF) = 0x20;
        if (value4 >= 5) {
            uint16_t y5;
            bool carry4;
            if (value4 == 0x0B) {
                y5 = 0x8200;
                carry4 = value4 >= 0x0B;
            } else {
                uint16_t y4;
                bool carry3;
                if (value4 == 0x0C) {
                    y4 = 0x0200;
                    carry3 = value4 >= 0x0C;
                } else {
                    uint16_t y3;
                    bool carry2;
                    if (value4 == 0x0D) {
                        y3 = 0x0282;
                        carry2 = value4 >= 0x0D;
                    } else {
                        uint16_t y2;
                        bool carry1;
                        if (value4 == 0x0E) {
                            y2 = 0x8202;
                            carry1 = value4 >= 0x0E;
                        } else {
                            uint16_t y1;
                            if (value4 == 0x0F) {
                                y1 = 0x0202;
                            } else {
                                y1 = 0x8282;
                            }
                            y2 = y1;
                            carry1 = value4 >= 0x0F;
                        }
                        y3 = y2;
                        carry2 = carry1;
                    }
                    y4 = y3;
                    carry3 = carry2;
                }
                y5 = y4;
                carry4 = carry3;
            }
            RAM16_SET(0xE006, y5);
            RAM16_SET(0xE206, y5);
            RAM16_SET(0xE406, y5);
            RAM8(0xE00A) = 0x0C;
            RAM8(0xE20A) = 0x0C;
            RAM8(0xE40A) = 0x0C;
            r->a = (r->a & 0x00FF) | ((y5 >> 8) << 8);
            r->x = value;
            r->y = y5;
            r->c = carry4;
            RETURN_RTS(c);
        }
        uint8_t value5 = RAM8(0x00E0);
        uint8_t a30;
        uint8_t a_hi27;
        uint16_t x11;
        bool carry21;
        bool overflow17;
        if (value5 & 0x80) {
            uint8_t a10;
            uint8_t a_hi8;
            uint16_t x3;
            bool carry9;
            bool overflow5;
            if ((value5 & 0x60) != 0) {
                uint8_t a7;
                uint8_t a_hi5;
                uint16_t x2;
                bool carry7;
                bool overflow3;
                if ((value5 & 0x60) != 0x20) {
                    uint8_t a5;
                    uint16_t x1;
                    bool carry6;
                    bool overflow2;
                    if ((value5 & 0x60) != 0x40) {
                        uint16_t value6 = RAM16(0x00D4);
                        uint8_t value7 = RAM8(0xE00B + value6);
                        uint16_t value8 = RAM16(0x00A8);
                        uint8_t a2;
                        uint8_t a_hi1;
                        if (!(value7 & 0x80)) {
                            a2 = (uint8_t)value8;
                            a_hi1 = value8 >> 8;
                        } else {
                            uint16_t value9 = RAM16(0x00AC);
                            a2 = (uint8_t)value9;
                            a_hi1 = value9 >> 8;
                        }
                        uint16_t value10 = RAM16(0x00C0);
                        uint8_t a3;
                        uint8_t a_hi2;
                        bool carry5;
                        bool overflow1;
                        if ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) < value10) {
                            a3 = (uint8_t)(((a_hi1 << 8) | a2) + 0x0100);
                            a_hi2 = (uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >> 8;
                            carry5 = (uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >= value10;
                            overflow1 = ((((a_hi1 << 8) | a2) ^ (uint16_t)(((a_hi1 << 8) | a2) + 0x0100)) & ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) ^ 0x0100) & 0x8000) != 0;
                        } else {
                            a3 = (uint8_t)((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) - value10 - ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >= value10 ^ 1));
                            a_hi2 = (uint16_t)((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) - value10 - ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >= value10 ^ 1)) >> 8;
                            carry5 = (uint16_t)(((a_hi1 << 8) | a2) + 0x0100) - value10 >= ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >= value10 ^ 1);
                            overflow1 = (((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) ^ value10) & ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) ^ (uint16_t)((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) - value10 - ((uint16_t)(((a_hi1 << 8) | a2) + 0x0100) >= value10 ^ 1))) & 0x8000) != 0;
                        }
                        RAM16_SET(0xE002, (a_hi2 << 8) | a3);
                        RAM16_SET(0xE202, (a_hi2 << 8) | a3);
                        RAM16_SET(0xE402, (a_hi2 << 8) | a3);
                        a5 = 0x82;
                        x1 = value6;
                        carry6 = carry5;
                        overflow2 = overflow1;
                    } else {
                        uint16_t value11 = RAM16(0x00D4);
                        uint8_t value12 = RAM8(0xE00B + value11);
                        uint16_t value13 = RAM16(0x00A8);
                        uint8_t a4;
                        uint8_t a_hi3;
                        if (!(value12 & 0x80)) {
                            a4 = (uint8_t)value13;
                            a_hi3 = value13 >> 8;
                        } else {
                            uint16_t value14 = RAM16(0x00AC);
                            a4 = (uint8_t)value14;
                            a_hi3 = value14 >> 8;
                        }
                        RAM16_SET(0xE002, (a_hi3 << 8) | a4);
                        RAM16_SET(0xE202, (a_hi3 << 8) | a4);
                        RAM16_SET(0xE402, (a_hi3 << 8) | a4);
                        a5 = 2;
                        x1 = value11;
                        carry6 = value12 & 0x80;
                        overflow2 = overflow;
                    }
                    a7 = a5;
                    a_hi5 = 0;
                    x2 = x1;
                    carry7 = carry6;
                    overflow3 = overflow2;
                } else {
                    uint16_t value15 = RAM16(0x00D4);
                    uint8_t value16 = RAM8(0xE00B + value15);
                    uint16_t value17 = RAM16(0x00AA);
                    uint8_t a6;
                    uint8_t a_hi4;
                    if (!(value16 & 0x80)) {
                        a6 = (uint8_t)value17;
                        a_hi4 = value17 >> 8;
                    } else {
                        uint16_t value18 = RAM16(0x00AE);
                        a6 = (uint8_t)value18;
                        a_hi4 = value18 >> 8;
                    }
                    RAM16_SET(0xE004, (a_hi4 << 8) | a6);
                    RAM16_SET(0xE204, (a_hi4 << 8) | a6);
                    RAM16_SET(0xE404, (a_hi4 << 8) | a6);
                    a7 = 0;
                    a_hi5 = 2;
                    x2 = value15;
                    carry7 = value16 & 0x80;
                    overflow3 = overflow;
                }
                a10 = a7;
                a_hi8 = a_hi5;
                x3 = x2;
                carry9 = carry7;
                overflow5 = overflow3;
            } else {
                uint16_t value19 = RAM16(0x00D4);
                uint8_t value20 = RAM8(0xE00B + value19);
                uint16_t value21 = RAM16(0x00AA);
                uint8_t a8;
                uint8_t a_hi6;
                if (!(value20 & 0x80)) {
                    a8 = (uint8_t)value21;
                    a_hi6 = value21 >> 8;
                } else {
                    uint16_t value22 = RAM16(0x00AE);
                    a8 = (uint8_t)value22;
                    a_hi6 = value22 >> 8;
                }
                uint16_t value23 = RAM16(0x00C2);
                uint8_t a9;
                uint8_t a_hi7;
                bool carry8;
                bool overflow4;
                if ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) < value23) {
                    a9 = (uint8_t)(((a_hi6 << 8) | a8) + 0xE0);
                    a_hi7 = (uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >> 8;
                    carry8 = (uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >= value23;
                    overflow4 = ((((a_hi6 << 8) | a8) ^ (uint16_t)(((a_hi6 << 8) | a8) + 0xE0)) & ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) ^ 0xE0) & 0x8000) != 0;
                } else {
                    a9 = (uint8_t)((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) - value23 - ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >= value23 ^ 1));
                    a_hi7 = (uint16_t)((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) - value23 - ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >= value23 ^ 1)) >> 8;
                    carry8 = (uint16_t)(((a_hi6 << 8) | a8) + 0xE0) - value23 >= ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >= value23 ^ 1);
                    overflow4 = (((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) ^ value23) & ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) ^ (uint16_t)((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) - value23 - ((uint16_t)(((a_hi6 << 8) | a8) + 0xE0) >= value23 ^ 1))) & 0x8000) != 0;
                }
                RAM16_SET(0xE004, (a_hi7 << 8) | a9);
                RAM16_SET(0xE204, (a_hi7 << 8) | a9);
                RAM16_SET(0xE404, (a_hi7 << 8) | a9);
                a10 = 0;
                a_hi8 = 0x82;
                x3 = value19;
                carry9 = carry8;
                overflow5 = overflow4;
            }
            a30 = a10;
            a_hi27 = a_hi8;
            x11 = x3;
            carry21 = carry9;
            overflow17 = overflow5;
        } else {
            uint8_t value24 = RAM8(0xE010 + value);
            uint8_t a29;
            uint8_t a_hi26;
            uint16_t x10;
            bool carry20;
            bool overflow16;
            if (value24 & 0x80) {
                uint16_t value25 = RAM16(0x00D4);
                uint8_t value26 = RAM8(0xE00B + value25);
                uint16_t value27 = RAM16(0x00A8);
                uint8_t a11;
                uint8_t a_hi9;
                if (!(value26 & 0x80)) {
                    a11 = (uint8_t)value27;
                    a_hi9 = value27 >> 8;
                } else {
                    uint16_t value28 = RAM16(0x00AC);
                    a11 = (uint8_t)value28;
                    a_hi9 = value28 >> 8;
                }
                uint16_t value29 = RAM16(0x00C0);
                uint8_t a12;
                uint8_t a_hi10;
                bool carry10;
                bool overflow6;
                if ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) < value29) {
                    a12 = (uint8_t)(((a_hi9 << 8) | a11) + 0x0100);
                    a_hi10 = (uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >> 8;
                    carry10 = (uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >= value29;
                    overflow6 = ((((a_hi9 << 8) | a11) ^ (uint16_t)(((a_hi9 << 8) | a11) + 0x0100)) & ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) ^ 0x0100) & 0x8000) != 0;
                } else {
                    a12 = (uint8_t)((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) - value29 - ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >= value29 ^ 1));
                    a_hi10 = (uint16_t)((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) - value29 - ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >= value29 ^ 1)) >> 8;
                    carry10 = (uint16_t)(((a_hi9 << 8) | a11) + 0x0100) - value29 >= ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >= value29 ^ 1);
                    overflow6 = (((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) ^ value29) & ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) ^ (uint16_t)((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) - value29 - ((uint16_t)(((a_hi9 << 8) | a11) + 0x0100) >= value29 ^ 1))) & 0x8000) != 0;
                }
                RAM16_SET(0xE002, (a_hi10 << 8) | a12);
                RAM16_SET(0xE202, (a_hi10 << 8) | a12);
                RAM16_SET(0xE402, (a_hi10 << 8) | a12);
                a29 = 0x82;
                a_hi26 = 0;
                x10 = value25;
                carry20 = carry10;
                overflow16 = overflow6;
            } else {
                uint8_t a28;
                uint8_t a_hi25;
                uint16_t x9;
                bool carry19;
                bool overflow15;
                if (value24 == 0) {
                    uint16_t value30 = RAM16(0x00D4);
                    uint8_t value31 = RAM8(0xE00B + value30);
                    uint16_t value32 = RAM16(0x00AA);
                    uint8_t a13;
                    uint8_t a_hi11;
                    if (!(value31 & 0x80)) {
                        a13 = (uint8_t)value32;
                        a_hi11 = value32 >> 8;
                    } else {
                        uint16_t value33 = RAM16(0x00AE);
                        a13 = (uint8_t)value33;
                        a_hi11 = value33 >> 8;
                    }
                    uint16_t value34 = RAM16(0x00C2);
                    uint8_t a14;
                    uint8_t a_hi12;
                    bool carry11;
                    bool overflow7;
                    if ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) < value34) {
                        a14 = (uint8_t)(((a_hi11 << 8) | a13) + 0xE0);
                        a_hi12 = (uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >> 8;
                        carry11 = (uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >= value34;
                        overflow7 = ((((a_hi11 << 8) | a13) ^ (uint16_t)(((a_hi11 << 8) | a13) + 0xE0)) & ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) ^ 0xE0) & 0x8000) != 0;
                    } else {
                        a14 = (uint8_t)((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) - value34 - ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >= value34 ^ 1));
                        a_hi12 = (uint16_t)((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) - value34 - ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >= value34 ^ 1)) >> 8;
                        carry11 = (uint16_t)(((a_hi11 << 8) | a13) + 0xE0) - value34 >= ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >= value34 ^ 1);
                        overflow7 = (((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) ^ value34) & ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) ^ (uint16_t)((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) - value34 - ((uint16_t)(((a_hi11 << 8) | a13) + 0xE0) >= value34 ^ 1))) & 0x8000) != 0;
                    }
                    RAM16_SET(0xE004, (a_hi12 << 8) | a14);
                    RAM16_SET(0xE204, (a_hi12 << 8) | a14);
                    RAM16_SET(0xE404, (a_hi12 << 8) | a14);
                    a28 = 0;
                    a_hi25 = 0x82;
                    x9 = value30;
                    carry19 = carry11;
                    overflow15 = overflow7;
                } else {
                    uint8_t a27;
                    uint8_t a_hi24;
                    uint16_t x8;
                    bool carry18;
                    bool overflow14;
                    if (value24 & 0x01) {
                        uint16_t value35 = RAM16(0x00D4);
                        uint8_t value36 = RAM8(0xE00B + value35);
                        uint16_t value37 = RAM16(0x00AA);
                        uint8_t a15;
                        uint8_t a_hi13;
                        if (!(value36 & 0x80)) {
                            a15 = (uint8_t)value37;
                            a_hi13 = value37 >> 8;
                        } else {
                            uint16_t value38 = RAM16(0x00AE);
                            a15 = (uint8_t)value38;
                            a_hi13 = value38 >> 8;
                        }
                        RAM16_SET(0xE004, (a_hi13 << 8) | a15);
                        RAM16_SET(0xE204, (a_hi13 << 8) | a15);
                        RAM16_SET(0xE404, (a_hi13 << 8) | a15);
                        a27 = 0;
                        a_hi24 = 2;
                        x8 = value35;
                        carry18 = value36 & 0x80;
                        overflow14 = overflow;
                    } else {
                        uint8_t a26;
                        uint8_t a_hi23;
                        uint16_t x7;
                        bool carry17;
                        bool overflow13;
                        if (!(value24 & 0x01)) {
                            uint16_t value39 = RAM16(0x00D4);
                            uint8_t value40 = RAM8(0xE00B + value39);
                            uint16_t value41 = RAM16(0x00A8);
                            uint8_t a16;
                            uint8_t a_hi14;
                            if (!(value40 & 0x80)) {
                                a16 = (uint8_t)value41;
                                a_hi14 = value41 >> 8;
                            } else {
                                uint16_t value42 = RAM16(0x00AC);
                                a16 = (uint8_t)value42;
                                a_hi14 = value42 >> 8;
                            }
                            RAM16_SET(0xE002, (a_hi14 << 8) | a16);
                            RAM16_SET(0xE202, (a_hi14 << 8) | a16);
                            RAM16_SET(0xE402, (a_hi14 << 8) | a16);
                            a26 = 2;
                            a_hi23 = 0;
                            x7 = value39;
                            carry17 = value40 & 0x80;
                            overflow13 = overflow;
                        } else {
                            uint8_t a25;
                            uint8_t a_hi22;
                            uint16_t x6;
                            bool carry16;
                            bool overflow12;
                            if (((value24 >> 1) & 0x60) != 0) {
                                uint8_t a22;
                                uint8_t a_hi19;
                                uint16_t x5;
                                bool carry14;
                                bool overflow10;
                                if (((value24 >> 1) & 0x60) != 0x20) {
                                    uint8_t a20;
                                    uint16_t x4;
                                    bool carry13;
                                    bool overflow9;
                                    if (((value24 >> 1) & 0x60) != 0x40) {
                                        uint16_t value43 = RAM16(0x00D4);
                                        uint8_t value44 = RAM8(0xE00B + value43);
                                        uint16_t value45 = RAM16(0x00A8);
                                        uint8_t a17;
                                        uint8_t a_hi15;
                                        if (!(value44 & 0x80)) {
                                            a17 = (uint8_t)value45;
                                            a_hi15 = value45 >> 8;
                                        } else {
                                            uint16_t value46 = RAM16(0x00AC);
                                            a17 = (uint8_t)value46;
                                            a_hi15 = value46 >> 8;
                                        }
                                        uint16_t value47 = RAM16(0x00C0);
                                        uint8_t a18;
                                        uint8_t a_hi16;
                                        bool carry12;
                                        bool overflow8;
                                        if ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) < value47) {
                                            a18 = (uint8_t)(((a_hi15 << 8) | a17) + 0x0100);
                                            a_hi16 = (uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >> 8;
                                            carry12 = (uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >= value47;
                                            overflow8 = ((((a_hi15 << 8) | a17) ^ (uint16_t)(((a_hi15 << 8) | a17) + 0x0100)) & ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) ^ 0x0100) & 0x8000) != 0;
                                        } else {
                                            a18 = (uint8_t)((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) - value47 - ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >= value47 ^ 1));
                                            a_hi16 = (uint16_t)((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) - value47 - ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >= value47 ^ 1)) >> 8;
                                            carry12 = (uint16_t)(((a_hi15 << 8) | a17) + 0x0100) - value47 >= ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >= value47 ^ 1);
                                            overflow8 = (((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) ^ value47) & ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) ^ (uint16_t)((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) - value47 - ((uint16_t)(((a_hi15 << 8) | a17) + 0x0100) >= value47 ^ 1))) & 0x8000) != 0;
                                        }
                                        RAM16_SET(0xE002, (a_hi16 << 8) | a18);
                                        RAM16_SET(0xE202, (a_hi16 << 8) | a18);
                                        RAM16_SET(0xE402, (a_hi16 << 8) | a18);
                                        a20 = 0x82;
                                        x4 = value43;
                                        carry13 = carry12;
                                        overflow9 = overflow8;
                                    } else {
                                        uint16_t value48 = RAM16(0x00D4);
                                        uint8_t value49 = RAM8(0xE00B + value48);
                                        uint16_t value50 = RAM16(0x00A8);
                                        uint8_t a19;
                                        uint8_t a_hi17;
                                        if (!(value49 & 0x80)) {
                                            a19 = (uint8_t)value50;
                                            a_hi17 = value50 >> 8;
                                        } else {
                                            uint16_t value51 = RAM16(0x00AC);
                                            a19 = (uint8_t)value51;
                                            a_hi17 = value51 >> 8;
                                        }
                                        RAM16_SET(0xE002, (a_hi17 << 8) | a19);
                                        RAM16_SET(0xE202, (a_hi17 << 8) | a19);
                                        RAM16_SET(0xE402, (a_hi17 << 8) | a19);
                                        a20 = 2;
                                        x4 = value48;
                                        carry13 = value49 & 0x80;
                                        overflow9 = overflow;
                                    }
                                    a22 = a20;
                                    a_hi19 = 0;
                                    x5 = x4;
                                    carry14 = carry13;
                                    overflow10 = overflow9;
                                } else {
                                    uint16_t value52 = RAM16(0x00D4);
                                    uint8_t value53 = RAM8(0xE00B + value52);
                                    uint16_t value54 = RAM16(0x00AA);
                                    uint8_t a21;
                                    uint8_t a_hi18;
                                    if (!(value53 & 0x80)) {
                                        a21 = (uint8_t)value54;
                                        a_hi18 = value54 >> 8;
                                    } else {
                                        uint16_t value55 = RAM16(0x00AE);
                                        a21 = (uint8_t)value55;
                                        a_hi18 = value55 >> 8;
                                    }
                                    RAM16_SET(0xE004, (a_hi18 << 8) | a21);
                                    RAM16_SET(0xE204, (a_hi18 << 8) | a21);
                                    RAM16_SET(0xE404, (a_hi18 << 8) | a21);
                                    a22 = 0;
                                    a_hi19 = 2;
                                    x5 = value52;
                                    carry14 = value53 & 0x80;
                                    overflow10 = overflow;
                                }
                                a25 = a22;
                                a_hi22 = a_hi19;
                                x6 = x5;
                                carry16 = carry14;
                                overflow12 = overflow10;
                            } else {
                                uint16_t value56 = RAM16(0x00D4);
                                uint8_t value57 = RAM8(0xE00B + value56);
                                uint16_t value58 = RAM16(0x00AA);
                                uint8_t a23;
                                uint8_t a_hi20;
                                if (!(value57 & 0x80)) {
                                    a23 = (uint8_t)value58;
                                    a_hi20 = value58 >> 8;
                                } else {
                                    uint16_t value59 = RAM16(0x00AE);
                                    a23 = (uint8_t)value59;
                                    a_hi20 = value59 >> 8;
                                }
                                uint16_t value60 = RAM16(0x00C2);
                                uint8_t a24;
                                uint8_t a_hi21;
                                bool carry15;
                                bool overflow11;
                                if ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) < value60) {
                                    a24 = (uint8_t)(((a_hi20 << 8) | a23) + 0xE0);
                                    a_hi21 = (uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >> 8;
                                    carry15 = (uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >= value60;
                                    overflow11 = ((((a_hi20 << 8) | a23) ^ (uint16_t)(((a_hi20 << 8) | a23) + 0xE0)) & ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) ^ 0xE0) & 0x8000) != 0;
                                } else {
                                    a24 = (uint8_t)((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) - value60 - ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >= value60 ^ 1));
                                    a_hi21 = (uint16_t)((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) - value60 - ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >= value60 ^ 1)) >> 8;
                                    carry15 = (uint16_t)(((a_hi20 << 8) | a23) + 0xE0) - value60 >= ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >= value60 ^ 1);
                                    overflow11 = (((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) ^ value60) & ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) ^ (uint16_t)((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) - value60 - ((uint16_t)(((a_hi20 << 8) | a23) + 0xE0) >= value60 ^ 1))) & 0x8000) != 0;
                                }
                                RAM16_SET(0xE004, (a_hi21 << 8) | a24);
                                RAM16_SET(0xE204, (a_hi21 << 8) | a24);
                                RAM16_SET(0xE404, (a_hi21 << 8) | a24);
                                a25 = 0;
                                a_hi22 = 0x82;
                                x6 = value56;
                                carry16 = carry15;
                                overflow12 = overflow11;
                            }
                            a26 = a25;
                            a_hi23 = a_hi22;
                            x7 = x6;
                            carry17 = carry16;
                            overflow13 = overflow12;
                        }
                        a27 = a26;
                        a_hi24 = a_hi23;
                        x8 = x7;
                        carry18 = carry17;
                        overflow14 = overflow13;
                    }
                    a28 = a27;
                    a_hi25 = a_hi24;
                    x9 = x8;
                    carry19 = carry18;
                    overflow15 = overflow14;
                }
                a29 = a28;
                a_hi26 = a_hi25;
                x10 = x9;
                carry20 = carry19;
                overflow16 = overflow15;
            }
            a30 = a29;
            a_hi27 = a_hi26;
            x11 = x10;
            carry21 = carry20;
            overflow17 = overflow16;
        }
        RAM16_SET(0xE006, (a_hi27 << 8) | a30);
        RAM16_SET(0xE206, (a_hi27 << 8) | a30);
        RAM16_SET(0xE406, (a_hi27 << 8) | a30);
        RAM8(0xE00A) = 0x24;
        RAM8(0xE20A) = 0x24;
        RAM8(0xE40A) = 0x24;
        r->a = (r->a & 0x00FF) | (a_hi27 << 8);
        r->x = x11;
        r->c = carry21;
        r->v = overflow17;
        RETURN_RTS(c);
    }
    r->x = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DD66, SOM_RTS, "gen", prepare_party_entry_walk, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 420, 168)
