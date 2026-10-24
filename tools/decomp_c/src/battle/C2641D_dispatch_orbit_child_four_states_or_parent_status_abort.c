#include "som_c.h"

/* C2641D dispatch_orbit_child_four_states_or_parent_status_abort   [class C, 18 bytes, 9 instructions]
 * Source: src/rom/dispatch_orbit_child_four_states_or_parent_status_abort.s
 * Documented in docs/boss-descriptor-three-orbit.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_orbit_child_four_states_or_parent_status_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00BA + x);
    uint16_t value2 = RAM16(0x0190 + value);
    if (value2 & 0x8000) {
        r->a = value2;
        r->y = value;
        r->c = 1;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value3 << 1);
    r->x = (uint16_t)(value3 << 1);
    r->y = value;
    r->c = value3 & 0x8000;
    r->z = (uint16_t)(value3 << 1) == 0;
    r->n = (uint16_t)(value3 << 1) & 0x8000;
    switch ((uint16_t)(value3 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC26437, SOM_RTS); /* initialize_descriptor_three_orbit_child_activity_animation_and_radius */
    case 0x0002: TAIL_CALL_DYN(c, 0xC2644B, SOM_RTS); /* expand_orbit_radius_then_enter_hold_state */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2646C, SOM_RTS); /* hold_orbit_for_eighty_counter_ticks_then_contract */
    case 0x0006: TAIL_CALL_DYN(c, 0xC26483, SOM_RTS); /* contract_orbit_radius_or_terminate */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x642F + ((uint16_t)(value3 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2641D, SOM_RTS, "gen", dispatch_orbit_child_four_states_or_parent_status_abort, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 9)
