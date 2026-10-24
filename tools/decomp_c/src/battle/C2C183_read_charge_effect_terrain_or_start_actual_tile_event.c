#include "som_c.h"

/* C2C183 read_charge_effect_terrain_or_start_actual_tile_event   [class C, 78 bytes, 43 instructions]
 * Source: src/rom/read_charge_effect_terrain_or_start_actual_tile_event.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXY.
 */
static void read_charge_effect_terrain_or_start_actual_tile_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE02C + x);
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = ((((value >> 7 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((value == 0) << 1) | carry;
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC18C, 0xC2C1D7); GUARD_JSR(c, sp_call, 0xC18C); } /* read_charge_effect_terrain_height */
    r->sp += 3;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    if (value2 & 0x02) {
        if (value2 & 0x10) {
            if (value2 & 0x20) {
                c->fail = 3;
                return;
            } else {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        } else {
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            if (value2 & 0x20) {
                uint8_t value8 = RAM8(0xD000 + y);
                uint8_t a2;
                if (value8 < 3) {
                    a2 = (uint8_t)a_all;
                } else {
                    a2 = 0;
                }
                r->a = (value8 << 8) | a2;
                r->x = (value7 << 8) | value6;
                r->mf = 1;
                r->xf = 0;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                RETURN_RTS(c);
            } else {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
    }
    if (value2 & 0x20) {
        if (RAM8(0x00D0) != 0) {
            if (value2 & 0x10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                uint8_t value14 = RAM8(0x0000 + sp0);
                uint8_t value15 = RAM8(0xD000 + y);
                uint8_t a4;
                if (value15 < 3) {
                    a4 = (uint8_t)a_all;
                } else {
                    a4 = 0;
                }
                r->a = (value15 << 8) | a4;
                r->x = (value14 << 8) | value13;
                r->mf = 1;
                r->xf = 0;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                RETURN_RTS(c);
            }
        }
        uint8_t value16 = BUS8(c, 0x7F0002 + x_ret);
        if ((value16 & 0xF0) == 0xF0) {
            uint8_t value17 = BUS8(c, 0x7F0003 + x_ret);
            uint8_t value18 = BUS8(c, 0x7F0002 + x_ret);
            if (value2 & 0x10) {
                uint8_t value19 = RAM8(0x0000 + sp0 - 1);
                RAM8(0x00D4) = value19;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
                r->a = ((value17 << 8) | (uint8_t)(value18 << 4)) >> 4;
                r->x = value19;
                r->y = (uint8_t)y;
                r->c = ((value17 << 8) | (uint8_t)(value18 << 4)) >> 3 & 0x01;
                r->z = value19 == 0;
                r->n = value19 & 0x80;
                r->v = value2 & 0x40;
                r->mf = 0;
                r->xf = 1;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xC1C5, 0x01E76D); GUARD_JSL(c, sp_call, 0xC1C5); } /* event_command_map_context_entry */
                r->sp += 2;
                uint8_t db_ret = r->db;
                bool x_ret2 = r->xf;
                if (x_ret2) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value22 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (db_ret << 0x10) + 0xD000 + ((value22 << 8) | value21), 0);
                    SET_A8(r, 0xFF);
                    r->y = (value22 << 8) | value21;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            } else {
                uint8_t value23 = RAM8(0x0000 + sp0 - 1);
                uint8_t value24 = RAM8(0x0000 + sp0);
                RAM16_SET(0x00D4, (value24 << 8) | value23);
                RAM8(0x0000 + sp0) = y >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
                r->a = ((value17 << 8) | (uint8_t)(value18 << 4)) >> 4;
                r->x = (value24 << 8) | value23;
                r->c = ((value17 << 8) | (uint8_t)(value18 << 4)) >> 3 & 0x01;
                r->z = ((value24 << 8) | value23) == 0;
                r->n = ((value24 << 8) | value23) & 0x8000;
                r->v = value2 & 0x40;
                r->mf = 0;
                r->xf = 0;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xC1C5, 0x01E76D); GUARD_JSL(c, sp_call, 0xC1C5); } /* event_command_map_context_entry */
                r->sp += 2;
                uint8_t db_ret2 = r->db;
                bool x_ret4 = r->xf;
                if (x_ret4) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value26 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value27 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xD000 + ((value27 << 8) | value26), 0);
                    SET_A8(r, 0xFF);
                    r->y = (value27 << 8) | value26;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
        }
        if (value2 & 0x10) {
            c->fail = 3;
            return;
        } else {
            uint8_t value30 = RAM8(0x0000 + sp0 - 1);
            uint8_t value31 = RAM8(0x0000 + sp0);
            uint8_t value32 = RAM8(0xD000 + y);
            uint8_t a6;
            if (value32 < 3) {
                a6 = (uint8_t)a_all;
            } else {
                a6 = 0;
            }
            r->a = (value32 << 8) | a6;
            r->x = (value31 << 8) | value30;
            r->mf = 1;
            r->xf = 0;
            r->i = value2 & 0x04;
            r->d = value2 & 0x08;
            RETURN_RTS(c);
        }
    } else {
        if (RAM16(0x00D0) != 0) {
            if (value2 & 0x10) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
        uint16_t value39 = BUS16(c, 0x7F0002 + x_ret);
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
}
SOM_REGISTER(0xC2C183, SOM_RTS, "gen", read_charge_effect_terrain_or_start_actual_tile_event, 0, L_A | L_B | L_X | L_Y, 3, 1, 0, 78, 43)
