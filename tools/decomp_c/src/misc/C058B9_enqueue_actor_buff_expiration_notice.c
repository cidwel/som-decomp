#include "som_c.h"

/* C058B9 enqueue_actor_buff_expiration_notice   [class B, 15 bytes, 7 instructions]
 * Source: src/rom/enqueue_actor_buff_expiration_notice.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void enqueue_actor_buff_expiration_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->sp -= 2;
    JSR(c, 0x58BC, 0xC05CCF); /* allocate_message_queue_line */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x58BF, 0xC05C06); /* append_actor_name_message_token */
    r->sp += 2;
    r->x = 0x62F3;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x58C5, 0xC05C2A); /* append_rom_message_text */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC058B9, SOM_RTL, "gen", enqueue_actor_buff_expiration_notice, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 15, 7)
