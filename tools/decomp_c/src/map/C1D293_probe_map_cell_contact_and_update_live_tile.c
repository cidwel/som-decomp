#include "som_c.h"

/* C1D293 probe_map_cell_contact_and_update_live_tile   [class C, 407 bytes, 220 instructions]
 * Source: src/rom/probe_map_cell_contact_and_update_live_tile.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void probe_map_cell_contact_and_update_live_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t a_d2de = 0;
    uint8_t a_hi_d2de = 0;
    uint16_t x_d2de = 0;
    RAM16_SET(0x0004, RAM16(0xE0C0 + x));
    RAM16_SET(0x0006, 0x1010);
    uint16_t value2 = RAM16(0x0056);
    if ((value2 & 0x0F) == 0) {
        uint16_t value3 = RAM16(0x0006);
        a_d2de = (uint8_t)(((value3 >> 9) ^ 0xFF) + 1);
        a_hi_d2de = (uint8_t)((((uint8_t)value3 >> 1) ^ 0xFF) + 1);
        x_d2de = x;
        goto shared_D2DE;
    }
    if ((uint16_t)((value2 & 0x0F) - 1) == 0) {
        uint16_t value4 = RAM16(0x0006);
        a_d2de = (uint8_t)(((value4 >> 9) ^ 0xFF) + 1);
        a_hi_d2de = (uint8_t)value4 >> 1;
        x_d2de = x;
        goto shared_D2DE;
    }
    if ((uint16_t)((value2 & 0x0F) - 2) == 0) {
        uint16_t value5 = RAM16(0x0006);
        a_d2de = value5 >> 9;
        a_hi_d2de = (uint8_t)((((uint8_t)value5 >> 1) ^ 0xFF) + 1);
        x_d2de = x;
        goto shared_D2DE;
    }
    if ((uint16_t)((value2 & 0x0F) - 3) == 0) {
        r->mf = false;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x0006);
    a_d2de = value6 >> 9;
    a_hi_d2de = (uint8_t)value6 >> 1;
    x_d2de = x;
    shared_D2DE:;
    uint8_t value7 = RAM8(0x0005);
    RAM8(0x0005) = (uint8_t)(a_d2de + value7);
    RAM8(0x0004) = (uint8_t)(a_hi_d2de + RAM8(0x0004));
    RAM8(0x0002) = 0x7F;
    RAM8(0x0008) = 0x7F;
    RAM8(0x0082) = 1;
    uint8_t value9 = RAM8(0xE00B + x_d2de);
    RAM16_SET(0x0006, 0xB800);
    uint16_t y1;
    if (!(value9 & 0x80)) {
        y1 = 0;
    } else {
        RAM8(0x0082) = 0x80;
        RAM16_SET(0x0006, 0xBC00);
        y1 = 0x4000;
    }
    RAM16_SET(0x0000, y1);
    uint8_t value10 = RAM8(0x0004);
    uint8_t a3;
    uint8_t a_hi3;
    if (value10 & 0x80) {
        uint16_t value11 = RAM16(0xE002 + x_d2de);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)((((uint8_t)(a_d2de + value7) << 8) | value10 | 0xFF00) + value11) & 0x8000)) {
            a1 = (uint8_t)((((uint8_t)(a_d2de + value7) << 8) | value10 | 0xFF00) + value11);
            a_hi1 = (uint16_t)((((uint8_t)(a_d2de + value7) << 8) | value10 | 0xFF00) + value11) >> 8;
        } else {
            uint16_t value12 = RAM16(0x00C0);
            a1 = (uint8_t)((uint16_t)((((uint8_t)(a_d2de + value7) << 8) | value10 | 0xFF00) + value11) + value12);
            a_hi1 = (uint16_t)((uint16_t)((((uint8_t)(a_d2de + value7) << 8) | value10 | 0xFF00) + value11) + value12) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value13 = RAM16(0xE002 + x_d2de);
        uint16_t value14 = RAM16(0x00C0);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) < value14) {
            a2 = (uint8_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13);
            a_hi2 = (uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) - value14 - ((uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) >= value14 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) - value14 - ((uint16_t)(((((uint8_t)(a_d2de + value7) << 8) | value10) & 0xFF) + value13) >= value14 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    RAM16_SET(0x000A, ((a_hi3 << 8) | a3) >> 4);
    uint8_t value15 = RAM8(0x0005);
    uint8_t a6;
    uint8_t a_hi6;
    if (value15 & 0x80) {
        uint16_t value16 = RAM16(0xE004 + x_d2de);
        uint8_t a4;
        uint8_t a_hi4;
        if (!((uint16_t)(((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15 | 0xFF00) + value16) & 0x8000)) {
            a4 = (uint8_t)(((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15 | 0xFF00) + value16);
            a_hi4 = (uint16_t)(((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15 | 0xFF00) + value16) >> 8;
        } else {
            uint16_t value17 = RAM16(0x00C2);
            a4 = (uint8_t)((uint16_t)(((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15 | 0xFF00) + value16) + value17);
            a_hi4 = (uint16_t)((uint16_t)(((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15 | 0xFF00) + value16) + value17) >> 8;
        }
        a6 = a4;
        a_hi6 = a_hi4;
    } else {
        uint16_t value18 = RAM16(0xE004 + x_d2de);
        uint16_t value19 = RAM16(0x00C2);
        uint8_t a5;
        uint8_t a_hi5;
        if ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) < value19) {
            a5 = (uint8_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) >> 8;
        } else {
            a5 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) - value19 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) >= value19 ^ 1));
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) - value19 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value15) & 0xFF) + value18) >= value19 ^ 1)) >> 8;
        }
        a6 = a5;
        a_hi6 = a_hi5;
    }
    RAM16_SET(0x0004, (a_hi6 << 8) | a6);
    RAM16_SET(0x0000, (uint16_t)((((((a_hi6 << 8) | a6) & 0x0FF0) << 1 << 1 << 1) | RAM16(0x000A)) + RAM16(0x0000)));
    uint16_t value22 = BUS16(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000));
    uint16_t value23 = BUS16(c, (RAM8(0x0008) << 0x10) + RAM16(0x0006) + (((value22 & 0xFF) << 1 << 1) + 2));
    RAM8(0x000A) = (uint8_t)value23;
    if (((uint8_t)value23 & 0xF0) == 0xC0) {
        uint8_t value24 = RAM8(0x000A);
        if ((value24 & 0x0F) < 8) {
            if ((value24 & 0x0F) != RAM8(0xE068 + x_d2de)) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
            uint8_t value26 = RAM8(0x0082);
            uint16_t value27 = RAM16(0x0004);
            uint8_t a9;
            uint8_t a_hi9;
            if (!(value26 & 0x80)) {
                uint16_t value28 = RAM16(0x00AA);
                uint8_t a7;
                uint8_t a_hi7;
                if (value27 >= value28) {
                    a7 = (uint8_t)(value27 - value28);
                    a_hi7 = (uint16_t)(value27 - value28) >> 8;
                } else {
                    uint16_t value29 = RAM16(0x00C6);
                    a7 = (uint8_t)((uint16_t)(value27 - value28) + value29 + (value27 >= value28));
                    a_hi7 = (uint16_t)((uint16_t)(value27 - value28) + value29 + (value27 >= value28)) >> 8;
                }
                a9 = a7;
                a_hi9 = a_hi7;
            } else {
                uint16_t value30 = RAM16(0x00AE);
                uint8_t a8;
                uint8_t a_hi8;
                if (value27 >= value30) {
                    a8 = (uint8_t)(value27 - value30);
                    a_hi8 = (uint16_t)(value27 - value30) >> 8;
                } else {
                    uint16_t value31 = RAM16(0x00C6);
                    a8 = (uint8_t)((uint16_t)(value27 - value30) + value31 + (value27 >= value30));
                    a_hi8 = (uint16_t)((uint16_t)(value27 - value30) + value31 + (value27 >= value30)) >> 8;
                }
                a9 = a8;
                a_hi9 = a_hi8;
            }
            RAM8(0x0083) = a9;
            if (value23 >> 8 != 0xC1) {
                uint8_t value32 = RAM8(0x000A);
                r->a = (a_hi9 << 8) | (uint8_t)((value32 & 0x0F) + 0xD8);
                r->x = x_d2de;
                r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                r->c = (value32 & 0x0F) + 0xD8 > 0xFF;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
            }
            r->x = x_d2de;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value24 & 0x0F) == 8) {
            uint8_t value33 = RAM8(0xE068 + x_d2de);
            if (value33 == 1) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value34 = RAM8(0x0082);
                uint16_t value35 = RAM16(0x0004);
                uint8_t a12;
                uint8_t a_hi12;
                if (!(value34 & 0x80)) {
                    uint16_t value36 = RAM16(0x00AA);
                    uint8_t a10;
                    uint8_t a_hi10;
                    if (value35 >= value36) {
                        a10 = (uint8_t)(value35 - value36);
                        a_hi10 = (uint16_t)(value35 - value36) >> 8;
                    } else {
                        uint16_t value37 = RAM16(0x00C6);
                        a10 = (uint8_t)((uint16_t)(value35 - value36) + value37 + (value35 >= value36));
                        a_hi10 = (uint16_t)((uint16_t)(value35 - value36) + value37 + (value35 >= value36)) >> 8;
                    }
                    a12 = a10;
                    a_hi12 = a_hi10;
                } else {
                    uint16_t value38 = RAM16(0x00AE);
                    uint8_t a11;
                    uint8_t a_hi11;
                    if (value35 >= value38) {
                        a11 = (uint8_t)(value35 - value38);
                        a_hi11 = (uint16_t)(value35 - value38) >> 8;
                    } else {
                        uint16_t value39 = RAM16(0x00C6);
                        a11 = (uint8_t)((uint16_t)(value35 - value38) + value39 + (value35 >= value38));
                        a_hi11 = (uint16_t)((uint16_t)(value35 - value38) + value39 + (value35 >= value38)) >> 8;
                    }
                    a12 = a11;
                    a_hi12 = a_hi11;
                }
                RAM8(0x0083) = a12;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value40 = RAM8(0x000A);
                    r->a = (a_hi12 << 8) | (uint8_t)((value40 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value40 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 == 2) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value41 = RAM8(0x0082);
                uint16_t value42 = RAM16(0x0004);
                uint8_t a15;
                uint8_t a_hi15;
                if (!(value41 & 0x80)) {
                    uint16_t value43 = RAM16(0x00AA);
                    uint8_t a13;
                    uint8_t a_hi13;
                    if (value42 >= value43) {
                        a13 = (uint8_t)(value42 - value43);
                        a_hi13 = (uint16_t)(value42 - value43) >> 8;
                    } else {
                        uint16_t value44 = RAM16(0x00C6);
                        a13 = (uint8_t)((uint16_t)(value42 - value43) + value44 + (value42 >= value43));
                        a_hi13 = (uint16_t)((uint16_t)(value42 - value43) + value44 + (value42 >= value43)) >> 8;
                    }
                    a15 = a13;
                    a_hi15 = a_hi13;
                } else {
                    uint16_t value45 = RAM16(0x00AE);
                    uint8_t a14;
                    uint8_t a_hi14;
                    if (value42 >= value45) {
                        a14 = (uint8_t)(value42 - value45);
                        a_hi14 = (uint16_t)(value42 - value45) >> 8;
                    } else {
                        uint16_t value46 = RAM16(0x00C6);
                        a14 = (uint8_t)((uint16_t)(value42 - value45) + value46 + (value42 >= value45));
                        a_hi14 = (uint16_t)((uint16_t)(value42 - value45) + value46 + (value42 >= value45)) >> 8;
                    }
                    a15 = a14;
                    a_hi15 = a_hi14;
                }
                RAM8(0x0083) = a15;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value47 = RAM8(0x000A);
                    r->a = (a_hi15 << 8) | (uint8_t)((value47 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value47 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 != 2) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 == 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value48 = RAM8(0x0082);
                uint16_t value49 = RAM16(0x0004);
                uint8_t a18;
                uint8_t a_hi18;
                if (!(value48 & 0x80)) {
                    uint16_t value50 = RAM16(0x00AA);
                    uint8_t a16;
                    uint8_t a_hi16;
                    if (value49 >= value50) {
                        a16 = (uint8_t)(value49 - value50);
                        a_hi16 = (uint16_t)(value49 - value50) >> 8;
                    } else {
                        uint16_t value51 = RAM16(0x00C6);
                        a16 = (uint8_t)((uint16_t)(value49 - value50) + value51 + (value49 >= value50));
                        a_hi16 = (uint16_t)((uint16_t)(value49 - value50) + value51 + (value49 >= value50)) >> 8;
                    }
                    a18 = a16;
                    a_hi18 = a_hi16;
                } else {
                    uint16_t value52 = RAM16(0x00AE);
                    uint8_t a17;
                    uint8_t a_hi17;
                    if (value49 >= value52) {
                        a17 = (uint8_t)(value49 - value52);
                        a_hi17 = (uint16_t)(value49 - value52) >> 8;
                    } else {
                        uint16_t value53 = RAM16(0x00C6);
                        a17 = (uint8_t)((uint16_t)(value49 - value52) + value53 + (value49 >= value52));
                        a_hi17 = (uint16_t)((uint16_t)(value49 - value52) + value53 + (value49 >= value52)) >> 8;
                    }
                    a18 = a17;
                    a_hi18 = a_hi17;
                }
                RAM8(0x0083) = a18;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value54 = RAM8(0x000A);
                    r->a = (a_hi18 << 8) | (uint8_t)((value54 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value54 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 == 4) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value55 = RAM8(0x0082);
                uint16_t value56 = RAM16(0x0004);
                uint8_t a21;
                uint8_t a_hi21;
                if (!(value55 & 0x80)) {
                    uint16_t value57 = RAM16(0x00AA);
                    uint8_t a19;
                    uint8_t a_hi19;
                    if (value56 >= value57) {
                        a19 = (uint8_t)(value56 - value57);
                        a_hi19 = (uint16_t)(value56 - value57) >> 8;
                    } else {
                        uint16_t value58 = RAM16(0x00C6);
                        a19 = (uint8_t)((uint16_t)(value56 - value57) + value58 + (value56 >= value57));
                        a_hi19 = (uint16_t)((uint16_t)(value56 - value57) + value58 + (value56 >= value57)) >> 8;
                    }
                    a21 = a19;
                    a_hi21 = a_hi19;
                } else {
                    uint16_t value59 = RAM16(0x00AE);
                    uint8_t a20;
                    uint8_t a_hi20;
                    if (value56 >= value59) {
                        a20 = (uint8_t)(value56 - value59);
                        a_hi20 = (uint16_t)(value56 - value59) >> 8;
                    } else {
                        uint16_t value60 = RAM16(0x00C6);
                        a20 = (uint8_t)((uint16_t)(value56 - value59) + value60 + (value56 >= value59));
                        a_hi20 = (uint16_t)((uint16_t)(value56 - value59) + value60 + (value56 >= value59)) >> 8;
                    }
                    a21 = a20;
                    a_hi21 = a_hi20;
                }
                RAM8(0x0083) = a21;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value61 = RAM8(0x000A);
                    r->a = (a_hi21 << 8) | (uint8_t)((value61 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value61 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 != 4) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 >= 5) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value62 = RAM8(0x0082);
                uint16_t value63 = RAM16(0x0004);
                uint8_t a24;
                uint8_t a_hi24;
                if (!(value62 & 0x80)) {
                    uint16_t value64 = RAM16(0x00AA);
                    uint8_t a22;
                    uint8_t a_hi22;
                    if (value63 >= value64) {
                        a22 = (uint8_t)(value63 - value64);
                        a_hi22 = (uint16_t)(value63 - value64) >> 8;
                    } else {
                        uint16_t value65 = RAM16(0x00C6);
                        a22 = (uint8_t)((uint16_t)(value63 - value64) + value65 + (value63 >= value64));
                        a_hi22 = (uint16_t)((uint16_t)(value63 - value64) + value65 + (value63 >= value64)) >> 8;
                    }
                    a24 = a22;
                    a_hi24 = a_hi22;
                } else {
                    uint16_t value66 = RAM16(0x00AE);
                    uint8_t a23;
                    uint8_t a_hi23;
                    if (value63 >= value66) {
                        a23 = (uint8_t)(value63 - value66);
                        a_hi23 = (uint16_t)(value63 - value66) >> 8;
                    } else {
                        uint16_t value67 = RAM16(0x00C6);
                        a23 = (uint8_t)((uint16_t)(value63 - value66) + value67 + (value63 >= value66));
                        a_hi23 = (uint16_t)((uint16_t)(value63 - value66) + value67 + (value63 >= value66)) >> 8;
                    }
                    a24 = a23;
                    a_hi24 = a_hi23;
                }
                RAM8(0x0083) = a24;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value68 = RAM8(0x000A);
                    r->a = (a_hi24 << 8) | (uint8_t)((value68 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value68 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 < 5) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 < 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value69 = RAM8(0x0082);
                uint16_t value70 = RAM16(0x0004);
                uint8_t a27;
                uint8_t a_hi27;
                if (!(value69 & 0x80)) {
                    uint16_t value71 = RAM16(0x00AA);
                    uint8_t a25;
                    uint8_t a_hi25;
                    if (value70 >= value71) {
                        a25 = (uint8_t)(value70 - value71);
                        a_hi25 = (uint16_t)(value70 - value71) >> 8;
                    } else {
                        uint16_t value72 = RAM16(0x00C6);
                        a25 = (uint8_t)((uint16_t)(value70 - value71) + value72 + (value70 >= value71));
                        a_hi25 = (uint16_t)((uint16_t)(value70 - value71) + value72 + (value70 >= value71)) >> 8;
                    }
                    a27 = a25;
                    a_hi27 = a_hi25;
                } else {
                    uint16_t value73 = RAM16(0x00AE);
                    uint8_t a26;
                    uint8_t a_hi26;
                    if (value70 >= value73) {
                        a26 = (uint8_t)(value70 - value73);
                        a_hi26 = (uint16_t)(value70 - value73) >> 8;
                    } else {
                        uint16_t value74 = RAM16(0x00C6);
                        a26 = (uint8_t)((uint16_t)(value70 - value73) + value74 + (value70 >= value73));
                        a_hi26 = (uint16_t)((uint16_t)(value70 - value73) + value74 + (value70 >= value73)) >> 8;
                    }
                    a27 = a26;
                    a_hi27 = a_hi26;
                }
                RAM8(0x0083) = a27;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value75 = RAM8(0x000A);
                    r->a = (a_hi27 << 8) | (uint8_t)((value75 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value75 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 >= 3) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value33 != value33) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
            uint8_t value76 = RAM8(0x0082);
            uint16_t value77 = RAM16(0x0004);
            uint8_t a30;
            uint8_t a_hi30;
            if (!(value76 & 0x80)) {
                uint16_t value78 = RAM16(0x00AA);
                uint8_t a28;
                uint8_t a_hi28;
                if (value77 >= value78) {
                    a28 = (uint8_t)(value77 - value78);
                    a_hi28 = (uint16_t)(value77 - value78) >> 8;
                } else {
                    uint16_t value79 = RAM16(0x00C6);
                    a28 = (uint8_t)((uint16_t)(value77 - value78) + value79 + (value77 >= value78));
                    a_hi28 = (uint16_t)((uint16_t)(value77 - value78) + value79 + (value77 >= value78)) >> 8;
                }
                a30 = a28;
                a_hi30 = a_hi28;
            } else {
                uint16_t value80 = RAM16(0x00AE);
                uint8_t a29;
                uint8_t a_hi29;
                if (value77 >= value80) {
                    a29 = (uint8_t)(value77 - value80);
                    a_hi29 = (uint16_t)(value77 - value80) >> 8;
                } else {
                    uint16_t value81 = RAM16(0x00C6);
                    a29 = (uint8_t)((uint16_t)(value77 - value80) + value81 + (value77 >= value80));
                    a_hi29 = (uint16_t)((uint16_t)(value77 - value80) + value81 + (value77 >= value80)) >> 8;
                }
                a30 = a29;
                a_hi30 = a_hi29;
            }
            RAM8(0x0083) = a30;
            if (value23 >> 8 != 0xC1) {
                uint8_t value82 = RAM8(0x000A);
                r->a = (a_hi30 << 8) | (uint8_t)((value82 & 0x0F) + 0xD8);
                r->x = x_d2de;
                r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                r->c = (value82 & 0x0F) + 0xD8 > 0xFF;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
            }
            r->x = x_d2de;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value24 & 0x0F) == 9) {
            uint8_t value83 = RAM8(0xE068 + x_d2de);
            if (value83 == 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value84 = RAM8(0x0082);
                uint16_t value85 = RAM16(0x0004);
                uint8_t a33;
                uint8_t a_hi33;
                if (!(value84 & 0x80)) {
                    uint16_t value86 = RAM16(0x00AA);
                    uint8_t a31;
                    uint8_t a_hi31;
                    if (value85 >= value86) {
                        a31 = (uint8_t)(value85 - value86);
                        a_hi31 = (uint16_t)(value85 - value86) >> 8;
                    } else {
                        uint16_t value87 = RAM16(0x00C6);
                        a31 = (uint8_t)((uint16_t)(value85 - value86) + value87 + (value85 >= value86));
                        a_hi31 = (uint16_t)((uint16_t)(value85 - value86) + value87 + (value85 >= value86)) >> 8;
                    }
                    a33 = a31;
                    a_hi33 = a_hi31;
                } else {
                    uint16_t value88 = RAM16(0x00AE);
                    uint8_t a32;
                    uint8_t a_hi32;
                    if (value85 >= value88) {
                        a32 = (uint8_t)(value85 - value88);
                        a_hi32 = (uint16_t)(value85 - value88) >> 8;
                    } else {
                        uint16_t value89 = RAM16(0x00C6);
                        a32 = (uint8_t)((uint16_t)(value85 - value88) + value89 + (value85 >= value88));
                        a_hi32 = (uint16_t)((uint16_t)(value85 - value88) + value89 + (value85 >= value88)) >> 8;
                    }
                    a33 = a32;
                    a_hi33 = a_hi32;
                }
                RAM8(0x0083) = a33;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value90 = RAM8(0x000A);
                    r->a = (a_hi33 << 8) | (uint8_t)((value90 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value90 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 == 4) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value91 = RAM8(0x0082);
                uint16_t value92 = RAM16(0x0004);
                uint8_t a36;
                uint8_t a_hi36;
                if (!(value91 & 0x80)) {
                    uint16_t value93 = RAM16(0x00AA);
                    uint8_t a34;
                    uint8_t a_hi34;
                    if (value92 >= value93) {
                        a34 = (uint8_t)(value92 - value93);
                        a_hi34 = (uint16_t)(value92 - value93) >> 8;
                    } else {
                        uint16_t value94 = RAM16(0x00C6);
                        a34 = (uint8_t)((uint16_t)(value92 - value93) + value94 + (value92 >= value93));
                        a_hi34 = (uint16_t)((uint16_t)(value92 - value93) + value94 + (value92 >= value93)) >> 8;
                    }
                    a36 = a34;
                    a_hi36 = a_hi34;
                } else {
                    uint16_t value95 = RAM16(0x00AE);
                    uint8_t a35;
                    uint8_t a_hi35;
                    if (value92 >= value95) {
                        a35 = (uint8_t)(value92 - value95);
                        a_hi35 = (uint16_t)(value92 - value95) >> 8;
                    } else {
                        uint16_t value96 = RAM16(0x00C6);
                        a35 = (uint8_t)((uint16_t)(value92 - value95) + value96 + (value92 >= value95));
                        a_hi35 = (uint16_t)((uint16_t)(value92 - value95) + value96 + (value92 >= value95)) >> 8;
                    }
                    a36 = a35;
                    a_hi36 = a_hi35;
                }
                RAM8(0x0083) = a36;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value97 = RAM8(0x000A);
                    r->a = (a_hi36 << 8) | (uint8_t)((value97 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value97 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 != 4) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 >= 5) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value98 = RAM8(0x0082);
                uint16_t value99 = RAM16(0x0004);
                uint8_t a39;
                uint8_t a_hi39;
                if (!(value98 & 0x80)) {
                    uint16_t value100 = RAM16(0x00AA);
                    uint8_t a37;
                    uint8_t a_hi37;
                    if (value99 >= value100) {
                        a37 = (uint8_t)(value99 - value100);
                        a_hi37 = (uint16_t)(value99 - value100) >> 8;
                    } else {
                        uint16_t value101 = RAM16(0x00C6);
                        a37 = (uint8_t)((uint16_t)(value99 - value100) + value101 + (value99 >= value100));
                        a_hi37 = (uint16_t)((uint16_t)(value99 - value100) + value101 + (value99 >= value100)) >> 8;
                    }
                    a39 = a37;
                    a_hi39 = a_hi37;
                } else {
                    uint16_t value102 = RAM16(0x00AE);
                    uint8_t a38;
                    uint8_t a_hi38;
                    if (value99 >= value102) {
                        a38 = (uint8_t)(value99 - value102);
                        a_hi38 = (uint16_t)(value99 - value102) >> 8;
                    } else {
                        uint16_t value103 = RAM16(0x00C6);
                        a38 = (uint8_t)((uint16_t)(value99 - value102) + value103 + (value99 >= value102));
                        a_hi38 = (uint16_t)((uint16_t)(value99 - value102) + value103 + (value99 >= value102)) >> 8;
                    }
                    a39 = a38;
                    a_hi39 = a_hi38;
                }
                RAM8(0x0083) = a39;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value104 = RAM8(0x000A);
                    r->a = (a_hi39 << 8) | (uint8_t)((value104 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value104 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 < 5) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 < 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value105 = RAM8(0x0082);
                uint16_t value106 = RAM16(0x0004);
                uint8_t a42;
                uint8_t a_hi42;
                if (!(value105 & 0x80)) {
                    uint16_t value107 = RAM16(0x00AA);
                    uint8_t a40;
                    uint8_t a_hi40;
                    if (value106 >= value107) {
                        a40 = (uint8_t)(value106 - value107);
                        a_hi40 = (uint16_t)(value106 - value107) >> 8;
                    } else {
                        uint16_t value108 = RAM16(0x00C6);
                        a40 = (uint8_t)((uint16_t)(value106 - value107) + value108 + (value106 >= value107));
                        a_hi40 = (uint16_t)((uint16_t)(value106 - value107) + value108 + (value106 >= value107)) >> 8;
                    }
                    a42 = a40;
                    a_hi42 = a_hi40;
                } else {
                    uint16_t value109 = RAM16(0x00AE);
                    uint8_t a41;
                    uint8_t a_hi41;
                    if (value106 >= value109) {
                        a41 = (uint8_t)(value106 - value109);
                        a_hi41 = (uint16_t)(value106 - value109) >> 8;
                    } else {
                        uint16_t value110 = RAM16(0x00C6);
                        a41 = (uint8_t)((uint16_t)(value106 - value109) + value110 + (value106 >= value109));
                        a_hi41 = (uint16_t)((uint16_t)(value106 - value109) + value110 + (value106 >= value109)) >> 8;
                    }
                    a42 = a41;
                    a_hi42 = a_hi41;
                }
                RAM8(0x0083) = a42;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value111 = RAM8(0x000A);
                    r->a = (a_hi42 << 8) | (uint8_t)((value111 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value111 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 >= 3) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value83 != value83) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
            uint8_t value112 = RAM8(0x0082);
            uint16_t value113 = RAM16(0x0004);
            uint8_t a45;
            uint8_t a_hi45;
            if (!(value112 & 0x80)) {
                uint16_t value114 = RAM16(0x00AA);
                uint8_t a43;
                uint8_t a_hi43;
                if (value113 >= value114) {
                    a43 = (uint8_t)(value113 - value114);
                    a_hi43 = (uint16_t)(value113 - value114) >> 8;
                } else {
                    uint16_t value115 = RAM16(0x00C6);
                    a43 = (uint8_t)((uint16_t)(value113 - value114) + value115 + (value113 >= value114));
                    a_hi43 = (uint16_t)((uint16_t)(value113 - value114) + value115 + (value113 >= value114)) >> 8;
                }
                a45 = a43;
                a_hi45 = a_hi43;
            } else {
                uint16_t value116 = RAM16(0x00AE);
                uint8_t a44;
                uint8_t a_hi44;
                if (value113 >= value116) {
                    a44 = (uint8_t)(value113 - value116);
                    a_hi44 = (uint16_t)(value113 - value116) >> 8;
                } else {
                    uint16_t value117 = RAM16(0x00C6);
                    a44 = (uint8_t)((uint16_t)(value113 - value116) + value117 + (value113 >= value116));
                    a_hi44 = (uint16_t)((uint16_t)(value113 - value116) + value117 + (value113 >= value116)) >> 8;
                }
                a45 = a44;
                a_hi45 = a_hi44;
            }
            RAM8(0x0083) = a45;
            if (value23 >> 8 != 0xC1) {
                uint8_t value118 = RAM8(0x000A);
                r->a = (a_hi45 << 8) | (uint8_t)((value118 & 0x0F) + 0xD8);
                r->x = x_d2de;
                r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                r->c = (value118 & 0x0F) + 0xD8 > 0xFF;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
            }
            r->x = x_d2de;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value24 & 0x0F) == 0x0A) {
            uint8_t value119 = RAM8(0xE068 + x_d2de);
            if (value119 >= 5) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value120 = RAM8(0x0082);
                uint16_t value121 = RAM16(0x0004);
                uint8_t a48;
                uint8_t a_hi48;
                if (!(value120 & 0x80)) {
                    uint16_t value122 = RAM16(0x00AA);
                    uint8_t a46;
                    uint8_t a_hi46;
                    if (value121 >= value122) {
                        a46 = (uint8_t)(value121 - value122);
                        a_hi46 = (uint16_t)(value121 - value122) >> 8;
                    } else {
                        uint16_t value123 = RAM16(0x00C6);
                        a46 = (uint8_t)((uint16_t)(value121 - value122) + value123 + (value121 >= value122));
                        a_hi46 = (uint16_t)((uint16_t)(value121 - value122) + value123 + (value121 >= value122)) >> 8;
                    }
                    a48 = a46;
                    a_hi48 = a_hi46;
                } else {
                    uint16_t value124 = RAM16(0x00AE);
                    uint8_t a47;
                    uint8_t a_hi47;
                    if (value121 >= value124) {
                        a47 = (uint8_t)(value121 - value124);
                        a_hi47 = (uint16_t)(value121 - value124) >> 8;
                    } else {
                        uint16_t value125 = RAM16(0x00C6);
                        a47 = (uint8_t)((uint16_t)(value121 - value124) + value125 + (value121 >= value124));
                        a_hi47 = (uint16_t)((uint16_t)(value121 - value124) + value125 + (value121 >= value124)) >> 8;
                    }
                    a48 = a47;
                    a_hi48 = a_hi47;
                }
                RAM8(0x0083) = a48;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value126 = RAM8(0x000A);
                    r->a = (a_hi48 << 8) | (uint8_t)((value126 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value126 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value119 < 5) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value119 < 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value127 = RAM8(0x0082);
                uint16_t value128 = RAM16(0x0004);
                uint8_t a51;
                uint8_t a_hi51;
                if (!(value127 & 0x80)) {
                    uint16_t value129 = RAM16(0x00AA);
                    uint8_t a49;
                    uint8_t a_hi49;
                    if (value128 >= value129) {
                        a49 = (uint8_t)(value128 - value129);
                        a_hi49 = (uint16_t)(value128 - value129) >> 8;
                    } else {
                        uint16_t value130 = RAM16(0x00C6);
                        a49 = (uint8_t)((uint16_t)(value128 - value129) + value130 + (value128 >= value129));
                        a_hi49 = (uint16_t)((uint16_t)(value128 - value129) + value130 + (value128 >= value129)) >> 8;
                    }
                    a51 = a49;
                    a_hi51 = a_hi49;
                } else {
                    uint16_t value131 = RAM16(0x00AE);
                    uint8_t a50;
                    uint8_t a_hi50;
                    if (value128 >= value131) {
                        a50 = (uint8_t)(value128 - value131);
                        a_hi50 = (uint16_t)(value128 - value131) >> 8;
                    } else {
                        uint16_t value132 = RAM16(0x00C6);
                        a50 = (uint8_t)((uint16_t)(value128 - value131) + value132 + (value128 >= value131));
                        a_hi50 = (uint16_t)((uint16_t)(value128 - value131) + value132 + (value128 >= value131)) >> 8;
                    }
                    a51 = a50;
                    a_hi51 = a_hi50;
                }
                RAM8(0x0083) = a51;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value133 = RAM8(0x000A);
                    r->a = (a_hi51 << 8) | (uint8_t)((value133 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value133 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value119 >= 3) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value119 != value119) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
            uint8_t value134 = RAM8(0x0082);
            uint16_t value135 = RAM16(0x0004);
            uint8_t a54;
            uint8_t a_hi54;
            if (!(value134 & 0x80)) {
                uint16_t value136 = RAM16(0x00AA);
                uint8_t a52;
                uint8_t a_hi52;
                if (value135 >= value136) {
                    a52 = (uint8_t)(value135 - value136);
                    a_hi52 = (uint16_t)(value135 - value136) >> 8;
                } else {
                    uint16_t value137 = RAM16(0x00C6);
                    a52 = (uint8_t)((uint16_t)(value135 - value136) + value137 + (value135 >= value136));
                    a_hi52 = (uint16_t)((uint16_t)(value135 - value136) + value137 + (value135 >= value136)) >> 8;
                }
                a54 = a52;
                a_hi54 = a_hi52;
            } else {
                uint16_t value138 = RAM16(0x00AE);
                uint8_t a53;
                uint8_t a_hi53;
                if (value135 >= value138) {
                    a53 = (uint8_t)(value135 - value138);
                    a_hi53 = (uint16_t)(value135 - value138) >> 8;
                } else {
                    uint16_t value139 = RAM16(0x00C6);
                    a53 = (uint8_t)((uint16_t)(value135 - value138) + value139 + (value135 >= value138));
                    a_hi53 = (uint16_t)((uint16_t)(value135 - value138) + value139 + (value135 >= value138)) >> 8;
                }
                a54 = a53;
                a_hi54 = a_hi53;
            }
            RAM8(0x0083) = a54;
            if (value23 >> 8 != 0xC1) {
                uint8_t value140 = RAM8(0x000A);
                r->a = (a_hi54 << 8) | (uint8_t)((value140 & 0x0F) + 0xD8);
                r->x = x_d2de;
                r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                r->c = (value140 & 0x0F) + 0xD8 > 0xFF;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
            }
            r->x = x_d2de;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value24 & 0x0F) == 0x0B) {
            uint8_t value141 = RAM8(0xE068 + x_d2de);
            if (value141 < 3) {
                BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
                uint8_t value142 = RAM8(0x0082);
                uint16_t value143 = RAM16(0x0004);
                uint8_t a57;
                uint8_t a_hi57;
                if (!(value142 & 0x80)) {
                    uint16_t value144 = RAM16(0x00AA);
                    uint8_t a55;
                    uint8_t a_hi55;
                    if (value143 >= value144) {
                        a55 = (uint8_t)(value143 - value144);
                        a_hi55 = (uint16_t)(value143 - value144) >> 8;
                    } else {
                        uint16_t value145 = RAM16(0x00C6);
                        a55 = (uint8_t)((uint16_t)(value143 - value144) + value145 + (value143 >= value144));
                        a_hi55 = (uint16_t)((uint16_t)(value143 - value144) + value145 + (value143 >= value144)) >> 8;
                    }
                    a57 = a55;
                    a_hi57 = a_hi55;
                } else {
                    uint16_t value146 = RAM16(0x00AE);
                    uint8_t a56;
                    uint8_t a_hi56;
                    if (value143 >= value146) {
                        a56 = (uint8_t)(value143 - value146);
                        a_hi56 = (uint16_t)(value143 - value146) >> 8;
                    } else {
                        uint16_t value147 = RAM16(0x00C6);
                        a56 = (uint8_t)((uint16_t)(value143 - value146) + value147 + (value143 >= value146));
                        a_hi56 = (uint16_t)((uint16_t)(value143 - value146) + value147 + (value143 >= value146)) >> 8;
                    }
                    a57 = a56;
                    a_hi57 = a_hi56;
                }
                RAM8(0x0083) = a57;
                if (value23 >> 8 != 0xC1) {
                    uint8_t value148 = RAM8(0x000A);
                    r->a = (a_hi57 << 8) | (uint8_t)((value148 & 0x0F) + 0xD8);
                    r->x = x_d2de;
                    r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                    r->c = (value148 & 0x0F) + 0xD8 > 0xFF;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
                }
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value141 >= 3) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (value141 != value141) {
                RAM8(0x0082) = 0;
                r->x = x_d2de;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value23 >> 8);
            uint8_t value149 = RAM8(0x0082);
            uint16_t value150 = RAM16(0x0004);
            uint8_t a60;
            uint8_t a_hi60;
            if (!(value149 & 0x80)) {
                uint16_t value151 = RAM16(0x00AA);
                uint8_t a58;
                uint8_t a_hi58;
                if (value150 >= value151) {
                    a58 = (uint8_t)(value150 - value151);
                    a_hi58 = (uint16_t)(value150 - value151) >> 8;
                } else {
                    uint16_t value152 = RAM16(0x00C6);
                    a58 = (uint8_t)((uint16_t)(value150 - value151) + value152 + (value150 >= value151));
                    a_hi58 = (uint16_t)((uint16_t)(value150 - value151) + value152 + (value150 >= value151)) >> 8;
                }
                a60 = a58;
                a_hi60 = a_hi58;
            } else {
                uint16_t value153 = RAM16(0x00AE);
                uint8_t a59;
                uint8_t a_hi59;
                if (value150 >= value153) {
                    a59 = (uint8_t)(value150 - value153);
                    a_hi59 = (uint16_t)(value150 - value153) >> 8;
                } else {
                    uint16_t value154 = RAM16(0x00C6);
                    a59 = (uint8_t)((uint16_t)(value150 - value153) + value154 + (value150 >= value153));
                    a_hi59 = (uint16_t)((uint16_t)(value150 - value153) + value154 + (value150 >= value153)) >> 8;
                }
                a60 = a59;
                a_hi60 = a_hi59;
            }
            RAM8(0x0083) = a60;
            if (value23 >> 8 != 0xC1) {
                uint8_t value155 = RAM8(0x000A);
                r->a = (a_hi60 << 8) | (uint8_t)((value155 & 0x0F) + 0xD8);
                r->x = x_d2de;
                r->y = ((value22 & 0xFF) << 1 << 1) + 2;
                r->c = (value155 & 0x0F) + 0xD8 > 0xFF;
                r->mf = true;
                r->xf = false;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD423, 0xC1D285); GUARD_JSR(c, sp_call, 0xD423); } /* record_contact_presentation_byte_and_volume */
            }
            r->x = x_d2de;
            r->mf = true;
            r->xf = false;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0082) = 0;
        r->x = x_d2de;
        r->mf = true;
        r->xf = false;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    bool m_flag3;
    if (((uint8_t)value23 & 0xF0) == 0xF0) {
        uint8_t value156 = RAM8(0xE02C + x_d2de);
        bool m_flag2;
        if (value156 == 0) {
            m_flag2 = 1;
        } else {
            uint8_t value157 = RAM8(0x000E);
            uint8_t value158 = RAM8(0x000F);
            bool m_flag;
            if ((value157 | value158) != 0) {
                m_flag = 1;
            } else {
                RAM16_SET(0x000E, (((value23 >> 8 << 8) | (uint8_t)(RAM8(0x000A) << 4)) >> 4) | 0x8000);
                RAM16_SET(0x001C, x_d2de);
                RAM16_SET(0x001E, 0);
                m_flag = 0;
            }
            m_flag2 = m_flag;
        }
        m_flag3 = m_flag2;
    } else {
        m_flag3 = 1;
    }
    RAM8(0x0082) = 0;
    r->x = x_d2de;
    r->mf = true;
    r->xf = false;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D293, SOM_RTS, "hand", probe_map_cell_contact_and_update_live_tile, 0, L_X, 1, 1, 0, 407, 220)
