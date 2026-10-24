#include "som_c.h"

/* D3FDBD construct_spell_random_fallback_object   [class B, 124 bytes, 64 instructions]
 * Source: src/rom/construct_spell_random_fallback_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void construct_spell_random_fallback_object(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0003 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) = (value2 >> 4) & 7;
    r->a = (value >> 8 << 8) | 0;
    r->x = 0x014A;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0A);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFDE2, 0xC12E78); GUARD_JSL(c, sp_call, 0xFDE2); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 10;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), x_ret);
    uint8_t value3 = RAM8(0x0003 + (uint16_t)(sp0 - 0x0A));
    r->a = ((uint16_t)(x_ret + 0x0140) >> 8 << 8) | value3;
    r->x = (uint16_t)(x_ret + 0x0140);
    r->c = x_ret + 0x0140 > 0xFFFF;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->v = ((x_ret ^ (uint16_t)(x_ret + 0x0140)) & ((uint16_t)(x_ret + 0x0140) ^ 0x0140) & 0x8000) != 0;
    r->mf = 1;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFDF4, 0xC12EB1); GUARD_JSL(c, sp_call, 0xFDF4); } /* position_spell_entity_from_actor_long */
    r->sp += 10;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
    BUS8_SET(c, (uint16_t)(dp_ret + 7), 0);
    BUS16_SET(c, (uint16_t)(dp_ret + 1), 0x14);
    uint8_t a_hi1 = 0;
    uint16_t x1 = value4;
    uint16_t y1 = y_ret2;
    bool carry1 = carry_ret2;
    bool overflow1 = overflow_ret2;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = dp_ret;
    for (;;) {
        RAM8(0x0000 + sp0 - 0x0A) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x1;
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
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFE07, 0xC12E80); GUARD_JSL(c, sp_call, 0xFE07); } /* activate_native_entity_sprite_long */
        r->sp += 12;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 6));
        BUS16_SET(c, (db_ret2 << 0x10) + 1 + x_ret3, value5);
        uint8_t value6 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value7 = RAM8(0x0000 + sp0 - 0x0A);
        BUS16_SET(c, (db_ret2 << 0x10) + ((value7 << 8) | value6), x_ret3);
        BUS16_SET(c, (db_ret2 << 0x10) + 0x0C + ((value7 << 8) | value6), 0xFFFF);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value8 - 1));
        a_hi1 = (uint16_t)(((value7 << 8) | value6) + 0x10) >> 8;
        x1 = (uint16_t)(((value7 << 8) | value6) + 0x10);
        y1 = y_ret3;
        carry1 = ((value7 << 8) | value6) + 0x10 > 0xFFFF;
        overflow1 = ((((value7 << 8) | value6) ^ (uint16_t)(((value7 << 8) | value6) + 0x10)) & ((uint16_t)(((value7 << 8) | value6) + 0x10) ^ 0x10) & 0x8000) != 0;
        data_bank = db_ret2;
        direct_page = dp_ret2;
        if (!((uint16_t)(value8 - 1) != 0)) break;
    }
    uint16_t value9 = BUS16_RDP(c, (uint16_t)(direct_page + 4));
    BUS16_SET(c, (data_bank << 0x10) + 0x0148 + value9, 1);
    BUS16_SET(c, (data_bank << 0x10) + 0x0146 + value9, 0x14);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->x = value9;
    r->y = y1;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = data_bank;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FDBD, SOM_RTS, "gen", construct_spell_random_fallback_object, 0, L_X | L_Y, 12, 1, 0, 124, 64)
