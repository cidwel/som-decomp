#include "som_c.h"

/* C20396 notify_control40_bosses_with_animation57_through7F   [class B, 59 bytes, 34 instructions]
 * Source: src/rom/notify_control40_bosses_with_animation57_through7F.s
 * Documented in docs/boss-public-party-services.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void notify_control40_bosses_with_animation57_through7F(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t a_hi1 = 2;
    uint16_t x1 = x;
    uint16_t y1 = 3;
    for (;;) {
        if (RAM8(0xE060 + (uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1)) == 0x40) {
            uint8_t value2 = RAM8(0xE180 + (uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1));
            if (value2 >= 0x57) {
                if (value2 < 0x80) {
                    RAM8(0xE061 + (uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1)) = 1;
                }
            }
        }
        uint8_t a_hi1_next = (uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) >> 8;
        uint16_t x1_next = (uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1);
        uint16_t y1_next = (uint16_t)(y1 + 1);
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 < 6)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC20396, SOM_RTL, "gen", notify_control40_bosses_with_animation57_through7F, 0, L_B | L_X | L_Y | L_V, 5, 1, 0, 59, 34)
