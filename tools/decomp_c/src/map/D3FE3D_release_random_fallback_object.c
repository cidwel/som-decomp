#include "som_c.h"

/* D3FE3D release_random_fallback_object   [class B, 52 bytes, 31 instructions]
 * Source: src/rom/release_random_fallback_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void release_random_fallback_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 0x14);
    uint8_t a_hi1 = 0;
    uint16_t y1 = x;
    bool carry1 = (uint16_t)(sp0 - 3) >= 4;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 7);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + y1);
        RAM8(0x0000 + sp0 - 7) = y1 >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | a;
        r->x = value;
        r->y = y1;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFE57, 0xC12E88); GUARD_JSL(c, sp_call, 0xFE57); } /* release_spell_sprite_instance_long */
        r->sp += 9;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value2 = RAM8(0x0000 + sp0 - 8);
        uint8_t value3 = RAM8(0x0000 + sp0 - 7);
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value4 - 1));
        a_hi1 = (uint16_t)(((value3 << 8) | value2) + 0x10) >> 8;
        y1 = (uint16_t)(((value3 << 8) | value2) + 0x10);
        carry1 = ((value3 << 8) | value2) + 0x10 > 0xFFFF;
        overflow1 = ((((value3 << 8) | value2) ^ (uint16_t)(((value3 << 8) | value2) + 0x10)) & ((uint16_t)(((value3 << 8) | value2) + 0x10) ^ 0x10) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint16_t)(value4 - 1) != 0)) break;
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
    r->a = (a_hi1 << 8) | a;
    r->x = value5;
    r->y = y1;
    r->c = carry1;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFE67, 0xC12E7C); GUARD_JSL(c, sp_call, 0xFE67); } /* release_spell_entity_heap_bank_long */
    r->sp += 7;
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FE3D, SOM_RTS, "gen", release_random_fallback_object, 0, 0, 9, 1, 0, 52, 31)
