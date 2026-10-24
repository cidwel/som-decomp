#include "som_c.h"

/* C26F05 request_boss_palette_slots_six_seven_to_zero   [class B, 41 bytes, 16 instructions]
 * Source: src/rom/request_boss_palette_slots_six_seven_to_zero.s
 * Documented in docs/boss-native-screen-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void request_boss_palette_slots_six_seven_to_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM8(0x033F + 6) = 0;
    RAM8(0x033F + 7) = 0;
    r->a = 0x36;
    r->x = 0;
    r->y = 6;
    JSR(c, 0x6F20, 0xC2272D); /* allocate_boss_palette_transition_object */
    r->a = 0x36;
    r->x = 0;
    r->y = 7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6F2C, 0xC2272D); /* allocate_boss_palette_transition_object */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26F05, SOM_RTS, "gen", request_boss_palette_slots_six_seven_to_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 41, 16)
