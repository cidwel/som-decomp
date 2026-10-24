#include "som_c.h"

/* D0D9B4 read_consumable_inventory_quantity   [class A, 11 bytes, 8 instructions]
 * Source: src/rom/read_consumable_inventory_quantity.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABYC.
 */
static void read_consumable_inventory_quantity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xD9B8, 0xD0D9BF); /* read_consumable_inventory_record */
    uint16_t a_all = r->a;
    r->a = a_all >> 5;
    r->c = a_all >> 4 & 0x01;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D9B4, SOM_RTS, "gen", read_consumable_inventory_quantity, 0, L_A | L_B | L_Y | L_C, 1, 0, 0, 11, 8)
