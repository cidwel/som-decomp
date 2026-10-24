#include "som_c.h"

/* C0385A jump_internal_controlled_party_world_snapshot   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_internal_controlled_party_world_snapshot.s
 * Documented in docs/event-party-world-snapshot.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: nothing.
 */
static void jump_internal_controlled_party_world_snapshot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03E35, SOM_RTL); /* record_controller_selected_actor_position_guard */
}
SOM_REGISTER(0xC0385A, SOM_RTL, "gen", jump_internal_controlled_party_world_snapshot, 0, 0, 1, 0, 0, 3, 1)
