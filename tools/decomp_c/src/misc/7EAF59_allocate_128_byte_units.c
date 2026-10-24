#include "som_c.h"

/* 7EAF59 allocate_128_byte_units   [class B, 182 bytes, 102 instructions]
 * Source: src/boot/allocate_128_byte_units.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXY.
 */
static void allocate_128_byte_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7F;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    RAM8(0x0003 + (uint16_t)(sp0 - 0x0A)) = 0;
    r->a = value;
    r->c = (uint16_t)(sp0 - 5) >= 5;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 0x0A);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF76, 0x7EACE9); GUARD_JSR(c, sp_call, 0xAF76); } /* current_task_id */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 7), (uint8_t)a_all);
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xC2);
        BUS8_SET(c, (uint16_t)(dp_ret + 4), value2);
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xC2);
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(0 - value3));
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
        BUS8_SET(c, (uint16_t)(dp_ret + 6), value4);
        uint8_t a_hi1 = a_all >> 8;
        uint8_t x1 = value2;
        uint8_t y1 = (uint8_t)y;
        for (;;) {
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xC4 + x1);
            if (value5 != 0) {
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                BUS8_SET(c, (uint16_t)(dp_ret + 6), value6);
                BUS8_SET(c, (uint16_t)(dp_ret + 4), x1);
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value7 - 1));
                if ((uint8_t)(value7 - 1) != 0) {
                    x1 = (uint8_t)(x1 + 1);
                    continue;
                }
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
            BUS8_SET(c, (uint16_t)(dp_ret + 6), (uint8_t)(value8 - 1));
            if ((uint8_t)(value8 - 1) != 0) {
                uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value22 - 1));
                if ((uint8_t)(value22 - 1) != 0) {
                    x1 = (uint8_t)(x1 + 1);
                    continue;
                }
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0xC0);
            if ((uint8_t)(0 - value9) != value10) {
                if ((uint8_t)(0 - value9) >= value10) {
                    BUS8_SET(c, (db_ret << 0x10) + 0xC0, (uint8_t)(0 - value9));
                }
            }
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
            uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0xC2);
            uint8_t a1;
            uint8_t a_hi3;
            uint8_t y3;
            if (value11 != value12) {
                a1 = (uint8_t)value11;
                a_hi3 = value11 >> 8;
                y3 = y1;
            } else {
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                uint8_t a_hi2 = (uint16_t)(value11 + value13) >> 8;
                uint8_t y2 = (uint8_t)(value11 + value13);
                for (;;) {
                    uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0xC4 + y2);
                    if (value14 != 0) {
                        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value15 - 1));
                        if ((uint8_t)(value15 - 1) != 0) {
                            y2 = (uint8_t)(y2 + 1);
                            continue;
                        }
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    }
                    break;
                }
                BUS8_SET(c, (db_ret << 0x10) + 0xC2, y2);
                uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                a1 = (uint8_t)(value16 - 1);
                a_hi3 = (uint16_t)(value16 - 1) >> 8;
                y3 = y2;
            }
            BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)(((a_hi3 << 8) | a1) + 1));
            uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), value17);
            uint8_t a_hi4 = (uint16_t)(((a_hi3 << 8) | a1) + 1) >> 8;
            uint8_t x2 = (uint8_t)(((a_hi3 << 8) | a1) + 1);
            for (;;) {
                uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (db_ret << 0x10) + 0xC4 + x2, value18);
                uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
                BUS8_SET(c, (db_ret << 0x10) + 0x01C4 + x2, value19);
                uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value20 - 1));
                x2 = (uint8_t)(x2 + 1);
                if (!((uint8_t)(value20 - 1) != 0)) break;
            }
            uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
            a_hi1 = (uint16_t)(value21 << 7) >> 8;
            x1 = (uint8_t)(value21 << 7);
            y1 = y3;
            break;
        }
        uint8_t value23 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value24 = RAM8(0x0000 + sp0 - 2);
        uint8_t value25 = RAM8(0x0000 + sp0 - 1);
        uint8_t value26 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0A) + 7);
        r->x = x1;
        r->y = y1;
        r->mf = value24 & 0x20;
        r->xf = value24 & 0x10;
        r->db = value23;
        r->dp = (value26 << 8) | value25;
        r->i = value24 & 0x04;
        r->d = value24 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value27 = BUS16_RDP(c, (db_ret << 0x10) + 0xC2);
        BUS16_SET(c, (uint16_t)(dp_ret + 4), value27);
        uint8_t value28 = BUS8_RDP(c, (db_ret << 0x10) + 0xC2);
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(0 - value28));
        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
        BUS8_SET(c, (uint16_t)(dp_ret + 6), value29);
        uint8_t a_hi5 = a_all >> 8;
        uint16_t x3 = value27;
        uint16_t y4 = y;
        for (;;) {
            uint8_t value30 = BUS8_RDP(c, (db_ret << 0x10) + 0xC4 + x3);
            uint16_t x6;
            uint16_t y9;
            if (value30 != 0) {
                uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                BUS8_SET(c, (uint16_t)(dp_ret + 6), value31);
                BUS16_SET(c, (uint16_t)(dp_ret + 4), x3);
                uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value32 - 1));
                if ((uint8_t)(value32 - 1) != 0) {
                    x3 = (uint16_t)(x3 + 1);
                    continue;
                }
                x6 = 0;
                y9 = y4;
            } else {
                uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
                BUS8_SET(c, (uint16_t)(dp_ret + 6), (uint8_t)(value33 - 1));
                uint16_t x5;
                uint16_t y8;
                if ((uint8_t)(value33 - 1) == 0) {
                    uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    uint8_t value35 = BUS8_RDP(c, (db_ret << 0x10) + 0xC0);
                    if ((uint8_t)(0 - value34) != value35) {
                        if ((uint8_t)(0 - value34) >= value35) {
                            BUS8_SET(c, (db_ret << 0x10) + 0xC0, (uint8_t)(0 - value34));
                        }
                    }
                    uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    uint16_t value37 = BUS16_RDP(c, (db_ret << 0x10) + 0xC2);
                    uint8_t a2;
                    uint8_t a_hi7;
                    uint16_t y7;
                    if (value36 != value37) {
                        a2 = (uint8_t)value36;
                        a_hi7 = value36 >> 8;
                        y7 = y4;
                    } else {
                        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                        uint8_t a_hi6 = (uint16_t)(value36 + value38) >> 8;
                        uint16_t y5 = (uint16_t)(value36 + value38);
                        for (;;) {
                            uint8_t value39 = BUS8_RDP(c, (db_ret << 0x10) + 0xC4 + y5);
                            uint16_t y6;
                            if (value39 == 0) {
                                y6 = y5;
                            } else {
                                uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value40 - 1));
                                if ((uint8_t)(value40 - 1) != 0) {
                                    y5 = (uint16_t)(y5 + 1);
                                    continue;
                                }
                                y6 = 0;
                            }
                            y5 = y6;
                            break;
                        }
                        BUS16_SET(c, (db_ret << 0x10) + 0xC2, y5);
                        uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                        a2 = (uint8_t)(value41 - 1);
                        a_hi7 = (uint16_t)(value41 - 1) >> 8;
                        y7 = y5;
                    }
                    BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)(((a_hi7 << 8) | a2) + 1));
                    uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), value42);
                    uint8_t a_hi8 = (uint16_t)(((a_hi7 << 8) | a2) + 1) >> 8;
                    uint16_t x4 = (uint16_t)(((a_hi7 << 8) | a2) + 1);
                    for (;;) {
                        uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                        BUS8_SET(c, (db_ret << 0x10) + 0xC4 + x4, value43);
                        uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
                        BUS8_SET(c, (db_ret << 0x10) + 0x01C4 + x4, value44);
                        uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value45 - 1));
                        x4 = (uint16_t)(x4 + 1);
                        if (!((uint8_t)(value45 - 1) != 0)) break;
                    }
                    uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    x5 = (uint16_t)(value46 << 7);
                    y8 = y7;
                } else {
                    uint8_t value47 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value47 - 1));
                    if ((uint8_t)(value47 - 1) != 0) {
                        x3 = (uint16_t)(x3 + 1);
                        continue;
                    }
                    x5 = 0;
                    y8 = y4;
                }
                x6 = x5;
                y9 = y8;
            }
            x3 = x6;
            y4 = y9;
            break;
        }
        uint8_t value48 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value49 = RAM8(0x0000 + sp0 - 2);
        uint8_t value50 = RAM8(0x0000 + sp0 - 1);
        uint8_t value51 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0A) + 7);
        r->x = x3;
        r->y = y4;
        r->mf = value49 & 0x20;
        r->xf = value49 & 0x10;
        r->db = value48;
        r->dp = (value51 << 8) | value50;
        r->i = value49 & 0x04;
        r->d = value49 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EAF59, SOM_RTS, "gen", allocate_128_byte_units, 0, L_B | L_X | L_Y, 13, 0, 0, 182, 102)
