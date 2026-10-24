#include "som_c.h"

/* C8EFD0 lunar_sleep_all_actors   [class A, 22 bytes, 10 instructions]
 * Source: src/rom/lunar_sleep_all_actors.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void lunar_sleep_all_actors(SomCtx *c)
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
    RAM16_SET(BATTLE_MUL_WORK, 0x0A00);
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0x0A00;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
        uint8_t value = RAM8(ACTOR_STATUS + battle_mul_work);
        RAM8(ACTOR_STATUS + battle_mul_work) = value | 0x10;
        RAM8(0x03CD)--;
        RAM8(0x03CD)--;
        a1 = value | 0x10;
        y1 = battle_mul_work;
        zero1 = RAM8(0x03CD) == 0;
        negative1 = RAM8(0x03CD) & 0x80;
        if (!(!negative1)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x;
    r->y = y1;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EFD0, SOM_RTS, "gen", lunar_sleep_all_actors, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 22, 10)
