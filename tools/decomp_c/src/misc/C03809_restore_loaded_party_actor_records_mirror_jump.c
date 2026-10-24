#include "som_c.h"

/* C03809 restore_loaded_party_actor_records_mirror_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/restore_loaded_party_actor_records_mirror_jump.s
 * Documented in docs/ui-native-loaded-game-save-apply.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BV.
 */
static void restore_loaded_party_actor_records_mirror_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC04C28, SOM_RTL); /* restore_loaded_party_actor_runtime_and_rebuild_attributes */
}
SOM_REGISTER(0xC03809, SOM_RTL, "gen", restore_loaded_party_actor_records_mirror_jump, 0, L_B | L_V, 1, 1, 0, 3, 1)
