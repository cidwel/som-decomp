#include "som_c.h"

/* C2AEF4 copy_actor_velocity_presets_to_wram   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/copy_actor_velocity_presets_to_wram.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void copy_actor_velocity_presets_to_wram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->a = 0x6F;
    r->x = 0xAF05;
    r->y = 0xC700;
    r->mf = 0;
    r->xf = 0;
    i_mvn(c, 0x02, 0x7E); /* copy up bank $02 to bank $7E */
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AEF4, SOM_RTL, "gen", copy_actor_velocity_presets_to_wram, 0, L_Y | L_C | L_V, 1, 1, 1, 17, 8)
