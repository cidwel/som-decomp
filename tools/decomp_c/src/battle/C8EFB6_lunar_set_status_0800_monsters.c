#include "som_c.h"

/* C8EFB6 lunar_set_status_0800_monsters   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/lunar_set_status_0800_monsters.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void lunar_set_status_0800_monsters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(BATTLE_MUL_WORK, 0x0600);
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0x0600;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
        RAM8(ACTOR_STATUS_HIGH + battle_mul_work) |= 8;
        RAM8(0x03CD)++;
        RAM8(0x03CD)++;
        uint8_t value2 = RAM8(0x03CD);
        a1 = value2;
        y1 = battle_mul_work;
        carry1 = value2 >= 0x0C;
        zero1 = value2 == 0x0C;
        negative1 = (uint8_t)(value2 - 0x0C) & 0x80;
        if (!(a1 != 0x0C)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EFB6, SOM_RTS, "gen", lunar_set_status_0800_monsters, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 26, 12)
