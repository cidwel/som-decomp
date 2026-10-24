#include "som_c.h"

/* C2924B enter_native7f_phase_one_from_initial_phase_eight   [class B, 93 bytes, 33 instructions]
 * Source: src/rom/enter_native7f_phase_one_from_initial_phase_eight.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void enter_native7f_phase_one_from_initial_phase_eight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 < 0x3C) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y;
        zero1 = value2 == 0x3C;
        negative1 = (uint16_t)(value2 - 0x3C) & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x002B + value, 0x0108);
        RAM16_SET(0x0032 + value, 0x0160);
        RAM16_SET(0x00B2 + value, 0);
        RAM16_SET(0x00B6 + value, 0);
        r->a = 0x0114;
        r->x = value;
        r->c = value2 >= 0x3C;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x926C, 0xC21394); GUARD_JSR(c, sp_call, 0x926C); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x00B0 + value, 0);
        RAM16_SET(OBJECT_PHASE + value, 1);
        RAM16_SET(0x003A + value, 0x3000);
        RAM16_SET(0x003C + value, 0);
        RAM16_SET(0x003E + value, 0x8000);
        RAM16_SET(0x0040 + value, 0);
        RAM16_SET(0x0090 + value, 0x8FED);
        RAM16_SET(0x02D5, 0x30);
        RAM16_SET(0x02D7, 0x18);
        r->a = 0x18;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x929C, 0xC291F3); GUARD_JSR(c, sp_call, 0x929C); } /* create_four_native7f_palette_transition_objects */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x929F, 0xC2979F); GUARD_JSR(c, sp_call, 0x929F); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
        r->a = 0xD6;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92A5, 0xC230E3); GUARD_JSR(c, sp_call, 0x92A5); } /* request_boss_sound_with_parameter_word */
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret2 = r->y;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret3 = r->v;
        m_flag = m_ret;
        x_flag = x_ret4;
        a1 = (uint8_t)a_all4;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret5;
        y1 = y_ret2;
        zero1 = zero_ret4;
        negative1 = negative_ret4;
        overflow1 = overflow_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2924B, SOM_RTS, "gen", enter_native7f_phase_one_from_initial_phase_eight, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 93, 33)
