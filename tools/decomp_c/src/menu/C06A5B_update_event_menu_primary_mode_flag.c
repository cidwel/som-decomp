#include "som_c.h"

/* C06A5B update_event_menu_primary_mode_flag   [class A, 24 bytes, 12 instructions]
 * Source: src/rom/update_event_menu_primary_mode_flag.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void update_event_menu_primary_mode_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x1802);
    uint8_t value2 = RAM8(0x1820);
    uint8_t a1;
    if (value2 != 0) {
        a1 = value & 0xFE;
    } else {
        a1 = value | 1;
    }
    RAM8(0x1802) = a1;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06A5B, SOM_RTS, "gen", update_event_menu_primary_mode_flag, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 24, 12)
