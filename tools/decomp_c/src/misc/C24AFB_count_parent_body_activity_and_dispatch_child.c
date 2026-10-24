#include "som_c.h"

/* C24AFB count_parent_body_activity_and_dispatch_child   [class C, 24 bytes, 12 instructions]
 * Source: src/rom/count_parent_body_activity_and_dispatch_child.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void count_parent_body_activity_and_dispatch_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x00BA + value, (uint16_t)(RAM16(0x00BA + value) + 1));
    uint16_t value2 = RAM16(0x0289);
    uint16_t value4 = RAM16(OBJECT_PHASE + RAM16(0x0287));
    r->a = (uint16_t)(value4 << 1);
    r->x = (uint16_t)(value4 << 1);
    r->y = (uint16_t)(value2 - 0xF800);
    r->c = value4 & 0x8000;
    r->z = (uint16_t)(value4 << 1) == 0;
    r->n = (uint16_t)(value4 << 1) & 0x8000;
    r->v = ((value2 ^ 0xF800) & (value2 ^ (uint16_t)(value2 - 0xF800)) & 0x8000) != 0;
    switch ((uint16_t)(value4 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC24B27, SOM_RTS); /* initialize_native54_body_identity67_attack1e */
    case 0x0002: TAIL_CALL_DYN(c, 0xC24B7F, SOM_RTS); /* begin_body_segment_growth_after_animation */
    case 0x0004: TAIL_CALL_DYN(c, 0xC24BC5, SOM_RTS); /* reset_body_motion_after_retraction_animation */
    case 0x0006: TAIL_CALL_DYN(c, 0xC24BF0, SOM_RTS); /* begin_body_appearance_after_thirty_six_ticks */
    case 0x0008: TAIL_CALL_DYN(c, 0xC24C0D, SOM_RTS); /* grow_body_segment_chain_at_four_tick_intervals */
    case 0x000A: TAIL_CALL_DYN(c, 0xC24C43, SOM_RTS); /* enter_body_retraction_after_six_ticks */
    case 0x000C: TAIL_CALL_DYN(c, 0xC24C74, SOM_RTS); /* retract_body_segments_and_choose_next_phase */
    case 0x000E: TAIL_CALL_DYN(c, 0xC24CEF, SOM_RTS); /* finish_body_hurt_or_enter_terminal_phase */
    case 0x0010: TAIL_CALL_DYN(c, 0xC24D20, SOM_RTS); /* recover_body_target_after_thirty_two_ticks */
    case 0x0012: TAIL_CALL_DYN(c, 0xC24D4C, SOM_RTS); /* update_body_terminal_tiles_or_deactivate_after_seven_ticks */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x4B13 + ((uint16_t)(value4 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC24AFB, SOM_RTS, "gen", count_parent_body_activity_and_dispatch_child, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 12)
