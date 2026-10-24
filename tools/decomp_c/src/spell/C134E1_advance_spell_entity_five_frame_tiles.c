#include "som_c.h"

/* C134E1 advance_spell_entity_five_frame_tiles   [class B, 70 bytes, 39 instructions]
 * Source: src/rom/advance_spell_entity_five_frame_tiles.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_spell_entity_five_frame_tiles(SomCtx *c)
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
    uint16_t value = RAM16(0x0016 + y);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + 1) < 5) {
        a1 = (uint8_t)(value + 1);
        a_hi1 = (uint16_t)(value + 1) >> 8;
    } else {
        a1 = 0;
        a_hi1 = 0;
    }
    RAM16_SET(0x0016 + y, (a_hi1 << 8) | a1);
    uint16_t value2 = RAM16(0x0016 + y);
    uint16_t value3 = RAM16(0x001A + y);
    uint16_t value4 = RAM16(0x0018 + y);
    uint16_t value5 = RAM16(0x0000 + y);
    r->a = 0xD104;
    r->x = (uint16_t)(((value4 & 0x0F) << 1) + value5);
    r->y = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi1 << 8) | a1) << 2) + value2) << 1) + value3);
    r->c = ((value4 & 0x0F) << 1) + value5 > 0xFFFF;
    r->z = 0;
    r->n = 1;
    r->v = ((((value4 & 0x0F) << 1) ^ (uint16_t)(((value4 & 0x0F) << 1) + value5)) & (value5 ^ (uint16_t)(((value4 & 0x0F) << 1) + value5)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3517, 0xC14297); GUARD_JSR(c, sp_call, 0x3517); } /* copy_spell_entity_sprite_record_words */
    r->sp += 5;
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value6 = RAM8(0x0001 + (uint16_t)(sp0 - 5));
        uint8_t value7 = RAM8(0x0000 + value6);
        r->x = value7;
        r->y = value6;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x351F, 0xC141F8); GUARD_JSR(c, sp_call, 0x351F); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 5;
        uint16_t a_all2 = r->a;
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (a_all2 >> 8 << 8) | value9;
        r->c = value10 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value10 & 0x40;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value13 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
        uint16_t value14 = RAM16(0x0000 + value13);
        r->x = value14;
        r->y = value13;
        r->z = value14 == 0;
        r->n = value14 & 0x8000;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x351F, 0xC141F8); GUARD_JSR(c, sp_call, 0x351F); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 5;
        uint16_t a_all3 = r->a;
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
    }
}
SOM_REGISTER(0xC134E1, SOM_RTS, "gen", advance_spell_entity_five_frame_tiles, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 70, 39)
