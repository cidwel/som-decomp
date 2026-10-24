#include "som_c.h"

/* C23922 boss_state_store_actor_relative_word   [class A, 18 bytes, 12 instructions]
 * Source: src/rom/boss_state_store_actor_relative_word.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_store_actor_relative_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value2);
    RAM16_SET(0x0233, (uint16_t)(value2 + value));
    uint16_t value3;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(y + 2), RAM8(0x0232), value3);
    BUS16_SET(c, RAM16(0x0233) + 0x7E0000, value3);
    r->a = value3;
    r->x = value;
    r->y = (uint16_t)(y + 4);
    r->c = value2 + value > 0xFFFF;
    r->z = (uint16_t)(y + 4) == 0;
    r->n = (uint16_t)(y + 4) & 0x8000;
    r->v = ((value2 ^ (uint16_t)(value2 + value)) & (value ^ (uint16_t)(value2 + value)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23922, SOM_RTS, "hand", boss_state_store_actor_relative_word, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 12)
