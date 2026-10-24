#include "som_c.h"

/* C00066 jump_public_chest_reward_command   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_chest_reward_command.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: nothing.
 */
static void jump_public_chest_reward_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0384E, SOM_RTL); /* jump_native_chest_reward_command */
}
SOM_REGISTER(0xC00066, SOM_RTL, "gen", jump_public_chest_reward_command, 0, 0, 1, 0, 0, 3, 1)
