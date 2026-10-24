#include "som_c.h"

/* C753D6 append_native_confirmation_hero_statistics   [class A, 21 bytes, 10 instructions]
 * Source: src/rom/append_native_confirmation_hero_statistics.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_confirmation_hero_statistics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x9C00 + x) = 0xA2;
    RAM8(0x9C00 + (uint16_t)(x + 1)) = 0xAA;
    r->a = (a_hi << 8) | 6;
    r->x = (uint16_t)(x + 2);
    { const uint16_t sp_call = r->sp; JSR(c, 0x53E6, 0xC759E0); GUARD_JSR(c, sp_call, 0x53E6); } /* append_native_saved_slot_format_pair */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x53E9, 0xC759FC); GUARD_JSR(c, sp_call, 0x53E9); } /* append_two_valid_native_saved_slot_statistics */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC753D6, SOM_RTS, "gen", append_native_confirmation_hero_statistics, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 21, 10)
