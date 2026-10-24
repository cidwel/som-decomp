#include "som_c.h"

/* C21A91 prepare_boss_animation_regular_graphics_cache   [class B, 57 bytes, 30 instructions]
 * Source: src/rom/prepare_boss_animation_regular_graphics_cache.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void prepare_boss_animation_regular_graphics_cache(SomCtx *c)
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
    uint16_t value = RAM16(0x00A0 + x);
    RAM16_SET(0x026E, value);
    RAM8(0x0270) = RAM8(0x00A2 + x);
    uint8_t value3;
    BUS8_PTR(c, (RAM8(0x0270) << 0x10) + RAM16(0x026E), RAM8(0x0270), value3);
    uint16_t a_final;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi3;
    uint16_t y3;
    bool overflow3;
    if (value3 == 0) {
        m_flag = 1;
        x_flag = 0;
        a_final = (uint16_t)((value & 0xFF00) | value3);
        a_hi3 = value >> 8;
        y3 = y;
        overflow3 = overflow;
    } else {
        RAM8(0x0266) = value3;
        RAM16_SET(0x026E, (uint16_t)(RAM16(0x026E) + 1));
        uint8_t a_hi1 = value >> 8;
        uint8_t x1 = 0;
        uint8_t y1 = 3;
        bool carry1 = carry;
        bool overflow1 = overflow;
        for (;;) {
            uint16_t value4;
            BUS16_PTR(c, (RAM8(0x0270) << 0x10) + RAM16(0x026E) + y1, RAM8(0x0270), value4);
            r->a = value4 & 0x01FF;
            r->z = (value4 & 0x01FF) == 0;   /* AND #$01FF */
            r->n = 0;
            r->y = y1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = 0x0200;
            RAM8(r->sp) = x1;   /* PHX */
            r->sp -= 1;
            JSR(c, 0x1AB5, 0xC21B03); /* ensure_regular_boss_animation_graphic_cached */
            r->sp += 1;
            x1 = RAM8(r->sp);   /* PLX */
            uint16_t a_all = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t a_hi2;
            uint8_t y2;
            bool overflow2;
            if (carry_ret) {
                a_final = a_all;
                a_hi2 = a_all >> 8;
                y2 = y1;
                overflow2 = overflow_ret;
            } else {
                uint8_t value5 = RAM8(0x0266);
                if ((uint8_t)(x1 + 1) != value5) {
                    uint8_t a_hi1_next = y1 + 4 >> 8;
                    uint8_t x1_next = (uint8_t)(x1 + 1);
                    uint8_t y1_next = (uint8_t)(y1 + 4);
                    bool carry1_next = (uint8_t)(x1 + 1) >= value5;
                    bool overflow1_next = ((y1 ^ y1 + 4) & (y1 + 4 ^ 4) & 0x8000) != 0;
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                a_final = (uint16_t)(y1 + 4);
                a_hi2 = y1 + 4 >> 8;
                y2 = (uint8_t)(y1 + 4);
                overflow2 = ((y1 ^ y1 + 4) & (y1 + 4 ^ 4) & 0x8000) != 0;
            }
            a_hi1 = a_hi2;
            y1 = y2;
            overflow1 = overflow2;
            break;
        }
        m_flag = 0;
        x_flag = 1;
        a_hi3 = a_hi1;
        y3 = y1;
        overflow3 = overflow1;
    }
    uint16_t value6 = RAM16(0x0287);
    (void)a_hi3;
    r->a = a_final;
    r->x = value6;
    r->z = value6 == 0;   /* LDX $87 */
    r->n = (value6 & 0x8000) != 0;
    r->y = y3;
    r->v = overflow3;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21A91, SOM_RTS, "hand", prepare_boss_animation_regular_graphics_cache, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 57, 30)
