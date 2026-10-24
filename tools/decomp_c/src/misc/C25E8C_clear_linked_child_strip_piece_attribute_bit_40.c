#include "som_c.h"

/* C25E8C clear_linked_child_strip_piece_attribute_bit_40   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/clear_linked_child_strip_piece_attribute_bit_40.s
 * Documented in docs/boss-native-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void clear_linked_child_strip_piece_attribute_bit_40(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0289);
    uint16_t value2 = RAM16(0x0002 + (uint16_t)(value + 0x15));
    RAM16_SET(0x0002 + (uint16_t)(value + 0x15), value2 & 0xFFBF);
    r->a = value2 & 0xFFBF;
    r->y = (uint16_t)(value + 0x15);
    r->v = ((value ^ (uint16_t)(value + 0x15)) & ((uint16_t)(value + 0x15) ^ 0x15) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25E8C, SOM_RTS, "gen", clear_linked_child_strip_piece_attribute_bit_40, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 17, 8)
