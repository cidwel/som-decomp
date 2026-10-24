#include "som_c.h"

/* C1392B allocate_spell_entity_sprite_pointer_group   [class B, 48 bytes, 31 instructions]
 * Source: src/rom/allocate_spell_entity_sprite_pointer_group.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void allocate_spell_entity_sprite_pointer_group(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = a_hi;
    uint8_t a_hi1 = (uint8_t)((a_hi << 8) | a);
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        RAM8(0x0000 + sp0 - 5) = x1 >> 8;
        RAM8(0x0000 + sp0 - 6) = (uint8_t)x1;
        r->a = (a_hi1 << 8) | 0x0F;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3941, 0xC12E80); GUARD_JSL(c, sp_call, 0x3941); } /* activate_native_entity_sprite_long */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
        BUS8_SET(c, (db_ret << 0x10) + 1 + x_ret, value);
        uint8_t value2 = RAM8(0x0000 + sp0 - 6);
        uint8_t value3 = RAM8(0x0000 + sp0 - 5);
        BUS16_SET(c, (db_ret << 0x10) + ((value3 << 8) | value2), x_ret);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
        a_hi1 = x_ret >> 8;
        x1 = (uint16_t)(((value3 << 8) | value2) + 2);
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->y = y1;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = data_bank;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1392B, SOM_RTS, "gen", allocate_spell_entity_sprite_pointer_group, 0, L_Y, 7, 1, 0, 48, 31)
