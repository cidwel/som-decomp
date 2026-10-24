#include "som_c.h"

/* C25E44 advance_linked_child_strip_ring_and_parent_coordinates   [class B, 25 bytes, 10 instructions]
 * Source: src/rom/advance_linked_child_strip_ring_and_parent_coordinates.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void advance_linked_child_strip_ring_and_parent_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B6 + value);
    RAM16_SET(0x00B6 + value, (uint16_t)(value2 + 1) & 0x0F);
    r->a = (uint16_t)(value2 + 1) & 0x0F;
    r->x = value;
    JSR(c, 0x5E52, 0xC25E9D); /* consume_linked_child_request_and_select_native_definition */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5E55, 0xC25D5C); /* follow_linked_child_parent_variant_position */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5E58, 0xC25EC9); /* interpolate_linked_child_four_piece_strip_history */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5E5B, 0xC25F60); /* construct_linked_child_six_piece_strip_records */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25E44, SOM_RTS, "gen", advance_linked_child_strip_ring_and_parent_coordinates, 0, L_B | L_X | L_Y, 1, 0, 0, 25, 10)
