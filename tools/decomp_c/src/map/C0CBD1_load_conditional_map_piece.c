#include "som_c.h"

/* C0CBD1 load_conditional_map_piece   [class B, 450 bytes, 250 instructions]
 * Source: src/rom/load_conditional_map_piece.s
 * Documented in docs/maps.md
 * Entry: M=any X=any DB=any D=any.  Callers read: CV.
 */
static void load_conditional_map_piece(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    uint16_t dp = r->dp;
    uint8_t db = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCBD3, 0xC0CBC2); GUARD_JSR(c, sp_call, 0xCBD3); } /* clear_map_piece_work_cache */
    dp = r->dp;
    db = r->db;
    uint16_t a_all = r->a;
    RAM8(0x0016 + dp) = 0;
    RAM8(0x0017 + dp) = 0;
    uint8_t value = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp), RAM8(0x0022 + dp));
    uint8_t a1;
    uint8_t a_hi2;
    if (value < 0xFE) {
        a1 = value;
        a_hi2 = a_all >> 8;
    } else {
        RAM8(0x0020 + dp)++;
        if (RAM8(0x0020 + dp) == 0) {
            RAM8(0x0021 + dp)++;
        }
        uint8_t a_hi1;
        if (value == 0xFF) {
            RAM8(0x0013 + dp) = 0x40;
            uint8_t value2 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 3, RAM8(0x0022 + dp));
            RAM8(0x00A2 + dp) = value2 >> 1;
            uint8_t value3 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 4, RAM8(0x0022 + dp));
            RAM8(0x00A3 + dp) = value3 >> 1;
            uint8_t value4 = RAM8(0x00A2 + dp);
            RAM16_SET(0x00CA + dp, ((((value3 >> 1) | 0x80) << 8) | (uint8_t)(value4 << 1)) >> 1);
            RAM8(0x00B9 + dp)++;
            a_hi1 = ((((value3 >> 1) | 0x80) << 8) | (uint8_t)(value4 << 1)) >> 1 >> 8;
        } else {
            uint8_t value5 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 3, RAM8(0x0022 + dp));
            RAM8(0x009E + dp) = value5 >> 1;
            uint8_t value6 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 4, RAM8(0x0022 + dp));
            RAM8(0x009F + dp) = value6 >> 1;
            uint8_t value7 = RAM8(0x009E + dp);
            RAM16_SET(0x00C8 + dp, ((value6 >> 1 << 8) | (uint8_t)(value7 << 1)) >> 1);
            RAM8(0x0013 + dp) = 0;
            a_hi1 = ((value6 >> 1 << 8) | (uint8_t)(value7 << 1)) >> 1 >> 8;
        }
        uint8_t value8 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp), RAM8(0x0022 + dp));
        a1 = value8;
        a_hi2 = a_hi1;
    }
    RAM8(0x0000 + dp) = RAM8(EVENT_FLAG_BYTES + (uint8_t)((a_hi2 << 8) | a1));
    uint8_t value9 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 1, RAM8(0x0022 + dp));
    RAM8(0x0000 + sp0) = value9;
    RAM8(0x0001 + dp) = value9 & 0x0F;
    RAM8(0x0002 + dp) = RAM8(0x0000 + sp0) >> 4;
    uint8_t value11 = RAM8(0x0000 + dp);
    uint8_t value12 = RAM8(0x0002 + dp);
    if (value11 >= value12) {
        uint8_t value13 = RAM8(0x0001 + dp);
        if (value11 == value13) {
            RAM8(0x0013 + dp) &= 0x40;
            uint8_t value15 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 2, RAM8(0x0022 + dp));
            RAM8(0x0000 + dp) = value15;
            uint8_t value16 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 3, RAM8(0x0022 + dp));
            RAM8(0x0001 + dp) = (RAM8(0x0001 + dp) >> 1) | ((value16 & 1) << 7);
            RAM8(0x0012 + dp) = value16 >> 1 << 1;
            uint8_t value18 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 4, RAM8(0x0022 + dp));
            uint8_t value19 = RAM8(0x0001 + dp);
            RAM8(0x0001 + dp) = (uint8_t)(RAM8(0x0001 + dp) << 1 | (value18 & 1));
            RAM8(0x0001 + dp) = (uint8_t)((RAM8(0x0001 + dp) << 1) | (value19 >> 7));
            RAM8(0x0013 + dp) = (value18 >> 2) | RAM8(0x0013 + dp);
            RAM8(0x0012 + dp) = (RAM8(0x0012 + dp) >> 1) | (((value18 >> 1) & 1) << 7);
            uint16_t value23 = RAM16(0x0000 + dp);
            uint16_t value24 = BUS16(c, 0xCD0000);
            uint8_t x3;
            if ((value23 & 0x03FF) < value24) {
                x3 = 0xCD;
            } else {
                uint16_t value25 = BUS16(c, 0xCD0002);
                uint8_t x2;
                if ((value23 & 0x03FF) < value25) {
                    x2 = 0xCE;
                } else {
                    uint16_t value26 = BUS16(c, 0xCD0004);
                    uint8_t x1;
                    if ((value23 & 0x03FF) < value26) {
                        x1 = 0xCF;
                    } else {
                        x1 = 0xCC;
                    }
                    x2 = x1;
                }
                x3 = x2;
            }
            RAM8(0x001F + dp) = x3;
            uint16_t value27 = BUS16(c, 0xCD0004 + ((value23 & 0x03FF) << 1));
            RAM16_SET(0x001D + dp, value27);
            uint8_t value28 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp), RAM8(0x001F + dp));
            RAM8(0x0000 + dp) = (RAM8(0x0000 + dp) >> 1) | ((value28 & 1) << 7);
            RAM8(0x0014 + dp) = (value28 >> 1) + 1;
            uint8_t value30 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + 1, RAM8(0x001F + dp));
            uint8_t value31 = RAM8(0x0000 + dp);
            RAM8(0x0000 + dp) = (uint8_t)(RAM8(0x0000 + dp) << 1 | (value30 & 1));
            RAM8(0x0000 + dp) = (uint8_t)((RAM8(0x0000 + dp) << 1) | (value31 >> 7));
            RAM8(0x0015 + dp) = (value30 >> 1) + 1;
            uint8_t value33 = RAM8(0x00B9 + dp);
            uint8_t a_hi5;
            if (value33 != 0) {
                uint8_t value34 = RAM8(0x00A0 + dp);
                uint8_t a_hi3;
                if (value34 != 0) {
                    a_hi3 = value27 >> 8;
                } else {
                    RAM8(0x00A0 + dp) = RAM8(0x0014 + dp);
                    uint8_t value36 = RAM8(0x0015 + dp);
                    RAM8(0x00A1 + dp) = value36;
                    RAM16_SET(0x00C6 + dp, (((value27 >> 8 << 8) | value36) & 0xFF) << 1 << 1 << 1 << 1);
                    uint16_t value37 = RAM16(0x00A0 + dp);
                    RAM16_SET(0x00C4 + dp, (value37 & 0xFF) << 1 << 1 << 1 << 1);
                    a_hi3 = (value37 & 0xFF) << 1 << 1 << 1 << 1 >> 8;
                }
                a_hi5 = a_hi3;
            } else {
                uint8_t value38 = RAM8(0x009C + dp);
                uint8_t a_hi4;
                if (value38 != 0) {
                    a_hi4 = value27 >> 8;
                } else {
                    RAM8(0x009C + dp) = RAM8(0x0014 + dp);
                    uint8_t value40 = RAM8(0x0015 + dp);
                    RAM8(0x009D + dp) = value40;
                    RAM16_SET(0x00C2 + dp, (((value27 >> 8 << 8) | value40) & 0xFF) << 1 << 1 << 1 << 1);
                    uint16_t value41 = RAM16(0x009C + dp);
                    RAM16_SET(0x00C0 + dp, (value41 & 0xFF) << 1 << 1 << 1 << 1);
                    a_hi4 = (value41 & 0xFF) << 1 << 1 << 1 << 1 >> 8;
                }
                a_hi5 = a_hi4;
            }
            uint8_t value42 = RAM8(0x0000 + dp);
            uint8_t a_hi8;
            uint16_t y3;
            if ((value42 & 3) == 0) {
                a_hi8 = a_hi5;
                y3 = 2;
            } else {
                uint8_t a_hi6 = a_hi5;
                uint16_t x4 = 0;
                uint16_t y1 = 2;
                for (;;) {
                    uint8_t value43 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + y1, RAM8(0x001F + dp));
                    BUS8_SET(c, (db << 0x10) + 0xFF00 + x4, value43);
                    uint8_t value44 = RAM8(0x001D + dp);
                    BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x4 + 1), (uint8_t)((uint8_t)(y1 + 1) + value44));
                    uint8_t value45 = RAM8(0x001E + dp);
                    BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x4 + 2), (uint8_t)(value45 + ((uint8_t)(y1 + 1) + value44 > 0xFF)));
                    uint8_t value46 = RAM8(0x001F + dp);
                    BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x4 + 3), (uint8_t)(value46 + (value45 + ((uint8_t)(y1 + 1) + value44 > 0xFF) > 0xFF)));
                    uint8_t a2 = (uint8_t)(value46 + (value45 + ((uint8_t)(y1 + 1) + value44 > 0xFF) > 0xFF));
                    uint8_t a_hi7 = a_hi6;
                    uint16_t y2 = (uint16_t)(y1 + 1);
                    for (;;) {
                        uint8_t value47 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + y2, RAM8(0x001F + dp));
                        a2 = value47;
                        y2 = (uint16_t)(y2 + 1);
                        if (!(a2 < 0xF8)) break;
                    }
                    a_hi6 = a_hi7;
                    x4 = (uint16_t)(x4 + 4);
                    y1 = y2;
                    if (!(a2 != 0xFF)) break;
                }
                a_hi8 = a_hi6;
                y3 = y1;
            }
            uint16_t value48 = RAM16(0x001D + dp);
            RAM16_SET(0x001D + dp, (uint16_t)(y3 + value48));
            if (y3 + value48 > 0xFFFF) {
                RAM8(0x001F + dp)++;
            }
            r->a = (uint16_t)(y3 + value48);
            r->v = ((y3 ^ (uint16_t)(y3 + value48)) & (value48 ^ (uint16_t)(y3 + value48)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCD48, 0xC0CD93); GUARD_JSR(c, sp_call, 0xCD48); } /* decode_map_piece_body */
            dp = r->dp;
            db = r->db;
            uint16_t a_all2 = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            RAM8(0x0026 + dp) = 0;
            uint8_t a_hi9 = a_all2 >> 8;
            bool carry1 = carry_ret;
            bool overflow1 = overflow_ret;
            for (;;) {
                uint8_t value49 = RAM8(0x0026 + dp);
                uint8_t value50 = BUS8_RDP(c, (db << 0x10) + 0xFF20 + value49);
                if (value50 != 0) {
                    RAM8(0x0000 + sp0) = value50;
                    uint8_t value51 = BUS8_RDP(c, (db << 0x10) + 0xFF22 + value49);
                    RAM8(0x0012 + dp) = value51;
                    uint8_t value52 = BUS8_RDP(c, (db << 0x10) + 0xFF23 + value49);
                    RAM8(0x0013 + dp) = value52;
                    uint8_t value53 = RAM8(0x0000 + sp0);
                    uint8_t value54 = BUS8_RDP(c, (db << 0x10) + 0xFF00 + (uint8_t)((a_hi9 << 8) | (uint8_t)(value53 << 2)));
                    RAM8(0x0000 + sp0) = value54;
                    RAM8(0x0014 + dp) = (value54 & 0x0F) + 1;
                    RAM8(0x0015 + dp) = (RAM8(0x0000 + sp0) >> 4) + 1;
                    uint8_t value56 = BUS8_RDP(c, (db << 0x10) + 0xFF01 + (uint8_t)((a_hi9 << 8) | (uint8_t)(value53 << 2)));
                    RAM8(0x001D + dp) = value56;
                    uint8_t value57 = BUS8_RDP(c, (db << 0x10) + 0xFF02 + (uint8_t)((a_hi9 << 8) | (uint8_t)(value53 << 2)));
                    RAM8(0x001E + dp) = value57;
                    uint8_t value58 = BUS8_RDP(c, (db << 0x10) + 0xFF03 + (uint8_t)((a_hi9 << 8) | (uint8_t)(value53 << 2)));
                    RAM8(0x001F + dp) = value58;
                    r->a = (a_hi9 << 8) | value58;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = db;
                    r->dp = dp;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xCD86, 0xC0CD93); GUARD_JSR(c, sp_call, 0xCD86); } /* decode_map_piece_body */
                    dp = r->dp;
                    db = r->db;
                    uint16_t a_all3 = r->a;
                    uint8_t value59 = RAM8(0x0026 + dp);
                    RAM8(0x0026 + dp) = (uint8_t)(value59 + 4);
                    a_hi9 = a_all3 >> 8;
                    carry1 = value59 + 4 > 0xFF;
                    overflow1 = ((value59 ^ (uint8_t)(value59 + 4)) & ((uint8_t)(value59 + 4) ^ 4) & 0x80) != 0;
                    continue;
                }
                r->c = carry1;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                r->db = db;
                r->dp = dp;
                RETURN_RTS(c);
            }
        }
        if (value11 >= value13) {
            r->c = value11 >= value13;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x0013 + dp) &= 0x40;
        uint8_t value61 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 2, RAM8(0x0022 + dp));
        RAM8(0x0000 + dp) = value61;
        uint8_t value62 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 3, RAM8(0x0022 + dp));
        RAM8(0x0001 + dp) = (RAM8(0x0001 + dp) >> 1) | ((value62 & 1) << 7);
        RAM8(0x0012 + dp) = value62 >> 1 << 1;
        uint8_t value64 = BUS8_RDL(c, (RAM8(0x0022 + dp) << 0x10) + RAM16(0x0020 + dp) + 4, RAM8(0x0022 + dp));
        uint8_t value65 = RAM8(0x0001 + dp);
        RAM8(0x0001 + dp) = (uint8_t)(RAM8(0x0001 + dp) << 1 | (value64 & 1));
        RAM8(0x0001 + dp) = (uint8_t)((RAM8(0x0001 + dp) << 1) | (value65 >> 7));
        RAM8(0x0013 + dp) = (value64 >> 2) | RAM8(0x0013 + dp);
        RAM8(0x0012 + dp) = (RAM8(0x0012 + dp) >> 1) | (((value64 >> 1) & 1) << 7);
        uint16_t value69 = RAM16(0x0000 + dp);
        uint16_t value70 = BUS16(c, 0xCD0000);
        uint8_t x7;
        if ((value69 & 0x03FF) < value70) {
            x7 = 0xCD;
        } else {
            uint16_t value71 = BUS16(c, 0xCD0002);
            uint8_t x6;
            if ((value69 & 0x03FF) < value71) {
                x6 = 0xCE;
            } else {
                uint16_t value72 = BUS16(c, 0xCD0004);
                uint8_t x5;
                if ((value69 & 0x03FF) < value72) {
                    x5 = 0xCF;
                } else {
                    x5 = 0xCC;
                }
                x6 = x5;
            }
            x7 = x6;
        }
        RAM8(0x001F + dp) = x7;
        uint16_t value73 = BUS16(c, 0xCD0004 + ((value69 & 0x03FF) << 1));
        RAM16_SET(0x001D + dp, value73);
        uint8_t value74 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp), RAM8(0x001F + dp));
        RAM8(0x0000 + dp) = (RAM8(0x0000 + dp) >> 1) | ((value74 & 1) << 7);
        RAM8(0x0014 + dp) = (value74 >> 1) + 1;
        uint8_t value76 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + 1, RAM8(0x001F + dp));
        uint8_t value77 = RAM8(0x0000 + dp);
        RAM8(0x0000 + dp) = (uint8_t)(RAM8(0x0000 + dp) << 1 | (value76 & 1));
        RAM8(0x0000 + dp) = (uint8_t)((RAM8(0x0000 + dp) << 1) | (value77 >> 7));
        RAM8(0x0015 + dp) = (value76 >> 1) + 1;
        uint8_t value79 = RAM8(0x00B9 + dp);
        uint8_t a_hi12;
        if (value79 != 0) {
            uint8_t value80 = RAM8(0x00A0 + dp);
            uint8_t a_hi10;
            if (value80 != 0) {
                a_hi10 = value73 >> 8;
            } else {
                RAM8(0x00A0 + dp) = RAM8(0x0014 + dp);
                uint8_t value82 = RAM8(0x0015 + dp);
                RAM8(0x00A1 + dp) = value82;
                RAM16_SET(0x00C6 + dp, (((value73 >> 8 << 8) | value82) & 0xFF) << 1 << 1 << 1 << 1);
                uint16_t value83 = RAM16(0x00A0 + dp);
                RAM16_SET(0x00C4 + dp, (value83 & 0xFF) << 1 << 1 << 1 << 1);
                a_hi10 = (value83 & 0xFF) << 1 << 1 << 1 << 1 >> 8;
            }
            a_hi12 = a_hi10;
        } else {
            uint8_t value84 = RAM8(0x009C + dp);
            uint8_t a_hi11;
            if (value84 != 0) {
                a_hi11 = value73 >> 8;
            } else {
                RAM8(0x009C + dp) = RAM8(0x0014 + dp);
                uint8_t value86 = RAM8(0x0015 + dp);
                RAM8(0x009D + dp) = value86;
                RAM16_SET(0x00C2 + dp, (((value73 >> 8 << 8) | value86) & 0xFF) << 1 << 1 << 1 << 1);
                uint16_t value87 = RAM16(0x009C + dp);
                RAM16_SET(0x00C0 + dp, (value87 & 0xFF) << 1 << 1 << 1 << 1);
                a_hi11 = (value87 & 0xFF) << 1 << 1 << 1 << 1 >> 8;
            }
            a_hi12 = a_hi11;
        }
        uint8_t value88 = RAM8(0x0000 + dp);
        uint8_t a_hi15;
        uint16_t y6;
        if ((value88 & 3) == 0) {
            a_hi15 = a_hi12;
            y6 = 2;
        } else {
            uint8_t a_hi13 = a_hi12;
            uint16_t x8 = 0;
            uint16_t y4 = 2;
            for (;;) {
                uint8_t value89 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + y4, RAM8(0x001F + dp));
                BUS8_SET(c, (db << 0x10) + 0xFF00 + x8, value89);
                uint8_t value90 = RAM8(0x001D + dp);
                BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x8 + 1), (uint8_t)((uint8_t)(y4 + 1) + value90));
                uint8_t value91 = RAM8(0x001E + dp);
                BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x8 + 2), (uint8_t)(value91 + ((uint8_t)(y4 + 1) + value90 > 0xFF)));
                uint8_t value92 = RAM8(0x001F + dp);
                BUS8_SET(c, (db << 0x10) + 0xFF00 + (uint16_t)(x8 + 3), (uint8_t)(value92 + (value91 + ((uint8_t)(y4 + 1) + value90 > 0xFF) > 0xFF)));
                uint8_t a3 = (uint8_t)(value92 + (value91 + ((uint8_t)(y4 + 1) + value90 > 0xFF) > 0xFF));
                uint8_t a_hi14 = a_hi13;
                uint16_t y5 = (uint16_t)(y4 + 1);
                for (;;) {
                    uint8_t value93 = BUS8_RDL(c, (RAM8(0x001F + dp) << 0x10) + RAM16(0x001D + dp) + y5, RAM8(0x001F + dp));
                    a3 = value93;
                    y5 = (uint16_t)(y5 + 1);
                    if (!(a3 < 0xF8)) break;
                }
                a_hi13 = a_hi14;
                x8 = (uint16_t)(x8 + 4);
                y4 = y5;
                if (!(a3 != 0xFF)) break;
            }
            a_hi15 = a_hi13;
            y6 = y4;
        }
        uint16_t value94 = RAM16(0x001D + dp);
        RAM16_SET(0x001D + dp, (uint16_t)(y6 + value94));
        if (y6 + value94 > 0xFFFF) {
            RAM8(0x001F + dp)++;
        }
        r->a = (uint16_t)(y6 + value94);
        r->v = ((y6 ^ (uint16_t)(y6 + value94)) & (value94 ^ (uint16_t)(y6 + value94)) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCD48, 0xC0CD93); GUARD_JSR(c, sp_call, 0xCD48); } /* decode_map_piece_body */
        dp = r->dp;
        db = r->db;
        uint16_t a_all4 = r->a;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        RAM8(0x0026 + dp) = 0;
        uint8_t a_hi16 = a_all4 >> 8;
        bool carry2 = carry_ret3;
        bool overflow2 = overflow_ret3;
        for (;;) {
            uint8_t value95 = RAM8(0x0026 + dp);
            uint8_t value96 = BUS8_RDP(c, (db << 0x10) + 0xFF20 + value95);
            if (value96 != 0) {
                RAM8(0x0000 + sp0) = value96;
                uint8_t value97 = BUS8_RDP(c, (db << 0x10) + 0xFF22 + value95);
                RAM8(0x0012 + dp) = value97;
                uint8_t value98 = BUS8_RDP(c, (db << 0x10) + 0xFF23 + value95);
                RAM8(0x0013 + dp) = value98;
                uint8_t value99 = RAM8(0x0000 + sp0);
                uint8_t value100 = BUS8_RDP(c, (db << 0x10) + 0xFF00 + (uint8_t)((a_hi16 << 8) | (uint8_t)(value99 << 2)));
                RAM8(0x0000 + sp0) = value100;
                RAM8(0x0014 + dp) = (value100 & 0x0F) + 1;
                RAM8(0x0015 + dp) = (RAM8(0x0000 + sp0) >> 4) + 1;
                uint8_t value102 = BUS8_RDP(c, (db << 0x10) + 0xFF01 + (uint8_t)((a_hi16 << 8) | (uint8_t)(value99 << 2)));
                RAM8(0x001D + dp) = value102;
                uint8_t value103 = BUS8_RDP(c, (db << 0x10) + 0xFF02 + (uint8_t)((a_hi16 << 8) | (uint8_t)(value99 << 2)));
                RAM8(0x001E + dp) = value103;
                uint8_t value104 = BUS8_RDP(c, (db << 0x10) + 0xFF03 + (uint8_t)((a_hi16 << 8) | (uint8_t)(value99 << 2)));
                RAM8(0x001F + dp) = value104;
                r->a = (a_hi16 << 8) | value104;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 1;
                r->db = db;
                r->dp = dp;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCD86, 0xC0CD93); GUARD_JSR(c, sp_call, 0xCD86); } /* decode_map_piece_body */
                dp = r->dp;
                db = r->db;
                uint16_t a_all5 = r->a;
                uint8_t value105 = RAM8(0x0026 + dp);
                RAM8(0x0026 + dp) = (uint8_t)(value105 + 4);
                a_hi16 = a_all5 >> 8;
                carry2 = value105 + 4 > 0xFF;
                overflow2 = ((value105 ^ (uint8_t)(value105 + 4)) & ((uint8_t)(value105 + 4) ^ 4) & 0x80) != 0;
                continue;
            }
            r->c = carry2;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
    }
    r->c = value11 >= value12;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0CBD1, SOM_RTS, "hand", load_conditional_map_piece, 0, L_C | L_V, 1, -1, -1, 450, 250)
