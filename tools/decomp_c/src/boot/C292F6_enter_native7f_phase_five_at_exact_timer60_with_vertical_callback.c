#include "som_c.h"

/* C292F6 enter_native7f_phase_five_at_exact_timer60_with_vertical_callback   [class B, 139 bytes, 49 instructions]
 * Source: src/rom/enter_native7f_phase_five_at_exact_timer60_with_vertical_callback.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void enter_native7f_phase_five_at_exact_timer60_with_vertical_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    uint16_t value = RAM16(OBJECT_AGE + current_object_dp0);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value != 0x3C) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = current_object_dp0;
        y1 = y;
        carry1 = value >= 0x3C;
        zero1 = value == 0x3C;
        negative1 = (uint16_t)(value - 0x3C) & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(OBJECT_AGE + current_object_dp0, 0);
        RAM16_SET(OBJECT_PHASE + current_object_dp0, 5);
        RAM16_SET(0x0000 + current_object_dp0, 1);
        RAM16_SET(OBJECT_AGE + current_object_dp0, 0);
        RAM16_SET(0x00B0 + current_object_dp0, 0x0800);
        RAM16_SET(0x00B2 + current_object_dp0, 0);
        r->a = 0x0113;
        r->x = current_object_dp0;
        r->c = value >= 0x3C;
        JSR(c, 0x9320, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x003A + current_object_dp0, 0);
        RAM16_SET(0x003C + current_object_dp0, 0);
        RAM16_SET(0x003E + current_object_dp0, 0xC000);
        RAM16_SET(0x0040 + current_object_dp0, 0);
        RAM16_SET(0x0090 + current_object_dp0, 0x9158);
        RAM16_SET(0x02D5, 0x30);
        RAM16_SET(0x02D7, 0x20);
        r->a = 0x5D;
        r->x = 0x62;
        r->y = 4;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x934D, 0xC2272D); /* allocate_boss_palette_transition_object */
        r->a = 0x5D;
        r->x = 0x63;
        r->y = 5;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x9359, 0xC2272D); /* allocate_boss_palette_transition_object */
        r->a = 0x5D;
        r->x = 0x64;
        r->y = 6;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x9365, 0xC2272D); /* allocate_boss_palette_transition_object */
        r->a = 0x5D;
        r->x = 0x65;
        r->y = 7;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x9371, 0xC2272D); /* allocate_boss_palette_transition_object */
        uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
        r->a = 0xD6;
        r->x = current_object_dp02;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x9379, 0xC230E3); /* request_boss_sound_with_parameter_word */
        uint16_t a_all6 = r->a;
        uint16_t y_ret5 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        uint16_t current_object_dp03 = RAM16(CURRENT_OBJECT_DP0 + dp);
        a1 = (uint8_t)a_all6;
        a_hi1 = a_all6 >> 8;
        x1 = current_object_dp03;
        y1 = y_ret5;
        carry1 = carry_ret5;
        zero1 = current_object_dp03 == 0;
        negative1 = current_object_dp03 & 0x8000;
        overflow1 = overflow_ret5;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = false;
    r->xf = false;
    JSR(c, 0x937E, 0xC2979F); /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = false;
    r->mf = false;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC292F6, SOM_RTS, "hand", enter_native7f_phase_five_at_exact_timer60_with_vertical_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 139, 49)
