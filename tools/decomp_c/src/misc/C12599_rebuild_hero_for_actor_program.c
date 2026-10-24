#include "som_c.h"

/* C12599 rebuild_hero_for_actor_program   [class A, 29 bytes, 20 instructions]
 * Source: src/rom/rebuild_hero_for_actor_program.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXY.
 */
static void rebuild_hero_for_actor_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((uint8_t)((uint8_t)a + 0x80) >= 3) {
        a1 = (uint8_t)((uint8_t)a + 0x80);
        a_hi1 = a >> 8;
        x1 = x;
        y1 = y;
    } else {
        r->a = (a >> 8 << 8) | (uint8_t)((uint8_t)a + 0x80);
        r->x = y;
        r->c = (uint8_t)((uint8_t)a + 0x80) >= 3;
        r->z = y == 0;
        r->n = y & 0x8000;
        r->v = (((uint8_t)a ^ (uint8_t)((uint8_t)a + 0x80)) & ((uint8_t)((uint8_t)a + 0x80) ^ 0x80) & 0x80) != 0;
        r->mf = 1;
        r->sp -= 4;
        JSL(c, 0x25B1, 0xC00036); /* rebuild_actor_stats_public_jump */
        r->sp += 4;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12599, SOM_RTS, "gen", rebuild_hero_for_actor_program, 0, L_A | L_B | L_X | L_Y, 6, 0, 0, 29, 20)
