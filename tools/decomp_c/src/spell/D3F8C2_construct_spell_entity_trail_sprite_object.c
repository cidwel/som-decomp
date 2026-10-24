#include "som_c.h"

/* D3F8C2 construct_spell_entity_trail_sprite_object   [class B, 189 bytes, 97 instructions]
 * Source: src/rom/construct_spell_entity_trail_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: X.
 */
static void construct_spell_entity_trail_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x7 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0C)) = (uint8_t)value;
    RAM8(0x0005 + (uint16_t)(sp0 - 0x0C)) = value >> 0x0E;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), y);
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0004 + (uint16_t)(sp0 - 0x0C)) = (value2 >> 4) & 7;
    r->a = ((uint8_t)value << 8) | 0;
    r->x = 0x0156;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 7) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0C)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0C);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF8F2, 0xC12E78); GUARD_JSL(c, sp_call, 0xF8F2); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 12;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), x_ret);
    uint8_t value3 = RAM8(0x0001 + (uint16_t)(sp0 - 0x0C));
    r->a = ((uint16_t)(x_ret + 0x0140) >> 8 << 8) | value3;
    r->x = (uint16_t)(x_ret + 0x0140);
    r->c = x_ret + 0x0140 > 0xFFFF;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->v = ((x_ret ^ (uint16_t)(x_ret + 0x0140)) & ((uint16_t)(x_ret + 0x0140) ^ 0x0140) & 0x8000) != 0;
    r->mf = 1;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF904, 0xC12EB1); GUARD_JSL(c, sp_call, 0xF904); } /* position_spell_entity_from_actor_long */
    r->sp += 12;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
    BUS8_SET(c, (db_ret << 0x10) + 0x0146 + value4, value5);
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
    BUS8_SET(c, (db_ret << 0x10) + 0x0144 + value4, value6);
    BUS8_SET(c, (db_ret << 0x10) + 0x0152 + value4, 1);
    r->a = (a_all2 >> 8 << 8) | 4;
    r->x = value4;
    r->z = 0;
    r->n = 0;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF91B, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF91B); } /* draw_spell_entity_bounded_random_long */
    r->sp += 12;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
    BUS8_SET(c, (db_ret2 << 0x10) + 0x014E + value7, (uint8_t)((uint8_t)a_all3 + 2));
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
    BUS8_SET(c, (db_ret2 << 0x10) + 0x014C + value7, value8);
    uint8_t a_hi2;
    if ((((a_all3 >> 8 << 8) | value8) & 0xFF) == 0) {
        BUS16_SET(c, (db_ret2 << 0x10) + 0x014A + value7, 0x10);
        a_hi2 = 0;
    } else {
        uint8_t a_hi1;
        if ((uint16_t)((((a_all3 >> 8 << 8) | value8) & 0xFF) - 1) == 0) {
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0148 + value7, 0x10);
            a_hi1 = 0;
        } else {
            if ((uint16_t)((((a_all3 >> 8 << 8) | value8) & 0xFF) - 2) == 0) {
                BUS16_SET(c, (db_ret2 << 0x10) + 0x014A + value7, 0xFFF0);
            } else {
                BUS16_SET(c, (db_ret2 << 0x10) + 0x0148 + value7, 0xFFF0);
            }
            a_hi1 = 0xFF;
        }
        a_hi2 = a_hi1;
    }
    BUS16_SET(c, (uint16_t)(dp_ret + 8), 0x14);
    uint8_t a_hi3 = 0;
    uint16_t x1 = value7;
    uint16_t y1 = y_ret3;
    bool carry1 = carry_ret3;
    bool overflow1 = overflow_ret3;
    uint8_t data_bank = db_ret2;
    uint16_t direct_page = dp_ret;
    for (;;) {
        RAM8(0x0000 + sp0 - 0x0C) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)x1;
        r->a = 0x0F;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF95F, 0xC12E80); GUARD_JSL(c, sp_call, 0xF95F); } /* activate_native_entity_sprite_long */
        r->sp += 14;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 4));
        BUS16_SET(c, (db_ret3 << 0x10) + 1 + x_ret4, value9);
        uint8_t value10 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value11 = RAM8(0x0000 + sp0 - 0x0C);
        BUS16_SET(c, (db_ret3 << 0x10) + ((value11 << 8) | value10), x_ret4);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 8));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 8), (uint16_t)(value12 - 1));
        a_hi3 = (uint16_t)(((value11 << 8) | value10) + 0x10) >> 8;
        x1 = (uint16_t)(((value11 << 8) | value10) + 0x10);
        y1 = y_ret4;
        carry1 = ((value11 << 8) | value10) + 0x10 > 0xFFFF;
        overflow1 = ((((value11 << 8) | value10) ^ (uint16_t)(((value11 << 8) | value10) + 0x10)) & ((uint16_t)(((value11 << 8) | value10) + 0x10) ^ 0x10) & 0x8000) != 0;
        data_bank = db_ret3;
        direct_page = dp_ret2;
        if (!((uint16_t)(value12 - 1) != 0)) break;
    }
    uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page + 2));
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->x = value13;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = data_bank;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F8C2, SOM_RTS, "gen", construct_spell_entity_trail_sprite_object, 0, L_X, 14, 1, 0, 189, 97)
