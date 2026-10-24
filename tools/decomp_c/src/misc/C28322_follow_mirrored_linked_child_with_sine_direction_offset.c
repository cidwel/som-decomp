#include "som_c.h"

/* C28322 follow_mirrored_linked_child_with_sine_direction_offset   [class B, 82 bytes, 34 instructions]
 * Source: src/rom/follow_mirrored_linked_child_with_sine_direction_offset.s
 * Documented in docs/boss-native58-action-helpers.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void follow_mirrored_linked_child_with_sine_direction_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    uint16_t value2 = RAM16(0x0098 + value);
    uint8_t a_hi1;
    if ((value2 & 0x40) != 0) {
        uint16_t value3 = RAM16(0x002B + value);
        RAM16_SET(0x002B + x, (uint16_t)(value3 - 0x18));
        a_hi1 = (uint16_t)(value3 - 0x18) >> 8;
    } else {
        uint16_t value4 = RAM16(0x002B + value);
        RAM16_SET(0x002B + x, (uint16_t)(value4 + 0x18));
        a_hi1 = (uint16_t)(value4 + 0x18) >> 8;
    }
    uint16_t value5 = RAM16(0x0032 + value);
    RAM16_SET(0x0032 + x, (uint16_t)(value5 + 0x12));
    RAM16_SET(0x00A9 + x, RAM16(0x00A9 + value));
    uint16_t value7 = RAM16(0x00AB + value);
    RAM16_SET(0x00AB + x, value7);
    r->a = (uint16_t)(value7 << 2);
    r->y = value;
    r->c = (uint16_t)(value7 << 1) & 0x8000;
    r->v = ((value5 ^ (uint16_t)(value5 + 0x12)) & ((uint16_t)(value5 + 0x12) ^ 0x12) & 0x8000) != 0;
    JSR(c, 0x835D, 0xC22A59); /* derive_cosine_by_adding_quarter_turn */
    uint16_t a_all = r->a;
    RAM16_SET(0x0246, a_all);
    RAM16_SET(0x024E, 0x20);
    r->a = 0x20;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8367, 0xC22D69); /* divide_signed_word_by_word_with_remainder */
    uint16_t value8 = RAM16(0x0287);
    uint16_t value9 = RAM16(0x002B + value8);
    uint16_t value10 = RAM16(0x0256);
    RAM16_SET(0x002B + value8, (uint16_t)(value9 + value10));
    r->a = (uint16_t)(value9 + value10);
    r->x = value8;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28322, SOM_RTS, "gen", follow_mirrored_linked_child_with_sine_direction_offset, 0, L_B | L_X | L_V, 1, 0, 0, 82, 34)
