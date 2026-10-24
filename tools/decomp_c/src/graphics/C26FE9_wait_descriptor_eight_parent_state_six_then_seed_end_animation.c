#include "som_c.h"

/* C26FE9 wait_descriptor_eight_parent_state_six_then_seed_end_animation   [class A, 24 bytes, 10 instructions]
 * Source: src/rom/wait_descriptor_eight_parent_state_six_then_seed_end_animation.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void wait_descriptor_eight_parent_state_six_then_seed_end_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(OBJECT_PHASE + value2);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value3 < 6) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        zero1 = value3 == 6;
        negative1 = (uint16_t)(value3 - 6) & 0x8000;
    } else {
        r->a = 0x0133;
        r->x = value;
        r->y = value2;
        r->c = value3 >= 6;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6FFB, 0xC21394); GUARD_JSR(c, sp_call, 0x6FFB); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = RAM16(OBJECT_PHASE + value) == 0;
        negative1 = RAM16(OBJECT_PHASE + value) & 0x8000;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->y = value2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26FE9, SOM_RTS, "gen", wait_descriptor_eight_parent_state_six_then_seed_end_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 10)
