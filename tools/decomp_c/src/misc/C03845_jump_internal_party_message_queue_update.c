#include "som_c.h"

/* C03845 jump_internal_party_message_queue_update   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_internal_party_message_queue_update.s
 * Documented in docs/event-party-message-queue.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void jump_internal_party_message_queue_update(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC057C9, SOM_RTL); /* advance_native_party_message_queue_and_dialogue */
}
SOM_REGISTER(0xC03845, SOM_RTL, "gen", jump_internal_party_message_queue_update, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
