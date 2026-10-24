#include "som_c.h"

/* C1C357 rotate_map_graphics_two_tiles_right   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/rotate_map_graphics_two_tiles_right.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0000.  Callers read: BZ.
 */
static void rotate_map_graphics_two_tiles_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x000A, (uint16_t)(value + 0x20));
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)));
    RAM16_SET(0x000C, (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)));
    uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)) >> 8;
    uint8_t y1 = 0x1F;
    for (;;) {
        uint8_t value2 = BUS8_RDP(c, RAM16(0x000A) + 0x7F0000 + y1);
        RAM8(0x0000 + sp0) = value2;
        uint8_t value3 = BUS8_RDP(c, RAM16(0x0006) + 0x7F0000 + y1);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + y1, (value3 >> 1) | ((value2 & 1) << 7));
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + y1, (RAM8(0x0000 + sp0) >> 1) | ((value3 & 1) << 7));
        y1 = (uint8_t)(y1 - 1);
        if (!(!(y1 & 0x80))) break;
    }
    uint16_t value5 = RAM16(0x0008);
    RAM16_SET(0x0006, value5);
    r->a = value5;
    r->z = value5 == 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C357, SOM_RTS, "gen", rotate_map_graphics_two_tiles_right, 0, L_B | L_Z, 1, 1, 0, 47, 26)
