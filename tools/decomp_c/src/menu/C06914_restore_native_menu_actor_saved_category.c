#include "som_c.h"

/* C06914 restore_native_menu_actor_saved_category   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/restore_native_menu_actor_saved_category.s
 * Documented in docs/event-menu-ring-waits.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void restore_native_menu_actor_saved_category(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint8_t ring_owner = RAM8(RING_OWNER);
    uint8_t value = RAM8(0x1870 + ring_owner);
    RAM8(RING_CATEGORY) = value;
    r->a = (a >> 8 << 8) | value;
    r->x = ring_owner;
    r->y = (uint8_t)y;
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06914, SOM_RTS, "gen", restore_native_menu_actor_saved_category, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)
