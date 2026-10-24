#include "som_c.h"

/* C25041 consume_native54_projectile_contacts_and_notify_parent_after_animation   [class B, 60 bytes, 27 instructions]
 * Source: src/rom/consume_native54_projectile_contacts_and_notify_parent_after_animation.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void consume_native54_projectile_contacts_and_notify_parent_after_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B2 + value);
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if (value2 != 0) {
        a_hi2 = value2 >> 8;
        x1 = value;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->x = value;
        JSR(c, 0x504A, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t a_hi1;
        if (!carry_ret) {
            a_hi1 = a_all >> 8;
        } else {
            RAM16_SET(0x00B2 + x_ret, 1);
            a_hi1 = 0;
        }
        a_hi2 = a_hi1;
        x1 = x_ret;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value3 = RAM16(0x009E + x1);
    if (value3 != 0) {
        r->a = value3;
        r->x = x1;
        r->y = y1;
        r->c = 0;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0042 + RAM16(0x00B0 + x1));
    r->a = (uint16_t)((uint16_t)((uint16_t)(value5 << 1) + value5) + 0x22 + ((uint16_t)(value5 << 1) + value5 > 0xFFFF));
    r->x = 0x0F;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x506C, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    uint16_t value7 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00B8 + value7, 1);
    r->a = 1;
    r->x = value7;
    r->c = 1;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25041, SOM_RTS, "gen", consume_native54_projectile_contacts_and_notify_parent_after_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 60, 27)
