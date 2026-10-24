#include "som_c.h"

/* C75148 append_native_name_entry_oam_corner   [class A, 26 bytes, 14 instructions]
 * Source: src/rom/append_native_name_entry_oam_corner.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_name_entry_oam_corner(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x9C00 + x) = RAM8(0xA173);
    RAM8(0x9C00 + (uint16_t)(x + 1)) = RAM8(0xA174);
    RAM8(0x9C00 + (uint16_t)(x + 2)) = (uint8_t)y;
    RAM8(0x9C00 + (uint16_t)(x + 3)) = y >> 8;
    r->x = (uint16_t)(x + 4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75148, SOM_RTS, "gen", append_native_name_entry_oam_corner, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 26, 14)
