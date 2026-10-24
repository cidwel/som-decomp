#include "som_c.h"

/* C05990 enqueue_physical_critical_hit_notice   [class B, 13 bytes, 5 instructions]
 * Source: src/rom/enqueue_physical_critical_hit_notice.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void enqueue_physical_critical_hit_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x5992, 0xC05D08); /* allocate_reverse_combat_message_slot */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5995, 0xC05C06); /* append_actor_name_message_token */
    r->x = 0x62B7;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x599B, 0xC05C2A); /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05990, SOM_RTL, "gen", enqueue_physical_critical_hit_notice, 0, 0, 1, 1, 0, 13, 5)
