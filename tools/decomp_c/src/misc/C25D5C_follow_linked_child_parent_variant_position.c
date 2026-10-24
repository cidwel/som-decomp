#include "som_c.h"

/* C25D5C follow_linked_child_parent_variant_position   [class B, 43 bytes, 18 instructions]
 * Source: src/rom/follow_linked_child_parent_variant_position.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void follow_linked_child_parent_variant_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(0x007A + value);
    uint8_t a_hi1;
    if (value3 != 0) {
        uint16_t value4 = RAM16(0x002B + value2);
        RAM16_SET(0x002B + value, (uint16_t)(value4 + 6));
        a_hi1 = (uint16_t)(value4 + 6) >> 8;
    } else {
        uint16_t value5 = RAM16(0x002B + value2);
        RAM16_SET(0x002B + value, (uint16_t)(value5 - 6));
        a_hi1 = (uint16_t)(value5 - 6) >> 8;
    }
    uint16_t value6 = RAM16(0x0032 + value2);
    RAM16_SET(0x0032 + value, (uint16_t)(value6 - 0x20));
    r->a = (uint16_t)(value6 - 0x20);
    r->x = value;
    r->y = value2;
    r->c = value6 >= 0x20;
    r->v = ((value6 ^ 0x20) & (value6 ^ (uint16_t)(value6 - 0x20)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25D5C, SOM_RTS, "gen", follow_linked_child_parent_variant_position, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 43, 18)
