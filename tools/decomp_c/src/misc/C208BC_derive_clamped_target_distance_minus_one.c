#include "som_c.h"

/* C208BC derive_clamped_target_distance_minus_one   [class B, 29 bytes, 16 instructions]
 * Source: src/rom/derive_clamped_target_distance_minus_one.s
 * Documented in docs/boss-descriptor-three.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYV.
 */
static void derive_clamped_target_distance_minus_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x08BE, 0xC208E3); /* derive_low_byte_target_manhattan_distance */
    uint16_t a_all = r->a;
    RAM16_SET(0x0299, a_all);
    if ((uint16_t)((a_all >> 4) - 1) & 0x8000) {
        r->a = 0;
        r->v = (((a_all >> 4) ^ 1) & ((a_all >> 4) ^ (uint16_t)((a_all >> 4) - 1)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)((a_all >> 4) - 1) >= 4) {
        r->a = 4;
        r->v = (((a_all >> 4) ^ 1) & ((a_all >> 4) ^ (uint16_t)((a_all >> 4) - 1)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)((a_all >> 4) - 1);
    r->v = (((a_all >> 4) ^ 1) & ((a_all >> 4) ^ (uint16_t)((a_all >> 4) - 1)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC208BC, SOM_RTS, "gen", derive_clamped_target_distance_minus_one, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 29, 16)
