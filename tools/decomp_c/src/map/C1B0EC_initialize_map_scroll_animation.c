#include "som_c.h"

/* C1B0EC initialize_map_scroll_animation   [class B, 91 bytes, 44 instructions]
 * Source: src/rom/initialize_map_scroll_animation.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BX.
 */
static void initialize_map_scroll_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x001C);
    if (value & 0x80) {
        RAM8(0x0090) = 0x40;
        uint8_t value2 = BUS8(c, 0xC80401 + (uint8_t)(a >> 8 << 8 | (value & 0x3F)));
        uint8_t value3 = BUS8(c, 0xC80400 + (uint8_t)(a >> 8 << 8 | (value & 0x3F)));
        uint8_t a1;
        if ((uint8_t)((uint8_t)(value2 - value3) << 1) != 0) {
            a1 = (uint8_t)((uint8_t)(value2 - value3) << 1);
        } else {
            a1 = 2;
        }
        RAM8(0x0001) = a1;
        RAM8(0x0000) = 0;
        uint8_t value4 = BUS8(c, 0xC80400 + (uint8_t)(a >> 8 << 8 | (value & 0x3F)));
        RAM8(0x18013) = 0;
        RAM8(0x1801B) = 0;
        RAM8(0x18023) = 0;
        RAM8(0x1802B) = 0;
        RAM8(0x18033) = 0;
        RAM8(0x1803B) = 0;
        uint8_t a_hi1 = (((a >> 8 << 8) | value4) & 0xFF) << 1 >> 8;
        uint16_t x1 = (((a >> 8 << 8) | value4) & 0xFF) << 1;
        uint16_t y1 = 0;
        do {
            uint8_t value5 = BUS8(c, 0xC80441 + x1);
            r->a = (a_hi1 << 8) | value5;
            r->x = x1;
            r->y = y1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = 0;
            r->sp -= 1;
            JSR(c, 0xB13D, 0xC1B147); /* append_map_scroll_animation_record */
            r->sp += 1;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            RAM8(0x0000)++;
            RAM8(0x0001)--;
            a_hi1 = a_all >> 8;
            x1 = (uint16_t)(x1 + 1);
            y1 = y_ret;
        } while (RAM8(0x0001) != 0);
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = x1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTL(c);
    }
    RAM8(0x0090) = 0;
    r->x = value;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1B0EC, SOM_RTL, "gen", initialize_map_scroll_animation, 0, L_B | L_X, 2, 0, 0, 91, 44)
