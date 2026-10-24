#include "som_c.h"

/* D3FA6F adjust_spell_entity_trail_velocity   [class B, 208 bytes, 103 instructions]
 * Source: src/rom/adjust_spell_entity_trail_velocity.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void adjust_spell_entity_trail_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 0);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), 0);
    RAM8(0x0000 + sp0 - 9) = x >> 8;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)x;
    r->a = 4;
    r->c = (uint16_t)(sp0 - 5) >= 4;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFA88, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFA88); } /* draw_spell_entity_bounded_random_long */
    r->sp += 11;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value27 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value28 = RAM8(0x0000 + sp0 - 9);
        BUS16_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(a_all + 2));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)((uint16_t)(a_all + 2) << 4));
        uint16_t value29 = BUS16_RDP(c, (db_ret << 0x10) + 0x014C + ((value28 << 8) | value27));
        uint8_t a_hi14;
        if ((value29 & 3) == 0) {
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 0x10);
            uint16_t value30 = BUS16_RDP(c, (db_ret << 0x10) + 0x0146 + ((value28 << 8) | value27));
            uint16_t value31 = BUS16_RDP(c, (db_ret << 0x10) + 0x0142 + ((value28 << 8) | value27));
            uint8_t a_hi8;
            if ((uint16_t)(value30 + 0x10) >= value31) {
                if ((uint16_t)((uint16_t)(value30 + 0x10) - value31) < 0x20) {
                    if ((uint16_t)((uint16_t)(value30 + 0x10) - value31) >= 0x10) {
                        uint16_t value32 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                        BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value32 + 1));
                    }
                }
                a_hi8 = (uint16_t)((uint16_t)(value30 + 0x10) - value31) >> 8;
            } else {
                if ((uint16_t)(((uint16_t)((uint16_t)(value30 + 0x10) - value31) ^ 0xFFFF) + 1) < 0x20) {
                    if ((uint16_t)(((uint16_t)((uint16_t)(value30 + 0x10) - value31) ^ 0xFFFF) + 1) >= 0x10) {
                        uint16_t value33 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                        BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value33 - 1));
                    }
                }
                a_hi8 = (uint16_t)(((uint16_t)((uint16_t)(value30 + 0x10) - value31) ^ 0xFFFF) + 1) >> 8;
            }
            a_hi14 = a_hi8;
        } else {
            uint8_t a_hi13;
            if ((uint16_t)((value29 & 3) - 1) == 0) {
                RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), 0x10);
                uint16_t value34 = BUS16_RDP(c, (db_ret << 0x10) + 0x0144 + ((value28 << 8) | value27));
                uint16_t value35 = BUS16_RDP(c, (db_ret << 0x10) + 0x0140 + ((value28 << 8) | value27));
                uint8_t a_hi9;
                if ((uint16_t)(value34 + 0x10) >= value35) {
                    if ((uint16_t)((uint16_t)(value34 + 0x10) - value35) < 0x20) {
                        if ((uint16_t)((uint16_t)(value34 + 0x10) - value35) >= 0x10) {
                            uint16_t value36 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value36 + 1));
                        }
                    }
                    a_hi9 = (uint16_t)((uint16_t)(value34 + 0x10) - value35) >> 8;
                } else {
                    if ((uint16_t)(((uint16_t)((uint16_t)(value34 + 0x10) - value35) ^ 0xFFFF) + 1) < 0x20) {
                        if ((uint16_t)(((uint16_t)((uint16_t)(value34 + 0x10) - value35) ^ 0xFFFF) + 1) >= 0x10) {
                            uint16_t value37 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value37 - 1));
                        }
                    }
                    a_hi9 = (uint16_t)(((uint16_t)((uint16_t)(value34 + 0x10) - value35) ^ 0xFFFF) + 1) >> 8;
                }
                a_hi13 = a_hi9;
            } else {
                uint8_t a_hi12;
                if ((uint16_t)((value29 & 3) - 2) == 0) {
                    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 0xFFF0);
                    uint16_t value38 = BUS16_RDP(c, (db_ret << 0x10) + 0x0146 + ((value28 << 8) | value27));
                    uint16_t value39 = BUS16_RDP(c, (db_ret << 0x10) + 0x0142 + ((value28 << 8) | value27));
                    uint8_t a_hi10;
                    if ((uint16_t)(value38 + 0xFFF0) >= value39) {
                        if ((uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) < 0x20) {
                            if ((uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) >= 0x10) {
                                uint16_t value40 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value40 - 1));
                            }
                        }
                        a_hi10 = (uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) >> 8;
                    } else {
                        if ((uint16_t)(((uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) ^ 0xFFFF) + 1) < 0x20) {
                            if ((uint16_t)(((uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) ^ 0xFFFF) + 1) >= 0x10) {
                                uint16_t value41 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value41 + 1));
                            }
                        }
                        a_hi10 = (uint16_t)(((uint16_t)((uint16_t)(value38 + 0xFFF0) - value39) ^ 0xFFFF) + 1) >> 8;
                    }
                    a_hi12 = a_hi10;
                } else {
                    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), 0xFFF0);
                    uint16_t value42 = BUS16_RDP(c, (db_ret << 0x10) + 0x0144 + ((value28 << 8) | value27));
                    uint16_t value43 = BUS16_RDP(c, (db_ret << 0x10) + 0x0140 + ((value28 << 8) | value27));
                    uint8_t a_hi11;
                    if ((uint16_t)(value42 + 0xFFF0) >= value43) {
                        if ((uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) < 0x20) {
                            if ((uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) >= 0x10) {
                                uint16_t value44 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value44 - 1));
                            }
                        }
                        a_hi11 = (uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) >> 8;
                    } else {
                        if ((uint16_t)(((uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) ^ 0xFFFF) + 1) < 0x20) {
                            if ((uint16_t)(((uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) ^ 0xFFFF) + 1) >= 0x10) {
                                uint16_t value45 = BUS16_RDP(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27));
                                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x014E + ((value28 << 8) | value27), (uint16_t)(value45 + 1));
                            }
                        }
                        a_hi11 = (uint16_t)(((uint16_t)((uint16_t)(value42 + 0xFFF0) - value43) ^ 0xFFFF) + 1) >> 8;
                    }
                    a_hi12 = a_hi11;
                }
                a_hi13 = a_hi12;
            }
            a_hi14 = a_hi13;
        }
        BUS16_SET(c, (db_ret << 0x10) + 0x014A + ((value28 << 8) | value27), RAM16(0x0003 + (uint16_t)(sp0 - 9)));
        uint16_t value47 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
        BUS16_SET(c, (db_ret << 0x10) + 0x0148 + ((value28 << 8) | value27), value47);
        RAM16_SET(0x0000 + sp0 - 4, value47);
        uint8_t value50 = RAM8(0x0000 + sp0 - 2);
        uint8_t value51 = RAM8(0x0000 + sp0 - 1);
        uint8_t value52 = RAM8(0x0000 + sp0);
        r->mf = value50 & 0x20;
        r->xf = value50 & 0x10;
        r->dp = (value52 << 8) | value51;
        r->i = value50 & 0x04;
        r->d = value50 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3FA6F, SOM_RTS, "gen", adjust_spell_entity_trail_velocity, 0, 0, 11, 1, 0, 208, 103)
