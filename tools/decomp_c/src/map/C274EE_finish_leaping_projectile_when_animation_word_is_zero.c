#include "som_c.h"

/* C274EE finish_leaping_projectile_when_animation_word_is_zero   [class A, 11 bytes, 7 instructions]
 * Source: src/rom/finish_leaping_projectile_when_animation_word_is_zero.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_leaping_projectile_when_animation_word_is_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x009E + value);
    if (value2 != 0) {
        r->a = value2;
        r->x = value;
        r->c = 0;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->x = value;
    r->c = 1;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC274EE, SOM_RTS, "gen", finish_leaping_projectile_when_animation_word_is_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 11, 7)
