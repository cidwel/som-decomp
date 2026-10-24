#include "som_c.h"

/* C05BB6 enqueue_wall_expiration_notice   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/enqueue_wall_expiration_notice.s
 * Documented in docs/actor-cast-spell-remaining.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void enqueue_wall_expiration_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BB8, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5BB8); } /* allocate_message_queue_line */
    r->x = 0x6310;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BBE, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5BBE); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05BB6, SOM_RTL, "gen", enqueue_wall_expiration_notice, 0, 0, 1, 1, 0, 10, 4)
