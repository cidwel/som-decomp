#include "som_c.h"

/* C1356D rotate_spell_entity_palette_words   [class B, 42 bytes, 24 instructions]
 * Source: src/rom/rotate_spell_entity_palette_words.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void rotate_spell_entity_palette_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0 - 2) = 3;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 5) = x >> 8;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), y);
    uint8_t value = RAM8(0x0018 + y);
    uint16_t value2 = RAM16(0x0000 + y);
    r->a = ((value & 0x0F) + 4 << 8) | value;
    r->x = value2;
    r->c = (value & 0x0F) + 4 > 0xFF;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->v = (((value & 0x0F) ^ (value & 0x0F) + 4) & ((value & 0x0F) + 4 ^ 4) & 0x80) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3589, 0xC1433E); GUARD_JSR(c, sp_call, 0x3589); } /* rotate_spell_entity_words_backward */
    r->sp += 5;
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value3 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        uint8_t value4 = RAM8(0x0000 + value3);
        r->x = value4;
        r->y = value3;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3591, 0xC141F8); GUARD_JSR(c, sp_call, 0x3591); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 5;
        bool m_ret2 = r->mf;
        uint16_t a_all2 = r->a;
        if (m_ret2) {
            uint8_t value6 = RAM8(0x0000 + sp0 - 5);
            uint8_t value7 = RAM8(0x0000 + sp0 - 4);
            uint8_t value8 = RAM8(0x0000 + sp0 - 3);
            uint8_t value9 = RAM8(0x0000 + sp0 - 2);
            r->a = (a_all2 >> 8 << 8) | value6;
            r->c = value7 & 0x01;
            r->z = ((value9 << 8) | value8) == 0;
            r->n = ((value9 << 8) | value8) & 0x8000;
            r->v = value7 & 0x40;
            r->mf = value7 & 0x20;
            r->xf = value7 & 0x10;
            r->dp = (value9 << 8) | value8;
            r->i = value7 & 0x04;
            r->d = value7 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint8_t value12 = RAM8(0x0000 + sp0 - 4);
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->a = (value13 << 8) | value12;
            r->c = value14 & 0x01;
            r->z = ((value16 << 8) | value15) == 0;
            r->n = ((value16 << 8) | value15) & 0x8000;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 2;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value17 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        uint16_t value18 = RAM16(0x0000 + value17);
        r->x = value18;
        r->y = value17;
        r->z = value18 == 0;
        r->n = value18 & 0x8000;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3591, 0xC141F8); GUARD_JSR(c, sp_call, 0x3591); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 5;
        bool m_ret3 = r->mf;
        uint16_t a_all3 = r->a;
        if (m_ret3) {
            uint8_t value20 = RAM8(0x0000 + sp0 - 5);
            uint8_t value21 = RAM8(0x0000 + sp0 - 4);
            uint8_t value22 = RAM8(0x0000 + sp0 - 3);
            uint8_t value23 = RAM8(0x0000 + sp0 - 2);
            r->a = (a_all3 >> 8 << 8) | value20;
            r->c = value21 & 0x01;
            r->z = ((value23 << 8) | value22) == 0;
            r->n = ((value23 << 8) | value22) & 0x8000;
            r->v = value21 & 0x40;
            r->mf = value21 & 0x20;
            r->xf = value21 & 0x10;
            r->dp = (value23 << 8) | value22;
            r->i = value21 & 0x04;
            r->d = value21 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint8_t value26 = RAM8(0x0000 + sp0 - 4);
            uint8_t value27 = RAM8(0x0000 + sp0 - 3);
            uint8_t value28 = RAM8(0x0000 + sp0 - 2);
            uint8_t value29 = RAM8(0x0000 + sp0 - 1);
            uint8_t value30 = RAM8(0x0000 + sp0);
            r->a = (value27 << 8) | value26;
            r->c = value28 & 0x01;
            r->z = ((value30 << 8) | value29) == 0;
            r->n = ((value30 << 8) | value29) & 0x8000;
            r->v = value28 & 0x40;
            r->mf = value28 & 0x20;
            r->xf = value28 & 0x10;
            r->dp = (value30 << 8) | value29;
            r->i = value28 & 0x04;
            r->d = value28 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 2;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC1356D, SOM_RTS, "gen", rotate_spell_entity_palette_words, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 42, 24)
