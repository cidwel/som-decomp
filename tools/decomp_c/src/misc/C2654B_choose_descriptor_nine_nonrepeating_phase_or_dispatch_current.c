#include "som_c.h"

/* C2654B choose_descriptor_nine_nonrepeating_phase_or_dispatch_current   [class C, 62 bytes, 27 instructions]
 * Source: src/rom/choose_descriptor_nine_nonrepeating_phase_or_dispatch_current.s
 * Documented in docs/boss-descriptor-nine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_nine_nonrepeating_phase_or_dispatch_current(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x654D, 0xC23A41); GUARD_JSR(c, sp_call, 0x654D); } /* select_nearest_living_target_and_eight_way_direction */
    r->a = 2;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6553, 0xC2300B); GUARD_JSR(c, sp_call, 0x6553); } /* draw_boss_frame_random_number */
    bool zero_ret2 = r->z;
    if (!zero_ret2) {
        uint16_t value2 = RAM16(0x007E + RAM16(0x0287));
        r->a = (value2 & 0xFF) << 1;
        r->x = (value2 & 0xFF) << 1;
        r->c = value2 & 0xFF & 0x8000;
        r->z = (value2 & 0xFF) << 1 == 0;
        r->n = (value2 & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((value2 & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC26593, SOM_RTS); /* choose_descriptor_nine_phase_zero_action */
        case 0x0002: TAIL_CALL_DYN(c, 0xC265A1, SOM_RTS); /* choose_descriptor_nine_phase_one_action */
        case 0x0004: TAIL_CALL_DYN(c, 0xC265AF, SOM_RTS); /* choose_descriptor_nine_phase_two_action */
        case 0x0006: TAIL_CALL_DYN(c, 0xC265BD, SOM_RTS); /* choose_descriptor_nine_phase_three_action */
        case 0x0008: TAIL_CALL_DYN(c, 0xC265CB, SOM_RTS); /* choose_descriptor_nine_phase_four_action */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6589 + ((value2 & 0xFF) << 1))), SOM_RTS);
        }
    }
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x007E + value3);
    if ((value4 & 0x8000) == 0) {
        r->a = (value4 & 0xFF) << 1;
        r->x = (value4 & 0xFF) << 1;
        r->c = value4 & 0xFF & 0x8000;
        r->z = (value4 & 0xFF) << 1 == 0;
        r->n = (value4 & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((value4 & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC26593, SOM_RTS); /* choose_descriptor_nine_phase_zero_action */
        case 0x0002: TAIL_CALL_DYN(c, 0xC265A1, SOM_RTS); /* choose_descriptor_nine_phase_one_action */
        case 0x0004: TAIL_CALL_DYN(c, 0xC265AF, SOM_RTS); /* choose_descriptor_nine_phase_two_action */
        case 0x0006: TAIL_CALL_DYN(c, 0xC265BD, SOM_RTS); /* choose_descriptor_nine_phase_three_action */
        case 0x0008: TAIL_CALL_DYN(c, 0xC265CB, SOM_RTS); /* choose_descriptor_nine_phase_four_action */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6589 + ((value4 & 0xFF) << 1))), SOM_RTS);
        }
    }
    RAM16_SET(0x0200, value4 & 0xFF);
    r->a = 4;
    r->x = value3;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x656D, 0xC2300B); GUARD_JSR(c, sp_call, 0x656D); } /* draw_boss_frame_random_number */
    uint16_t a_all3 = r->a;
    uint16_t value5 = RAM16(0x0287);
    if (a_all3 == RAM16(0x0200)) {
        uint16_t value7 = RAM16(0x007E + value5);
        r->a = (value7 & 0xFF) << 1;
        r->x = (value7 & 0xFF) << 1;
        r->c = value7 & 0xFF & 0x8000;
        r->z = (value7 & 0xFF) << 1 == 0;
        r->n = (value7 & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((value7 & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC26593, SOM_RTS); /* choose_descriptor_nine_phase_zero_action */
        case 0x0002: TAIL_CALL_DYN(c, 0xC265A1, SOM_RTS); /* choose_descriptor_nine_phase_one_action */
        case 0x0004: TAIL_CALL_DYN(c, 0xC265AF, SOM_RTS); /* choose_descriptor_nine_phase_two_action */
        case 0x0006: TAIL_CALL_DYN(c, 0xC265BD, SOM_RTS); /* choose_descriptor_nine_phase_three_action */
        case 0x0008: TAIL_CALL_DYN(c, 0xC265CB, SOM_RTS); /* choose_descriptor_nine_phase_four_action */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6589 + ((value7 & 0xFF) << 1))), SOM_RTS);
        }
    }
    uint16_t value8 = BUS16(c, 0xDCE324 + (uint16_t)(a_all3 << 1));
    r->a = value8;
    r->x = (uint16_t)(a_all3 << 1);
    r->c = 0;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2654B, SOM_RTS, "gen", choose_descriptor_nine_nonrepeating_phase_or_dispatch_current, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 62, 27)
