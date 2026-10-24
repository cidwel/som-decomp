#include "som_c.h"

/* C29539 consume_native7f_request_then_install_lateral_linear_motion   [class B, 103 bytes, 37 instructions]
 * Source: src/rom/consume_native7f_request_then_install_lateral_linear_motion.s
 * Documented in docs/boss-native7f-frame-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void consume_native7f_request_then_install_lateral_linear_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0364);
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if (value == 0) {
        a_hi1 = value >> 8;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = 0x20;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9543, 0xC224C3); GUARD_JSR(c, sp_call, 0x9543); } /* prepare_boss_loader_resource_expansion */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        RAM16_SET(0x0364, 0);
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(OBJECT_AGE + value2);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y2;
    bool zero1;
    bool negative1;
    bool overflow2;
    if (value3 < 9) {
        r->x = value2;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x959D, 0xC295A0); GUARD_JSR(c, sp_call, 0x959D); } /* publish_native7f_single_mode7_frame_dma_request */
        uint16_t a_all2 = r->a;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        x1 = value2;
        y2 = y1;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow2 = overflow_ret2;
    } else {
        RAM16_SET(OBJECT_AGE + value2, 0);
        RAM16_SET(0x0090 + value2, 0x9224);
        RAM16_SET(0x00B0 + value2, 0x80);
        r->a = 0x0115;
        r->x = value2;
        r->y = y1;
        r->c = value3 >= 9;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9565, 0xC21394); GUARD_JSR(c, sp_call, 0x9565); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x00B6 + value2, 0);
        RAM16_SET(0x00B4 + value2, 0);
        RAM16_SET(OBJECT_PHASE + value2, 7);
        RAM16_SET(0x002B + value2, 0x0228);
        RAM16_SET(0x003C + value2, 0xFFF8);
        RAM16_SET(0x003A + value2, 0);
        RAM16_SET(0x0040 + value2, 0);
        RAM16_SET(0x003E + value2, 0);
        RAM16_SET(0x02D5, 0x38);
        RAM16_SET(0x02D7, 0x20);
        r->a = 0xD6;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9598, 0xC230E3); GUARD_JSR(c, sp_call, 0x9598); } /* request_boss_sound_with_parameter_word */
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret2 = r->y;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret3 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a1 = (uint8_t)a_all4;
        a_hi2 = a_all4 >> 8;
        x1 = x_ret3;
        y2 = y_ret2;
        zero1 = zero_ret4;
        negative1 = negative_ret4;
        overflow2 = overflow_ret3;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x1;
    r->y = y2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29539, SOM_RTS, "gen", consume_native7f_request_then_install_lateral_linear_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 103, 37)
