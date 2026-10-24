#include "som_c.h"

/* C226F9 copy_boss_palette_with_cpu_words   [class B, 51 bytes, 28 instructions]
 * Source: src/rom/copy_boss_palette_with_cpu_words.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void copy_boss_palette_with_cpu_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0x033F + x) = (uint8_t)a;
    RAM16_SET(0x0279, ((((x & 0x0F) << 8) | 0) >> 3) + 0x0600);
    RAM16_SET(0x0277, 0xC200);
    uint16_t value = BUS16(c, 0xD0BB24 + (uint16_t)(a << 1));
    RAM16_SET(0x0276, value);
    uint8_t a1 = (uint8_t)value;
    uint8_t a_hi1 = value >> 8;
    uint16_t y1 = 0;
    bool carry1 = a & 0x8000;
    for (;;) {
        uint16_t value2 = BUS16(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y1);
        BUS16_SET(c, RAM16(0x0279) + 0x7E0000 + y1, value2);
        uint8_t a1_next = (uint8_t)value2;
        uint8_t a_hi1_next = value2 >> 8;
        uint16_t y1_next = (uint16_t)(y1 + 2);
        bool carry1_next = (uint16_t)(y1 + 2) >= 0x20;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        if (!(y1 < 0x20)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = (uint16_t)(a << 1);
    r->y = y1;
    r->c = carry1;
    r->v = ((((((x & 0x0F) << 8) | 0) >> 3) ^ ((((x & 0x0F) << 8) | 0) >> 3) + 0x0600) & (((((x & 0x0F) << 8) | 0) >> 3) + 0x0600 ^ 0x0600) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC226F9, SOM_RTS, "gen", copy_boss_palette_with_cpu_words, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 51, 28)
