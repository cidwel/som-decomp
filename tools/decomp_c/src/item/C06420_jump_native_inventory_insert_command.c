#include "som_c.h"

/* C06420 jump_native_inventory_insert_command   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_native_inventory_insert_command.s
 * Documented in docs/event-vm-inventory-command.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void jump_native_inventory_insert_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC064BD, SOM_RTL); /* insert_inventory_record_with_zero_controller_bits */
}
SOM_REGISTER(0xC06420, SOM_RTL, "gen", jump_native_inventory_insert_command, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
