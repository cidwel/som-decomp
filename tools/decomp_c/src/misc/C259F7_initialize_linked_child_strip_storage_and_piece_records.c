#include "som_c.h"

/* C259F7 initialize_linked_child_strip_storage_and_piece_records   [class B, 66 bytes, 28 instructions]
 * Source: src/rom/initialize_linked_child_strip_storage_and_piece_records.s
 * Documented in docs/boss-native-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_linked_child_strip_storage_and_piece_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x009E + x, 0);
    RAM16_SET(0x0083 + x, 0);
    RAM16_SET(0x00BC + x, 0);
    RAM16_SET(0x00BE + x, 0);
    RAM16_SET(0x00C0 + x, 0);
    RAM16_SET(0x00C2 + x, 0);
    RAM16_SET(0x00B8 + x, 0);
    RAM16_SET(0x00BA + x, 0);
    RAM16_SET(0x00B6 + x, 0);
    RAM16_SET(0x0000 + x, 1);
    RAM16_SET(0x008E + x, 0x5CC8);
    uint16_t value = RAM16(0x007A + x);
    uint16_t x1 = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1);
    uint16_t y1 = 0x80;
    for (;;) {
        RAM16_SET(0xF500 + x1, 0);
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    r->a = 0;
    JSR(c, 0x5A36, 0xC25F60); /* construct_linked_child_six_piece_strip_records */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC259F7, SOM_RTS, "gen", initialize_linked_child_strip_storage_and_piece_records, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 66, 28)
