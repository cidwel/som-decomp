#include "som_c.h"

/* C2542E dispatch_descriptor_twelve_variant_action   [class C, 11 bytes, 5 instructions]
 * Source: src/rom/dispatch_descriptor_twelve_variant_action.s
 * Documented in docs/boss-descriptor-twelve.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_twelve_variant_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5430, 0xC23A52); GUARD_JSR(c, sp_call, 0x5430); } /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x0042 + x_ret);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC2543D, SOM_RTS); /* choose_descriptor_twelve_variant_zero_phase_control_action */
    case 0x0002: TAIL_CALL_DYN(c, 0xC254C7, SOM_RTS); /* choose_descriptor_twelve_variant_one_hp_event_or_phase_action */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x5439 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2542E, SOM_RTS, "gen", dispatch_descriptor_twelve_variant_action, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 11, 5)
