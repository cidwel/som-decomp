#include "som_c.h"

/* C058AF enqueue_generic_actor_status_notice   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/enqueue_generic_actor_status_notice.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void enqueue_generic_actor_status_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x58B1, 0xC05CCF); /* allocate_message_queue_line */
    r->x = 0x62E2;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x58B7, 0xC05C2A); /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC058AF, SOM_RTL, "gen", enqueue_generic_actor_status_notice, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 10, 4)
