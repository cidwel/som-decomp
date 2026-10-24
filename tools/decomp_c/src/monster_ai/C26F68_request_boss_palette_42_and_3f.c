#include "som_c.h"

/* C26F68 request_boss_palette_42_and_3f   [class B, 52 bytes, 20 instructions]
 * Source: src/rom/request_boss_palette_42_and_3f.s
 * Documented in docs/boss-native-screen-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void request_boss_palette_42_and_3f(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x3C;
    r->x = 0x0D;
    JSR(c, 0x6F70, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    RAM8(0x033F + 6) = 0x42;
    RAM8(0x033F + 7) = 0x3F;
    r->a = 0x36;
    r->x = 0x42;
    r->y = 6;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6F8E, 0xC2272D); /* allocate_boss_palette_transition_object */
    r->a = 0x36;
    r->x = 0x3F;
    r->y = 7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6F9A, 0xC2272D); /* allocate_boss_palette_transition_object */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26F68, SOM_RTS, "gen", request_boss_palette_42_and_3f, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 52, 20)
