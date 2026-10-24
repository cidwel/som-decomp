#include "som_c.h"

/* C75464 append_native_save_confirmation_active_hero_count   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/append_native_save_confirmation_active_hero_count.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void append_native_save_confirmation_active_hero_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5469, 0xC75B17); GUARD_JSR(c, sp_call, 0x5469); } /* count_active_hero_nibbles_in_selected_native_save_copy */
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    RAM8(0x9C00 + x_ret) = (uint8_t)((uint8_t)y_ret + 0xB5);
    SET_A8(r, (uint8_t)((uint8_t)y_ret + 0xB5));
    r->x = (uint16_t)(x_ret + 1);
    r->c = (uint8_t)y_ret + 0xB5 > 0xFF;
    r->z = (uint16_t)(x_ret + 1) == 0;
    r->n = (uint16_t)(x_ret + 1) & 0x8000;
    r->v = (((uint8_t)y_ret ^ (uint8_t)((uint8_t)y_ret + 0xB5)) & ((uint8_t)((uint8_t)y_ret + 0xB5) ^ 0xB5) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75464, SOM_RTS, "gen", append_native_save_confirmation_active_hero_count, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 15, 8)
