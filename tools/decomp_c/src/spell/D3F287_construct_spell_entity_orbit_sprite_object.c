#include "som_c.h"

/* D3F287 construct_spell_entity_orbit_sprite_object   [class B, 127 bytes, 69 instructions]
 * Source: src/rom/construct_spell_entity_orbit_sprite_object.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: X.
 */
static void construct_spell_entity_orbit_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0008 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0007 + (uint16_t)(sp0 - 0x0B)) = (value2 >> 4) & 7;
    r->a = (value >> 8 << 8) | 0;
    r->x = 0xEE;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 6) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF2AC, 0xC12E78); GUARD_JSL(c, sp_call, 0xF2AC); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 11;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0B), x_ret);
    uint8_t value3 = RAM8(0x0008 + (uint16_t)(sp0 - 0x0B));
    r->a = ((uint16_t)(x_ret + 0xE0) >> 8 << 8) | value3;
    r->x = (uint16_t)(x_ret + 0xE0);
    r->c = x_ret + 0xE0 > 0xFFFF;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->v = ((x_ret ^ (uint16_t)(x_ret + 0xE0)) & ((uint16_t)(x_ret + 0xE0) ^ 0xE0) & 0x8000) != 0;
    r->mf = 1;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF2BE, 0xC12EB1); GUARD_JSL(c, sp_call, 0xF2BE); } /* position_spell_entity_from_actor_long */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
    BUS16_SET(c, (uint16_t)(dp_ret + 3), 8);
    uint8_t a_hi1 = 0;
    uint16_t x1 = value4;
    uint16_t y1 = y_ret2;
    bool carry1 = carry_ret2;
    bool overflow1 = overflow_ret2;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = dp_ret;
    for (;;) {
        RAM8(0x0000 + sp0 - 0x0B) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)x1;
        BUS16_SET(c, (uint16_t)(direct_page + 1), 2);
        uint8_t a_hi2 = 0;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        bool carry2 = carry1;
        bool overflow2 = overflow1;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            RAM8(0x0000 + sp0 - 0x0D) = x2 >> 8;
            RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)x2;
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page2 + 7));
            r->a = 4;
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->z = 0;
            r->n = 0;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 15;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF2D8, 0xC12EB5); GUARD_JSL(c, sp_call, 0xF2D8); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 15;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t y_ret3 = r->y;
            uint8_t value6 = RAM8(0x0000 + sp0 - 0x0E);
            uint8_t value7 = RAM8(0x0000 + sp0 - 0x0D);
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value8 - 1));
            a_hi2 = (uint16_t)(((value7 << 8) | value6) + 0x0C) >> 8;
            x2 = (uint16_t)(((value7 << 8) | value6) + 0x0C);
            y2 = y_ret3;
            carry2 = ((value7 << 8) | value6) + 0x0C > 0xFFFF;
            overflow2 = ((((value7 << 8) | value6) ^ (uint16_t)(((value7 << 8) | value6) + 0x0C)) & ((uint16_t)(((value7 << 8) | value6) + 0x0C) ^ 0x0C) & 0x8000) != 0;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret2;
            if (!((uint16_t)(value8 - 1) != 0)) break;
        }
        uint8_t value9 = RAM8(0x0000 + sp0 - 0x0C);
        uint8_t value10 = RAM8(0x0000 + sp0 - 0x0B);
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page2 + 3));
        BUS16_RMW_SET(c, (uint16_t)(direct_page2 + 3), (uint16_t)(value11 - 1));
        a_hi1 = (uint16_t)(((value10 << 8) | value9) + 0x1C) >> 8;
        x1 = (uint16_t)(((value10 << 8) | value9) + 0x1C);
        y1 = y2;
        carry1 = ((value10 << 8) | value9) + 0x1C > 0xFFFF;
        overflow1 = ((((value10 << 8) | value9) ^ (uint16_t)(((value10 << 8) | value9) + 0x1C)) & ((uint16_t)(((value10 << 8) | value9) + 0x1C) ^ 0x1C) & 0x8000) != 0;
        data_bank = data_bank2;
        direct_page = direct_page2;
        if (!((uint16_t)(value11 - 1) != 0)) break;
    }
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 5));
    BUS16_SET(c, (data_bank << 0x10) + 0xE8 + value12, 1);
    BUS16_SET(c, (data_bank << 0x10) + 0xE6 + value12, 0x10);
    uint8_t value13 = RAM8(0x0000 + sp0 - 2);
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    r->x = value12;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->db = data_bank;
    r->dp = (value15 << 8) | value14;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F287, SOM_RTS, "gen", construct_spell_entity_orbit_sprite_object, 0, L_X, 15, -1, 0, 127, 69)
