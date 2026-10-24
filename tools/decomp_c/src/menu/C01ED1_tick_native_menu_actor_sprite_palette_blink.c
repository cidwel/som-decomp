#include "som_c.h"

/* C01ED1 tick_native_menu_actor_sprite_palette_blink   [class B, 44 bytes, 22 instructions]
 * Source: src/rom/tick_native_menu_actor_sprite_palette_blink.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void tick_native_menu_actor_sprite_palette_blink(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA202);
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    if (value != 4) {
        a_hi3 = a_hi;
        x3 = x;
        y3 = y;
    } else {
        RAM8(0xA19F)--;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        if (RAM8(0xA19F) != 0) {
            a_hi2 = a_hi;
            x2 = x;
            y2 = y;
        } else {
            r->a = a_hi;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1EE2, 0xC01F18); GUARD_JSR(c, sp_call, 0x1EE2); } /* select_native_menu_actor_sprite_span */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            uint8_t a_hi1 = a_all >> 8;
            uint16_t x1 = x_ret;
            uint16_t y1 = y_ret;
            for (;;) {
                RAM8(0x9C03 + x1) ^= 0x30;
                x1 = (uint16_t)(x1 + 4);
                y1 = (uint16_t)(y1 - 1);
                if (!(y1 != 0)) break;
            }
            RAM8(0xA19F) = 0x0A;
            RAM8(0xA20A) |= 4;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
        }
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x3;
    r->y = y3;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01ED1, SOM_RTS, "gen", tick_native_menu_actor_sprite_palette_blink, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 44, 22)
