#include "som_c.h"

/* C24FEB home_native54_projectile_or_enter_contact_animation   [class B, 86 bytes, 34 instructions]
 * Source: src/rom/home_native54_projectile_or_enter_contact_animation.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void home_native54_projectile_or_enter_contact_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = RAM16(0x00A9 + RAM16(0x0287));
    JSR(c, 0x4FF2, 0xC208E3); /* derive_low_byte_target_manhattan_distance */
    uint16_t a_all = r->a;
    uint16_t value3 = RAM16(0x0287);
    if (a_all >= 0x20) {
        r->a = RAM16(0x00A9 + value3);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5007, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all2 = r->a;
        uint16_t value5 = RAM16(0x0287);
        RAM16_SET(0x00AB + value5, a_all2);
        RAM16_SET(0x021A, 2);
        RAM16_SET(0x020D, 0xDC00);
        RAM16_SET(0x020C, 0xE663);
        r->a = 0xE663;
        r->x = value5;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x501E, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x0066 + value3);
    if (value6 < 0x40) {
        RAM16_SET(OBJECT_PHASE + value3, (uint16_t)(RAM16(OBJECT_PHASE + value3) + 1));
        RAM16_SET(0x00A7 + value3, 0);
        RAM16_SET(0x0090 + value3, 0);
        RAM16_SET(0x0066 + value3, 0);
        RAM16_SET(0x00B2 + value3, 0);
        r->a = 0x0170;
        r->x = value3;
        r->c = value6 >= 0x40;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5035, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        r->a = 0x48;
        r->x = 0x0F;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x503E, 0xC226F9); /* copy_boss_palette_with_cpu_words */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + value3);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5007, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
    uint16_t a_all6 = r->a;
    uint16_t value9 = RAM16(0x0287);
    RAM16_SET(0x00AB + value9, a_all6);
    RAM16_SET(0x021A, 2);
    RAM16_SET(0x020D, 0xDC00);
    RAM16_SET(0x020C, 0xE663);
    r->a = 0xE663;
    r->x = value9;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x501E, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24FEB, SOM_RTS, "gen", home_native54_projectile_or_enter_contact_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 86, 34)
