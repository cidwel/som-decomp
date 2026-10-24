#include "som_c.h"

/* C305DF adjust_native_sound_cursor_by_aligned_word_and_direct_page_reference   [class A, 20 bytes, 13 instructions]
 * Source: src/boot/adjust_native_sound_cursor_by_aligned_word_and_direct_page_reference.s
 * Documented in docs/source-recovery-parallel-sound-cursor-math.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void adjust_native_sound_cursor_by_aligned_word_and_direct_page_reference(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = RAM16(0x0315);
    RAM16_SET(0x0315, (uint16_t)((uint16_t)((value & 0xFF80) - RAM16(0x03FA)) + value));
    SET_A8(r, (uint8_t)((a_hi << 8) | a));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC305DF, SOM_RTS, "gen", adjust_native_sound_cursor_by_aligned_word_and_direct_page_reference, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 20, 13)
