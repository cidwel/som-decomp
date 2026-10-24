#include "som_c.h"

/* C00051 jump_public_event_inventory_command   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_event_inventory_command.s
 * Documented in docs/event-vm-inventory-command.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BXYCV.
 */
static void jump_public_event_inventory_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06420, SOM_RTL); /* jump_native_inventory_insert_command */
}
SOM_REGISTER(0xC00051, SOM_RTL, "gen", jump_public_event_inventory_command, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
