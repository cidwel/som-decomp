#include "som_c.h"

/* C213AD tick_boss_animation_and_prepare_frame_graphics   [class B, 62 bytes, 27 instructions]
 * Source: src/rom/tick_boss_animation_and_prepare_frame_graphics.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void tick_boss_animation_and_prepare_frame_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0098 + x);
    if (!(value & 0x8000)) {
        RAM8(0x0278) = 0xC1;
        uint8_t value2 = RAM8(0x009E + x);
        bool m_flag2;
        uint16_t y2;
        bool overflow2;
        if (value2 == 0) {
            m_flag2 = 1;
            y2 = y;
            overflow2 = overflow;
        } else {
            RAM8(0x009E + x)--;
            bool m_flag;
            uint16_t y1;
            bool overflow1;
            if (RAM8(0x009E + x) != 0) {
                m_flag = 1;
                y1 = y;
                overflow1 = overflow;
            } else {
                r->mf = 1;
                JSR(c, 0x13E2, 0xC213EB); /* interpret_boss_animation_commands_until_frame_record */
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x13E7, 0xC21C37); /* prepare_boss_animation_frame_geometry_and_collision */
                uint16_t y_ret2 = r->y;
                bool overflow_ret2 = r->v;
                m_flag = 0;
                y1 = y_ret2;
                overflow1 = overflow_ret2;
            }
            m_flag2 = m_flag;
            y2 = y1;
            overflow2 = overflow1;
        }
        r->y = y2;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    RAM8(0x0278) = 0xC1;
    uint8_t value4 = RAM8(0x009E + x);
    bool m_flag4;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y4;
    bool carry2;
    bool overflow4;
    if (value4 == 0) {
        m_flag4 = 1;
        a_hi2 = value >> 8;
        x2 = x;
        y4 = y;
        carry2 = carry;
        overflow4 = overflow;
    } else {
        RAM8(0x009E + x)--;
        bool m_flag3;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y3;
        bool carry1;
        bool overflow3;
        if (RAM8(0x009E + x) != 0) {
            m_flag3 = 1;
            a_hi1 = value >> 8;
            x1 = x;
            y3 = y;
            carry1 = carry;
            overflow3 = overflow;
        } else {
            r->mf = 1;
            JSR(c, 0x13C4, 0xC213EB); /* interpret_boss_animation_commands_until_frame_record */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            m_flag3 = 0;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret3;
            y3 = y_ret3;
            carry1 = carry_ret3;
            overflow3 = overflow_ret3;
        }
        m_flag4 = m_flag3;
        a_hi2 = a_hi1;
        x2 = x1;
        y4 = y3;
        carry2 = carry1;
        overflow4 = overflow3;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->x = x2;
    r->y = y4;
    r->c = carry2;
    r->v = overflow4;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    JSR(c, 0x13C9, 0xC21A81); /* prepare_boss_animation_graphics_cache_by_mode */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x13CC, 0xC21C37); /* prepare_boss_animation_frame_geometry_and_collision */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC213AD, SOM_RTS, "gen", tick_boss_animation_and_prepare_frame_graphics, 0, L_Y | L_V, 1, 0, 0, 62, 27)
