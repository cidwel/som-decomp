#include "som_c.h"

/* C13D8F initialize_spell_entity_oam_workspace   [class B, 236 bytes, 126 instructions]
 * Source: src/rom/initialize_spell_entity_oam_workspace.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_oam_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x8421) = (uint8_t)value & 2;
    RAM8(0x8420) = (uint8_t)value & 1;
    RAM8(0x0003 + (uint16_t)(sp0 - 7)) = value >> 8;
    RAM8(0x8422) = 0;
    r->a = (((uint8_t)value & 1) << 8) | 0;
    r->x = 0x0400;
    r->c = (uint16_t)(sp0 - 5) >= 2;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3DBF, 0xC13D48); GUARD_JSR(c, sp_call, 0x3DBF); } /* allocate_and_fill_spell_entity_heap_bytes */
    r->sp += 8;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x841A, x_ret);
    RAM16_SET(0x841E, 0x0800);
    r->a = (a_all >> 8 << 8) | 0;
    r->x = 0x0100;
    r->z = 0;
    r->n = 0;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3DD0, 0xC13D48); GUARD_JSR(c, sp_call, 0x3DD0); } /* allocate_and_fill_spell_entity_heap_bytes */
    r->sp += 8;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x841C, x_ret2);
    uint16_t value2 = RAM16(0x841A);
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x40;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = value2;
    uint16_t direct_page = (uint16_t)(sp0 - 7);
    for (;;) {
        RAM8(0x0000 + sp0 - 8) = x1 >> 8;
        RAM8(0x0000 + sp0 - 9) = (uint8_t)x1;
        RAM16_SET(0x0002 + x1, 0xFFF0);
        RAM16_SET(0x0004 + x1, 0);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
        RAM8(0x000A + x1) = (uint8_t)(0x40 - value3);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 3));
        RAM8(0x000B + x1) = value4 >> 2;
        RAM8(0x0008 + x1) = 0;
        r->a = (0xFF << 8) | (value4 >> 2);
        r->x = x1;
        r->c = value4 >> 1 & 0x01;
        r->z = value4 >> 2 == 0;
        r->n = value4 >> 2 & 0x80;
        r->v = ((value3 ^ 0x40) & ((uint8_t)(0x40 - value3) ^ 0x40) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3DFD, 0xC13E9C); GUARD_JSR(c, sp_call, 0x3DFD); } /* project_spell_entity_sprite_record_to_oam */
        r->sp += 10;
        uint16_t dp_ret = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value5 = RAM8(0x0000 + sp0 - 9);
        uint8_t value6 = RAM8(0x0000 + sp0 - 8);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value7 - 1));
        a_hi1 = (uint16_t)(((value6 << 8) | value5) + 0x10) >> 8;
        x1 = (uint16_t)(((value6 << 8) | value5) + 0x10);
        direct_page = dp_ret;
        if (!((uint8_t)(value7 - 1) != 0)) break;
    }
    uint16_t value8 = RAM16(0x841C);
    uint16_t value9 = RAM16(0x841A);
    BUS16_SET(c, (uint16_t)(direct_page + 1), 0x10);
    uint8_t a_hi2 = 0;
    uint16_t x2 = value8;
    uint16_t y1 = value9;
    for (;;) {
        RAM16_SET(0x0000 + x2, y1);
        RAM16_SET(0x000C + y1, x2);
        RAM16_SET(0x0002 + x2, (uint16_t)(y1 + 0x10));
        RAM16_SET(0x000C + (uint16_t)(y1 + 0x10), x2);
        RAM16_SET(0x0004 + x2, (uint16_t)(y1 + 0x20));
        RAM16_SET(0x000C + (uint16_t)(y1 + 0x20), x2);
        RAM16_SET(0x0006 + x2, (uint16_t)(y1 + 0x30));
        RAM16_SET(0x000C + (uint16_t)(y1 + 0x30), x2);
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
        RAM8(0x0009 + x2) = (uint8_t)((uint8_t)(0x10 - value10) << 2);
        RAM8(0x000A + x2) = (uint8_t)((uint8_t)(0x10 - value10) << 3);
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(direct_page + 3));
        RAM8(0x000B + x2) = value11;
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
        BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value12 - 1));
        uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
        uint16_t x2_next = (uint16_t)(x2 + 0x10);
        uint16_t y1_next = (uint16_t)(y1 + 0x40);
        a_hi2 = a_hi2_next;
        x2 = x2_next;
        y1 = y1_next;
        if (!((uint16_t)(value12 - 1) != 0)) break;
    }
    uint8_t value13 = RAM8(0x0000 + sp0 - 7);
    uint8_t value17 = RAM8(0x0000 + sp0 - 3);
    uint8_t value18 = RAM8(0x0000 + sp0 - 2);
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | value17;
    r->x = x2;
    r->y = y1;
    r->c = value18 & 0x01;
    r->z = ((value20 << 8) | value19) == 0;
    r->n = ((value20 << 8) | value19) & 0x8000;
    r->v = value18 & 0x40;
    r->mf = value18 & 0x20;
    r->xf = value18 & 0x10;
    r->db = value13;
    r->dp = (value20 << 8) | value19;
    r->i = value18 & 0x04;
    r->d = value18 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13D8F, SOM_RTS, "gen", initialize_spell_entity_oam_workspace, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 0, 0, 236, 126)
