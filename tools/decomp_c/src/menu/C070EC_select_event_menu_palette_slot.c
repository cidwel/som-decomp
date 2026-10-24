#include "som_c.h"

/* C070EC select_event_menu_palette_slot   [class A, 28 bytes, 15 instructions]
 * Source: src/rom/select_event_menu_palette_slot.s
 * Documented in docs/event-menu-palette-graphics.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void select_event_menu_palette_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x1802);
    uint8_t a1;
    if ((value & 1) == 0) {
        a1 = 4;
    } else {
        a1 = 0;
    }
    r->a = ((a >> 8 << 8) | (uint8_t)(a1 + (uint8_t)a)) & 7;
    r->v = ((a1 ^ (uint8_t)(a1 + (uint8_t)a)) & ((uint8_t)a ^ (uint8_t)(a1 + (uint8_t)a)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC070EC, SOM_RTS, "gen", select_event_menu_palette_slot, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 28, 15)
