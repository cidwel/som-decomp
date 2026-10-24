#include "som_c.h"

/* C2225B boss_loader_write_word   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/boss_loader_write_word.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_loader_write_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value;
    BUS16_OK(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230), value);
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    RAM16_SET(0x0233, value);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230), value2);
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    uint16_t value3 = RAM16(0x0230);
    BUS16_SET(c, RAM16(0x0233) + 0x7E0000, value2);
    r->a = value2;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2225B, SOM_RTS, "hand", boss_loader_write_word, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 17, 9)
