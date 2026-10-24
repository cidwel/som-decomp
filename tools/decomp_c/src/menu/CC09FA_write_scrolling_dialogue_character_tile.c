#include "som_c.h"

/* CC09FA write_scrolling_dialogue_character_tile   [class B, 49 bytes, 26 instructions]
 * Source: src/rom/write_scrolling_dialogue_character_tile.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void write_scrolling_dialogue_character_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0xA19B);
    uint8_t value2 = RAM8(0x9000 + y);
    uint8_t a2;
    if (value2 == 0x20) {
        a2 = 0;
    } else {
        uint8_t a1;
        if (value2 == 0x2E) {
            a1 = 0x1B;
        } else {
            a1 = (uint8_t)(value2 - 0x40);
        }
        a2 = a1;
    }
    RAM16_SET(0x9400 + value, ((((a_hi << 8) | a2) & 0xFF) << 1) + 0x2100);
    RAM16_SET(0xA19B, (uint16_t)(value + 2));
    r->a = (uint16_t)(value + 2);
    r->x = (uint16_t)(value + 2);
    r->y = (uint16_t)(y + 1);
    r->c = 0;
    r->z = (uint16_t)(value + 2) == 0;
    r->n = (uint16_t)(value + 2) & 0x8000;
    r->v = ((((((a_hi << 8) | a2) & 0xFF) << 1) ^ ((((a_hi << 8) | a2) & 0xFF) << 1) + 0x2100) & (((((a_hi << 8) | a2) & 0xFF) << 1) + 0x2100 ^ 0x2100) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC09FA, SOM_RTS, "gen", write_scrolling_dialogue_character_tile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 49, 26)
