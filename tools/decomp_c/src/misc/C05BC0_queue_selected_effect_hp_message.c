#include "som_c.h"

/* C05BC0 queue_selected_effect_hp_message   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/queue_selected_effect_hp_message.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void queue_selected_effect_hp_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BC2, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5BC2); } /* allocate_message_queue_line */
    r->x = 0x6303;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BC8, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5BC8); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05BC0, SOM_RTL, "gen", queue_selected_effect_hp_message, 0, 0, 1, 1, 0, 10, 4)
