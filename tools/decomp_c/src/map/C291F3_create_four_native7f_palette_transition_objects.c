#include "som_c.h"

/* C291F3 create_four_native7f_palette_transition_objects   [class B, 49 bytes, 17 instructions]
 * Source: src/rom/create_four_native7f_palette_transition_objects.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void create_four_native7f_palette_transition_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->a = 0xBB;
    r->x = 0x66;
    r->y = 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91FE, 0xC2272D); GUARD_JSR(c, sp_call, 0x91FE); } /* allocate_boss_palette_transition_object */
    r->a = 0xBB;
    r->x = 0x66;
    r->y = 5;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x920A, 0xC2272D); GUARD_JSR(c, sp_call, 0x920A); } /* allocate_boss_palette_transition_object */
    r->a = 0xBB;
    r->x = 0x66;
    r->y = 6;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9216, 0xC2272D); GUARD_JSR(c, sp_call, 0x9216); } /* allocate_boss_palette_transition_object */
    r->a = 0xBB;
    r->x = 0x66;
    r->y = 7;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9222, 0xC2272D); GUARD_JSR(c, sp_call, 0x9222); } /* allocate_boss_palette_transition_object */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC291F3, SOM_RTS, "gen", create_four_native7f_palette_transition_objects, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 49, 17)
