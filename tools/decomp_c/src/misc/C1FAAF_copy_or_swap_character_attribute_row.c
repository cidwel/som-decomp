#include "som_c.h"

/* C1FAAF copy_or_swap_character_attribute_row   [class B, 82 bytes, 37 instructions]
 * Source: src/rom/copy_or_swap_character_attribute_row.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void copy_or_swap_character_attribute_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00E3);
    if (value == 0x80) {
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0x3E;
        for (;;) {
            uint16_t value2 = RAM16(0xEBC0 + x1);
            RAM16_SET(0xEFC0 + x1, value2);
            a_hi1 = value2 >> 8;
            x1 = (uint16_t)(x1 - 2);
            if (!(!(x1 & 0x8000))) break;
        }
        r->y = y;
        r->c = value >= 0x80;
        r->v = overflow;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (value == 0x84) {
        uint8_t a_hi2 = a_hi;
        uint16_t x2 = 0x3E;
        for (;;) {
            uint16_t value3 = RAM16(0xEFC0 + x2);
            RAM16_SET(0xEFC0 + x2, RAM16(0xEBC0 + x2));
            RAM16_SET(0xEBC0 + x2, value3);
            a_hi2 = value3 >> 8;
            x2 = (uint16_t)(x2 - 2);
            if (!(!(x2 & 0x8000))) break;
        }
        r->y = y;
        r->c = value >= 0x84;
        r->v = overflow;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (value == 2) {
        uint8_t a_hi3 = a_hi;
        uint16_t x3 = 0x3E;
        for (;;) {
            uint16_t value5 = RAM16(0xEFC0 + x3);
            RAM16_SET(0xEBC0 + x3, value5);
            a_hi3 = value5 >> 8;
            x3 = (uint16_t)(x3 - 2);
            if (!(!(x3 & 0x8000))) break;
        }
        r->y = y;
        r->c = value >= 2;
        r->v = overflow;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    bool m_flag;
    bool x_flag;
    if (value != 0x40) {
        m_flag = 1;
        x_flag = 1;
    } else {
        uint8_t a_hi4 = a_hi;
        uint16_t x4 = 0x3E;
        for (;;) {
            uint16_t value6 = RAM16(0xEBC0 + x4);
            RAM16_SET(0xEFC0 + x4, value6);
            a_hi4 = value6 >> 8;
            x4 = (uint16_t)(x4 - 2);
            if (!(!(x4 & 0x8000))) break;
        }
        m_flag = 0;
        x_flag = 0;
    }
    r->y = y;
    r->c = value >= 0x40;
    r->v = overflow;
    r->mf = m_flag;
    r->xf = x_flag;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FAAF, SOM_RTS, "gen", copy_or_swap_character_attribute_row, 0, L_Y | L_C | L_V, 2, 1, 1, 82, 37)
