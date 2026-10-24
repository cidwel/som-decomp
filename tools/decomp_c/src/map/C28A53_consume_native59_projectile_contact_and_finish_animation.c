#include "som_c.h"

/* C28A53 consume_native59_projectile_contact_and_finish_animation   [class B, 30 bytes, 15 instructions]
 * Source: src/rom/consume_native59_projectile_contact_and_finish_animation.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void consume_native59_projectile_contact_and_finish_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B4 + value);
    uint8_t a_hi2;
    uint16_t y1;
    bool overflow1;
    if (value2 != 0) {
        a_hi2 = value2 >> 8;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->x = value;
        JSR(c, 0x8A5C, 0xC23F64); /* test_parent_status_or_projectile_collision */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t a_hi1;
        if (!carry_ret) {
            a_hi1 = a_all >> 8;
        } else {
            uint16_t value3 = RAM16(0x0287);
            uint16_t value4 = RAM16(0x02C7);
            RAM16_SET(0x00B4 + value3, value4);
            a_hi1 = value4 >> 8;
        }
        a_hi2 = a_hi1;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value5 = RAM16(0x0287);
    uint16_t value6 = RAM16(0x009E + value5);
    if (value6 != 0) {
        r->a = value6;
        r->x = value5;
        r->y = y1;
        r->c = 0;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value6;
    r->x = value5;
    r->y = y1;
    r->c = 1;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28A53, SOM_RTS, "gen", consume_native59_projectile_contact_and_finish_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 15)
