#include "som_c.h"

/* D3F30A release_spell_entity_orbit_sprite_object   [class B, 69 bytes, 40 instructions]
 * Source: src/rom/release_spell_entity_orbit_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void release_spell_entity_orbit_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 8);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(sp0 - 3) >= 6;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 9);
    for (;;) {
        RAM8(0x0000 + sp0 - 9) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)x1;
        BUS16_SET(c, (uint16_t)(direct_page + 1), 2);
        uint8_t a_hi2 = 0;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        bool carry2 = carry1;
        bool overflow2 = overflow1;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            RAM8(0x0000 + sp0 - 0x0B) = x2 >> 8;
            RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)x2;
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
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF329, 0xC12EB9); GUARD_JSL(c, sp_call, 0xF329); } /* release_spell_entity_sprite_pointer_group_long */
            r->sp += 13;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t y_ret = r->y;
            uint8_t value = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value2 = RAM8(0x0000 + sp0 - 0x0B);
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value3 - 1));
            a_hi2 = (uint16_t)(((value2 << 8) | value) + 0x0C) >> 8;
            x2 = (uint16_t)(((value2 << 8) | value) + 0x0C);
            y2 = y_ret;
            carry2 = ((value2 << 8) | value) + 0x0C > 0xFFFF;
            overflow2 = ((((value2 << 8) | value) ^ (uint16_t)(((value2 << 8) | value) + 0x0C)) & ((uint16_t)(((value2 << 8) | value) + 0x0C) ^ 0x0C) & 0x8000) != 0;
            data_bank2 = db_ret;
            direct_page2 = dp_ret;
            if (!((uint16_t)(value3 - 1) != 0)) break;
        }
        uint8_t value4 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value5 = RAM8(0x0000 + sp0 - 9);
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page2 + 3));
        BUS16_RMW_SET(c, (uint16_t)(direct_page2 + 3), (uint16_t)(value6 - 1));
        a_hi1 = (uint16_t)(((value5 << 8) | value4) + 0x1C) >> 8;
        x1 = (uint16_t)(((value5 << 8) | value4) + 0x1C);
        y1 = y2;
        carry1 = ((value5 << 8) | value4) + 0x1C > 0xFFFF;
        overflow1 = ((((value5 << 8) | value4) ^ (uint16_t)(((value5 << 8) | value4) + 0x1C)) & ((uint16_t)(((value5 << 8) | value4) + 0x1C) ^ 0x1C) & 0x8000) != 0;
        data_bank = data_bank2;
        direct_page = direct_page2;
        if (!((uint16_t)(value6 - 1) != 0)) break;
    }
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(direct_page + 5));
    r->a = (a_hi1 << 8) | a;
    r->x = value7;
    r->y = y1;
    r->c = carry1;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF345, 0xC12E7C); GUARD_JSL(c, sp_call, 0xF345); } /* release_spell_entity_heap_bank_long */
    r->sp += 9;
    if (r->mf != 0) { c->fail = 3; return; }
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F30A, SOM_RTS, "gen", release_spell_entity_orbit_sprite_object, 0, 0, 13, 1, 0, 69, 40)
