#include "som_c.h"

/* C753C8 append_native_confirmation_hero_level   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/append_native_confirmation_hero_level.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_confirmation_hero_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x9C00 + x) = 0xA6;
    r->a = (a_hi << 8) | 0xA6;
    r->x = (uint16_t)(x + 1);
    { const uint16_t sp_call = r->sp; JSR(c, 0x53D0, 0xC75386); GUARD_JSR(c, sp_call, 0x53D0); } /* append_two_native_saved_slot_text_space_tokens */
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        r->x = (uint8_t)((uint8_t)x_ret2 - 1);
        r->y = (uint8_t)y;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x53D4, 0xC75AF8); GUARD_JSR(c, sp_call, 0x53D4); } /* external */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        r->x = (uint16_t)(x_ret2 - 1);
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x53D4, 0xC75AF8); GUARD_JSR(c, sp_call, 0x53D4); } /* external */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC753C8, SOM_RTS, "gen", append_native_confirmation_hero_level, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 14, 7)
