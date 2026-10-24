#include "som_c.h"
#include "som_hand_b.h"

/* D9FE08 set_native_inventory_descriptor_disabled_flag   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/set_native_inventory_descriptor_disabled_flag.s
 * Documented in docs/event-menu-inventory-masks.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void set_native_inventory_descriptor_disabled_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (!hand_rd_ok(0x0018A0 + x) || !hand_rd_ok(0x0018A0 + x + 1)) { c->fail = 3; return; } /* open bus: out of contract */
    uint16_t value = BUS16(c, 0x0018A0 + x); /* DB is $00: the indexed address leaves WRAM when X is large */
    BUS16_SET(c, 0x0018A0 + x, value | 0x4000);
    r->a = value | 0x4000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD9FE08, SOM_RTS, "hand", set_native_inventory_descriptor_disabled_flag, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 10, 4)
