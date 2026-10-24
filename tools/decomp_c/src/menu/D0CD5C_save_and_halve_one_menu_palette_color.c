#include "som_c.h"
#include "som_hand_b.h"

/* D0CD5C save_and_halve_one_menu_palette_color   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/save_and_halve_one_menu_palette_color.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void save_and_halve_one_menu_palette_color(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (!hand_rd_ok(0x0600 + x) || !hand_rd_ok(0x0600 + x + 1)) { c->fail = 3; return; } /* open bus: out of contract */
    uint16_t value = BUS16(c, 0x0600 + x);
    RAM16_SET(0x8000 + x, value);
    BUS16_SET(c, 0x0600 + x, (value >> 1) & 0x3DEF);
    r->a = (value >> 1) & 0x3DEF;
    r->x = (uint16_t)(x + 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CD5C, SOM_RTS, "hand", save_and_halve_one_menu_palette_color, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 17, 8)
