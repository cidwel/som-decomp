#include "som_c.h"
#include "som_hand_b.h"

/* C2B55A clone_second_layer_trigger_tile   [class B, 67 bytes, 33 instructions]
 * Source: src/rom/clone_second_layer_trigger_tile.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: Y.
 */
static void clone_second_layer_trigger_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    /* All table accesses are absolute,X / absolute,Y in bank $7F: 16-bit index plus base can carry into bank $80. */
    const uint16_t y_saved = r->y;
    uint16_t index = RAM16(0x0018);
    uint16_t x = r->x;
    bus16_set_once(c, 0x7F0000u + 0xBF00 + index, BUS16(c, 0x7F0000u + 0xBC00 + x));
    bus16_set_once(c, 0x7F0000u + 0xBF02 + index, BUS16(c, 0x7F0000u + 0xBC02 + x));
    x = (uint16_t)(x << 1);
    uint16_t y = (uint16_t)(index << 1);
    for (unsigned k = 0; k < 8; k += 2) {
        bus16_set_once(c, 0x7F0000u + 0xCE00 + k + y, BUS16(c, 0x7F0000u + 0xC800 + k + x));
    }
    r->x = x;
    r->y = y_saved; /* PLY */
    uint8_t flags = (uint8_t)(((uint8_t)RAM16(0x0018) >> 2) | 0xC0);
    uint32_t ptr = (uint32_t)(0x7F0000u + RAM16(0x0010));
    BUS8_SET(c, ptr + y_saved, flags);
    RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) + 4));
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B55A, SOM_RTL, "hand", clone_second_layer_trigger_tile, 0, L_Y, 2, 0, 0, 67, 33)
