#include "som_c.h"

/* C22240 boss_loader_consume_song_word_and_invoke_music_request   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/boss_loader_consume_song_word_and_invoke_music_request.s
 * Documented in docs/boss-loader-music-command.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_loader_consume_song_word_and_invoke_music_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8_RDL(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230), RAM8(0x0232));
    RAM8(0x0230)++;
    RAM8(0x0230)++;
    r->a = (a_hi << 8) | value;
    r->z = RAM8(0x0230) == 0;
    r->n = RAM8(0x0230) & 0x80;
    TAIL_CALL(c, 0xC230C2, SOM_RTS); /* load_requested_song_with_native_parameter_four */
}
SOM_REGISTER(0xC22240, SOM_RTS, "gen", boss_loader_consume_song_word_and_invoke_music_request, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 4)
