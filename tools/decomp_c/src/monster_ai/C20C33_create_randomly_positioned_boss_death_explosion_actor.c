#include "som_c.h"

/* C20C33 create_randomly_positioned_boss_death_explosion_actor   [class B, 86 bytes, 37 instructions]
 * Source: src/rom/create_randomly_positioned_boss_death_explosion_actor.s
 * Documented in docs/boss-native-linked-death-dependencies.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void create_randomly_positioned_boss_death_explosion_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x48;
    r->x = 0x0F;
    JSR(c, 0x0C3B, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->a = 0x40;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0C41, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x0299, a_all2);
    r->a = 0x40;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0C49, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all3 = r->a;
    RAM16_SET(0x029B, a_all3);
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0295, RAM16(0x002B + value));
    RAM16_SET(0x0297, RAM16(0x0032 + value));
    uint16_t value4 = RAM16(0x0098 + value);
    r->a = (value4 & 3) | 0xA920;
    r->x = 0x3197;
    r->y = (value4 & 3) | 0xA920;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0C67, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t a_all4 = r->a;
    uint16_t x_ret4 = r->x;
    bool carry_ret4 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t a_hi1;
    bool overflow1;
    if (carry_ret4) {
        a_hi1 = a_all4 >> 8;
        overflow1 = overflow_ret2;
    } else {
        RAM16_SET(0x002B + x_ret4, (uint16_t)((uint16_t)(((uint16_t)(RAM16(0x0299) - 0x20) ^ 0xFFFF) + 1) + RAM16(0x0295)));
        uint16_t value7 = RAM16(0x029B);
        uint16_t value8 = RAM16(0x0297);
        RAM16_SET(0x0032 + x_ret4, (uint16_t)((uint16_t)(value7 - 0x40) + value8));
        a_hi1 = (uint16_t)((uint16_t)(value7 - 0x40) + value8) >> 8;
        overflow1 = (((uint16_t)(value7 - 0x40) ^ (uint16_t)((uint16_t)(value7 - 0x40) + value8)) & (value8 ^ (uint16_t)((uint16_t)(value7 - 0x40) + value8)) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a_all4;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20C33, SOM_RTS, "gen", create_randomly_positioned_boss_death_explosion_actor, 0, L_B | L_Y | L_V, 1, 0, 0, 86, 37)
