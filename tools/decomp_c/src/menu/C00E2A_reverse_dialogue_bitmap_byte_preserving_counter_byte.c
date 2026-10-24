#include "som_c.h"

/* C00E2A reverse_dialogue_bitmap_byte_preserving_counter_byte   [class A, 22 bytes, 14 instructions]
 * Source: src/rom/reverse_dialogue_bitmap_byte_preserving_counter_byte.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXY.
 */
static void reverse_dialogue_bitmap_byte_preserving_counter_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0xA198) = 0;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a;
    for (;;) {
        RAM8(0xA198) = (RAM8(0xA198) >> 1) | (a_hi1 >> 7 << 7);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = (uint8_t)(a_hi1 << 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi << 8) | RAM8(0xA198);
    r->x = x;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00E2A, SOM_RTS, "gen", reverse_dialogue_bitmap_byte_preserving_counter_byte, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 22, 14)
