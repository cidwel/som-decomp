#include "som_c.h"

/* C267AE rotate_five_native_boss_palette_color_words   [class A, 35 bytes, 13 instructions]
 * Source: src/rom/rotate_five_native_boss_palette_color_words.s
 * Documented in docs/boss-native-visual-callbacks.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void rotate_five_native_boss_palette_color_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x0295, RAM16(0x07CE));
    RAM16_SET(0x07CE, RAM16(0x07D0));
    RAM16_SET(0x07D0, RAM16(0x07D2));
    RAM16_SET(0x07D2, RAM16(0x07D4));
    RAM16_SET(0x07D4, RAM16(0x07D6));
    uint16_t value6 = RAM16(0x0295);
    RAM16_SET(0x07D6, value6);
    r->a = value6;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC267AE, SOM_RTS, "gen", rotate_five_native_boss_palette_color_words, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 35, 13)
