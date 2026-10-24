#include "som_c.h"

/* C23802 boss_state_set_six_motion_words   [class A, 45 bytes, 26 instructions]
 * Source: src/rom/boss_state_set_six_motion_words.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_set_six_motion_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value2);
    RAM16_SET(0x003A + value, value2);
    uint16_t value3;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 2), RAM8(0x0232), value3);
    RAM16_SET(0x003C + value, value3);
    uint16_t value4;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 4), RAM8(0x0232), value4);
    RAM16_SET(0x003E + value, value4);
    uint16_t value5;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 6), RAM8(0x0232), value5);
    RAM16_SET(0x0040 + value, value5);
    uint16_t value6;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 8), RAM8(0x0232), value6);
    RAM16_SET(0x00C4 + value, value6);
    uint16_t value7;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 0x0A), RAM8(0x0232), value7);
    RAM16_SET(0x00C6 + value, value7);
    r->a = value7;
    r->x = value;
    r->y = (uint16_t)(y + 0x0C);
    r->z = (uint16_t)(y + 0x0C) == 0;
    r->n = (uint16_t)(y + 0x0C) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23802, SOM_RTS, "hand", boss_state_set_six_motion_words, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 26)
