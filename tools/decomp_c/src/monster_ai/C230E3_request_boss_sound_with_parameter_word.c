#include "som_c.h"

/* C230E3 request_boss_sound_with_parameter_word   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/request_boss_sound_with_parameter_word.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void request_boss_sound_with_parameter_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0x1E00) = 2;
    RAM8(0x1E01) = (uint8_t)a;
    RAM16_SET(0x1E02, x);
    r->a = x;
    r->z = x == 0;
    r->n = x & 0x8000;
    JSL(c, 0x30FB, 0xC30004); /* audio_command_sender_public_jump */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC230E3, SOM_RTS, "gen", request_boss_sound_with_parameter_word, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 26, 11)
