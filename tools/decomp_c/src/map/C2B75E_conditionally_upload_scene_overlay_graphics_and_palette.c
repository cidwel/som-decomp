#include "som_c.h"

/* C2B75E conditionally_upload_scene_overlay_graphics_and_palette   [class D, 70 bytes, 29 instructions]
 * Source: src/rom/conditionally_upload_scene_overlay_graphics_and_palette.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void conditionally_upload_scene_overlay_graphics_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x008C);
    bool m_flag2;
    uint8_t a_hi4;
    if (value == 0) {
        BUS8_SET(c, 0x002115, 0x80);
        BUS16_SET(c, 0x002116, 0x7800);
        BUS16_SET(c, 0x004370, 0x1801);
        BUS16_SET(c, 0x004372, 0xB8D6);
        BUS8_SET(c, 0x004374, 0xC2);
        BUS16_SET(c, 0x004375, 0x0200);
        BUS8_SET(c, 0x00420B, 0x80);
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0x1E;
        for (;;) {
            uint16_t value2 = BUS16(c, 0x02B7BC + x1);
            BUS16_SET(c, 0x0007E2 + x1, value2);
            a_hi1 = value2 >> 8;
            x1 = (uint16_t)(x1 - 2);
            if (!(!(x1 & 0x8000))) break;
        }
        m_flag2 = 0;
        a_hi4 = a_hi1;
    } else {
        uint8_t value3 = RAM8(0x00E3);
        bool m_flag;
        uint8_t a_hi3;
        if ((value3 & 6) == 0) {
            m_flag = 1;
            a_hi3 = a_hi;
        } else {
            BUS8_SET(c, 0x002115, 0x80);
            BUS16_SET(c, 0x002116, 0x7800);
            BUS16_SET(c, 0x004370, 0x1801);
            BUS16_SET(c, 0x004372, 0xB8D6);
            BUS8_SET(c, 0x004374, 0xC2);
            BUS16_SET(c, 0x004375, 0x0200);
            BUS8_SET(c, 0x00420B, 0x80);
            uint8_t a_hi2 = a_hi;
            uint16_t x2 = 0x1E;
            for (;;) {
                uint16_t value4 = BUS16(c, 0x02B7BC + x2);
                BUS16_SET(c, 0x0007E2 + x2, value4);
                a_hi2 = value4 >> 8;
                x2 = (uint16_t)(x2 - 2);
                if (!(!(x2 & 0x8000))) break;
            }
            m_flag = 0;
            a_hi3 = a_hi2;
        }
        m_flag2 = m_flag;
        a_hi4 = a_hi3;
    }
    r->a = (a_hi4 << 8) | a;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    r->mf = m_flag2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B75E, SOM_RTL, "gen", conditionally_upload_scene_overlay_graphics_and_palette, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 70, 29)
