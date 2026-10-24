#include "som_c.h"

/* C10030 initialize_scrolling_dialogue_sprite_workspace_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_scrolling_dialogue_sprite_workspace_long.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: B.
 */
static void initialize_scrolling_dialogue_sprite_workspace_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0032, 0xC1481F); GUARD_JSR(c, sp_call, 0x0032); } /* initialize_scrolling_dialogue_sprite_workspace */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10030, SOM_RTL, "gen", initialize_scrolling_dialogue_sprite_workspace_long, 0, L_B, 1, 1, 0, 4, 2)
