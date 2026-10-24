#include "som_c.h"

/* C04F4F select_actor_recovery_impact_motion   [class B, 31 bytes, 14 instructions]
 * Source: src/rom/select_actor_recovery_impact_motion.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_actor_recovery_impact_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    if ((value & 0xC578) != 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    if ((RAM8(ACTOR_KIND_FLAGS + x) & 0x81) != 0) {
        r->a = (value >> 8 << 8) | 0x2B;
        JSR(c, 0x4F6C, 0xC04F6E); /* store_actor_impact_motion_when_counter_idle */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (value >> 8 << 8) | 0x12;
    JSR(c, 0x4F66, 0xC04F6E); /* store_actor_impact_motion_when_counter_idle */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04F4F, SOM_RTS, "gen", select_actor_recovery_impact_motion, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 31, 14)
