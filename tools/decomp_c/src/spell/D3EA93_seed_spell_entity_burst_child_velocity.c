#include "som_c.h"

/* D3EA93 seed_spell_entity_burst_child_velocity   [class B, 240 bytes, 114 instructions]
 * Source: src/rom/seed_spell_entity_burst_child_velocity.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: YCV.
 */
static void seed_spell_entity_burst_child_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0E) + 0xB > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = RAM16(0x0054 + x);
    uint16_t y1;
    uint8_t data_bank;
    if (value != 0) {
        RAM16_SET(0x0054 + x, (uint16_t)(value - 1));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0E), y);
        RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0E), x);
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0E), RAM16(0x0052 + x));
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0E), RAM16(0x0050 + x));
        RAM16_SET(0x000E + y, 0);
        r->a = 0;
        r->c = (uint16_t)(sp0 - 3) >= 0x0B;
        r->z = 1;
        r->n = 0;
        r->v = (((uint16_t)(sp0 - 3) ^ 0x0B) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0E)) & 0x8000) != 0;
        r->mf = 1;
        r->dp = (uint16_t)(sp0 - 0x0E);
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEAC9, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEAC9); } /* draw_spell_entity_bounded_random_long */
        r->sp += 14;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0E)) = (uint8_t)a_all & 0xF0;
        uint8_t value4 = RAM8(0x0007 + (uint16_t)(sp0 - 0x0E));
        r->a = (a_all >> 8 << 8) | value4;
        r->x = 0x60;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEAD6, 0xC12EC9); GUARD_JSL(c, sp_call, 0xEAD6); } /* scale_spell_entity_signed_angle_vector_long */
        r->sp += 14;
        uint16_t x_ret2 = r->x;
        uint16_t value5 = RAM16(0x0005 + (uint16_t)(sp0 - 0x0E));
        uint16_t value6 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0E));
        BUS16_SET(c, (db_ret << 0x10) + 3 + value6, (uint16_t)(x_ret2 + value5));
        uint16_t value7 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0E));
        r->a = value7;
        r->x = 0x60;
        r->y = value6;
        r->c = x_ret2 + value5 > 0xFFFF;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->v = ((x_ret2 ^ (uint16_t)(x_ret2 + value5)) & (value5 ^ (uint16_t)(x_ret2 + value5)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEAEA, 0xC12ECD); GUARD_JSL(c, sp_call, 0xEAEA); } /* scale_spell_entity_signed_quarter_turn_vector_long */
        r->sp += 14;
        uint16_t x_ret3 = r->x;
        uint16_t value8 = RAM16(0x0003 + (uint16_t)(sp0 - 0x0E));
        uint16_t value9 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0E));
        BUS16_SET(c, (db_ret << 0x10) + 6 + value9, (uint16_t)(x_ret3 + value8));
        uint16_t value10 = RAM16(0x0008 + (uint16_t)(sp0 - 0x0E));
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0x50 + value10);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), 0);
        uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 3 + value9);
        uint8_t a3;
        uint8_t a_hi3;
        if ((uint16_t)(value11 - value12) & 0x8000) {
            uint8_t a1;
            uint8_t a_hi1;
            if (((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12)) & 0x8000) != 0) {
                a1 = (uint8_t)(value11 - value12);
                a_hi1 = (uint16_t)(value11 - value12) >> 8;
            } else {
                RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) - 1));
                a1 = (uint8_t)(((uint16_t)(value11 - value12) ^ 0xFFFF) + 1);
                a_hi1 = (uint16_t)(((uint16_t)(value11 - value12) ^ 0xFFFF) + 1) >> 8;
            }
            a3 = a1;
            a_hi3 = a_hi1;
        } else {
            uint8_t a2;
            uint8_t a_hi2;
            if (((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12)) & 0x8000) == 0) {
                a2 = (uint8_t)(value11 - value12);
                a_hi2 = (uint16_t)(value11 - value12) >> 8;
            } else {
                RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) - 1));
                a2 = (uint8_t)(((uint16_t)(value11 - value12) ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)(((uint16_t)(value11 - value12) ^ 0xFFFF) + 1) >> 8;
            }
            a3 = a2;
            a_hi3 = a_hi2;
        }
        BUS16_SET(c, 0x004204, (a3 << 8) | a_hi3);
        BUS8_SET(c, 0x004206, 0xD2);
        RAM8(0x0000 + sp0 - 0x0E) = a3;
        RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)((a3 << 8) | 0xD2);
        RAM8(0x0000 + sp0 - 0x0E) = a3;
        RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)((a3 << 8) | 0xD2);
        uint16_t value13 = BUS16(c, 0x004214);
        uint16_t value14 = RAM16(0x000A + (uint16_t)(sp0 - 0x0E));
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) >> 1);
        uint8_t a4;
        uint8_t a_hi4;
        if (!(value14 & 0x01)) {
            a4 = (uint8_t)value13;
            a_hi4 = value13 >> 8;
        } else {
            a4 = (uint8_t)((value13 ^ 0xFFFF) + 1);
            a_hi4 = (uint16_t)((value13 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (db_ret << 0x10) + 8 + value9, (a_hi4 << 8) | a4);
        BUS8_SET(c, (db_ret << 0x10) + 0x0A + value9, RAM8(0x000A + (uint16_t)(sp0 - 0x0E)));
        uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0x52 + value10);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), 0);
        uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 6 + value9);
        uint8_t a7;
        uint8_t a_hi7;
        if ((uint16_t)(value16 - value17) & 0x8000) {
            uint8_t a5;
            uint8_t a_hi5;
            if (((value16 ^ value17) & (value16 ^ (uint16_t)(value16 - value17)) & 0x8000) != 0) {
                a5 = (uint8_t)(value16 - value17);
                a_hi5 = (uint16_t)(value16 - value17) >> 8;
            } else {
                RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) - 1));
                a5 = (uint8_t)(((uint16_t)(value16 - value17) ^ 0xFFFF) + 1);
                a_hi5 = (uint16_t)(((uint16_t)(value16 - value17) ^ 0xFFFF) + 1) >> 8;
            }
            a7 = a5;
            a_hi7 = a_hi5;
        } else {
            uint8_t a6;
            uint8_t a_hi6;
            if (((value16 ^ value17) & (value16 ^ (uint16_t)(value16 - value17)) & 0x8000) == 0) {
                a6 = (uint8_t)(value16 - value17);
                a_hi6 = (uint16_t)(value16 - value17) >> 8;
            } else {
                RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) - 1));
                a6 = (uint8_t)(((uint16_t)(value16 - value17) ^ 0xFFFF) + 1);
                a_hi6 = (uint16_t)(((uint16_t)(value16 - value17) ^ 0xFFFF) + 1) >> 8;
            }
            a7 = a6;
            a_hi7 = a_hi6;
        }
        BUS16_SET(c, 0x004204, (a7 << 8) | a_hi7);
        BUS8_SET(c, 0x004206, 0xD2);
        RAM8(0x0000 + sp0 - 0x0E) = a7;
        RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)((a7 << 8) | 0xD2);
        RAM8(0x0000 + sp0 - 0x0E) = a7;
        RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)((a7 << 8) | 0xD2);
        uint16_t value18 = BUS16(c, 0x004214);
        uint16_t value19 = RAM16(0x000A + (uint16_t)(sp0 - 0x0E));
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), RAM16(0x000A + (uint16_t)(sp0 - 0x0E)) >> 1);
        uint8_t a8;
        uint8_t a_hi8;
        if (!(value19 & 0x01)) {
            a8 = (uint8_t)value18;
            a_hi8 = value18 >> 8;
        } else {
            a8 = (uint8_t)((value18 ^ 0xFFFF) + 1);
            a_hi8 = (uint16_t)((value18 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (db_ret << 0x10) + 0x0B + value9, (a_hi8 << 8) | a8);
        BUS8_SET(c, (db_ret << 0x10) + 0x0D + value9, RAM8(0x000A + (uint16_t)(sp0 - 0x0E)));
        y1 = value9;
        data_bank = db_ret;
    } else {
        RAM16_SET(0x000E + y, 0x8000);
        y1 = y;
        data_bank = 0x7E;
    }
    uint8_t value21 = RAM8(0x0000 + sp0 - 2);
    uint8_t value22 = RAM8(0x0000 + sp0 - 1);
    uint8_t value23 = RAM8(0x0000 + sp0);
    r->y = y1;
    r->c = value21 & 0x01;
    r->v = value21 & 0x40;
    r->mf = value21 & 0x20;
    r->xf = value21 & 0x10;
    r->db = data_bank;
    r->dp = (value23 << 8) | value22;
    r->i = value21 & 0x04;
    r->d = value21 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EA93, SOM_RTS, "gen", seed_spell_entity_burst_child_velocity, 0, L_Y | L_C | L_V, 16, -1, 0, 240, 114)
