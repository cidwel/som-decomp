#include "som_c.h"

/* C13597 cycle_spell_entity_blue_color   [class B, 54 bytes, 32 instructions]
 * Source: src/rom/cycle_spell_entity_blue_color.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void cycle_spell_entity_blue_color(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), y);
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x32;
    r->z = 0;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x35A6, 0xC144B3); GUARD_JSR(c, sp_call, 0x35A6); } /* allocate_spell_entity_register_record */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x22 + value);
        uint8_t a1;
        if ((uint8_t)(value2 + 1) < 0x0A) {
            a1 = (uint8_t)(value2 + 1);
        } else {
            a1 = 0;
        }
        BUS8_SET(c, (db_ret << 0x10) + 0x22 + value, a1);
        uint8_t a2;
        if (a1 >= 5) {
            a2 = (uint8_t)(a1 - 5);
        } else {
            a2 = (uint8_t)(((uint8_t)(a1 - 5) ^ 0xFF) + 1);
        }
        BUS8_SET(c, (db_ret << 0x10) + 2 + (uint8_t)x_ret2, (uint8_t)(a2 << 2) | 0x20);
        r->a = (a_all >> 8 << 8) | ((uint8_t)(a2 << 2) | 0x20);
        r->x = (uint8_t)x_ret2;
        r->y = value;
        r->c = (uint8_t)(a2 << 1) & 0x80;
        r->z = ((uint8_t)(a2 << 2) | 0x20) == 0;
        r->n = ((uint8_t)(a2 << 2) | 0x20) & 0x80;
        r->v = ((a1 ^ 5) & (a1 ^ (uint8_t)(a1 - 5)) & 0x80) != 0;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x35C7, 0xC14514); GUARD_JSR(c, sp_call, 0x35C7); } /* append_spell_entity_transient_register_record */
        r->sp += 5;
        bool m_ret = r->mf;
        uint16_t a_all2 = r->a;
        if (m_ret) {
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            r->a = (a_all2 >> 8 << 8) | value4;
            r->c = value5 & 0x01;
            r->z = ((value7 << 8) | value6) == 0;
            r->n = ((value7 << 8) | value6) & 0x8000;
            r->v = value5 & 0x40;
            r->mf = value5 & 0x20;
            r->xf = value5 & 0x10;
            r->dp = (value7 << 8) | value6;
            r->i = value5 & 0x04;
            r->d = value5 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0x22 + value13);
        uint8_t a3;
        if ((uint8_t)(value14 + 1) < 0x0A) {
            a3 = (uint8_t)(value14 + 1);
        } else {
            a3 = 0;
        }
        BUS8_SET(c, (db_ret << 0x10) + 0x22 + value13, a3);
        uint8_t a4;
        if (a3 >= 5) {
            a4 = (uint8_t)(a3 - 5);
        } else {
            a4 = (uint8_t)(((uint8_t)(a3 - 5) ^ 0xFF) + 1);
        }
        BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret2, (uint8_t)(a4 << 2) | 0x20);
        r->a = (a_all >> 8 << 8) | ((uint8_t)(a4 << 2) | 0x20);
        r->y = value13;
        r->c = (uint8_t)(a4 << 1) & 0x80;
        r->z = ((uint8_t)(a4 << 2) | 0x20) == 0;
        r->n = ((uint8_t)(a4 << 2) | 0x20) & 0x80;
        r->v = ((a3 ^ 5) & (a3 ^ (uint8_t)(a3 - 5)) & 0x80) != 0;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x35C7, 0xC14514); GUARD_JSR(c, sp_call, 0x35C7); } /* append_spell_entity_transient_register_record */
        r->sp += 5;
        bool m_ret2 = r->mf;
        uint16_t a_all3 = r->a;
        if (m_ret2) {
            uint8_t value16 = RAM8(0x0000 + sp0 - 3);
            uint8_t value17 = RAM8(0x0000 + sp0 - 2);
            uint8_t value18 = RAM8(0x0000 + sp0 - 1);
            uint8_t value19 = RAM8(0x0000 + sp0);
            r->a = (a_all3 >> 8 << 8) | value16;
            r->c = value17 & 0x01;
            r->z = ((value19 << 8) | value18) == 0;
            r->n = ((value19 << 8) | value18) & 0x8000;
            r->v = value17 & 0x40;
            r->mf = value17 & 0x20;
            r->xf = value17 & 0x10;
            r->dp = (value19 << 8) | value18;
            r->i = value17 & 0x04;
            r->d = value17 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
}
SOM_REGISTER(0xC13597, SOM_RTS, "gen", cycle_spell_entity_blue_color, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 54, 32)
