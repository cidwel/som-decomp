#include "som_c.h"

/* C27041 cycle_descriptor_eight_child_three_palette_slots   [class B, 64 bytes, 25 instructions]
 * Source: src/rom/cycle_descriptor_eight_child_three_palette_slots.s
 * Documented in docs/boss-descriptor-eight-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void cycle_descriptor_eight_child_three_palette_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x00B2 + RAM16(0x0287));
    uint16_t value3 = BUS16(c, 0xC270A3 + value2);
    r->a = value3 & 0xFF;
    r->x = 6;
    r->sp -= 2;
    JSR(c, 0x7054, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->sp += 2;
    uint16_t value4 = BUS16(c, 0xC270A7 + value2);
    r->a = value4 & 0xFF;
    r->x = 7;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x7063, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->sp += 2;
    uint16_t value5 = BUS16(c, 0xC270AB + value2);
    r->a = value5 & 0xFF;
    r->x = 0x0D;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7071, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    uint16_t value6 = RAM16(0x0287);
    RAM16_SET(0x00B2 + value6, (uint16_t)(RAM16(0x00B2 + value6) + 1));
    uint16_t value7 = RAM16(0x00B2 + value6);
    RAM16_SET(0x00B2 + value6, value7 & 3);
    r->a = value7 & 3;
    r->x = value6;
    r->z = (value7 & 3) == 0;
    r->n = value7 & 3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27041, SOM_RTS, "gen", cycle_descriptor_eight_child_three_palette_slots, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 64, 25)
