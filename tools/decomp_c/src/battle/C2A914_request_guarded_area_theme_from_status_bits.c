#include "som_c.h"

/* C2A914 request_guarded_area_theme_from_status_bits   [class B, 47 bytes, 19 instructions]
 * Source: src/rom/request_guarded_area_theme_from_status_bits.s
 * Documented in docs/audio-native-callers.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYC.
 */
static void request_guarded_area_theme_from_status_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0x008C);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y3;
    bool carry1;
    if (value != 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        y3 = y;
        carry1 = carry;
    } else {
        uint8_t value2 = RAM8(0x00E3);
        uint16_t x2;
        uint16_t y2;
        if (value2 & 0x80) {
            x2 = 0x0201;
            y2 = 0xFF0D;
        } else {
            uint16_t x1;
            uint16_t y1;
            if (value2 & 0x40) {
                x1 = 0x0301;
                y1 = 0xFF0B;
            } else {
                x1 = 0x0101;
                y1 = 0xFF09;
            }
            x2 = x1;
            y2 = y1;
        }
        RAM16_SET(0x1E00, x2);
        RAM16_SET(0x1E02, y2);
        r->a = (a_hi << 8) | value;
        r->x = x2;
        r->y = y2;
        r->z = 0;
        r->n = 1;
        r->v = value2 & 0x40;
        { const uint16_t sp_call = r->sp; JSL(c, 0xA941, 0xC30004); GUARD_JSL(c, sp_call, 0xA941); } /* audio_command_sender_public_jump */
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        y3 = y_ret;
        carry1 = carry_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y3;
    r->c = carry1;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A914, SOM_RTL, "gen", request_guarded_area_theme_from_status_bits, 0, L_B | L_Y | L_C, 1, 1, 0, 47, 19)
