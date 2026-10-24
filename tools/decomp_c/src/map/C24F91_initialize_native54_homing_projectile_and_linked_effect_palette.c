#include "som_c.h"

/* C24F91 initialize_native54_homing_projectile_and_linked_effect_palette   [class B, 90 bytes, 34 instructions]
 * Source: src/rom/initialize_native54_homing_projectile_and_linked_effect_palette.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native54_homing_projectile_and_linked_effect_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0066 + value, 0x80);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0022 + value, RAM16(0x0032 + value));
    r->a = 0x75;
    r->x = value;
    JSR(c, 0x4FAD, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00A7 + value, 0);
    RAM16_SET(0x0090 + value, 0x507D);
    RAM16_SET(0x003A + value, 0);
    RAM16_SET(0x003C + value, 0);
    RAM16_SET(0x003E + value, 0);
    RAM16_SET(0x0040 + value, 0);
    RAM16_SET(0x00C4 + value, 0);
    RAM16_SET(0x00C6 + value, 0x10);
    r->a = 1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4FD1, 0xC23385); /* allocate_parent_linked_boss_effect_and_copy_coordinates */
    uint16_t value5 = RAM16(0x0042 + RAM16(0x00B0 + RAM16(0x0287)));
    r->a = (uint16_t)((uint16_t)((uint16_t)(value5 << 1) + value5) + 0x22 + ((uint16_t)(value5 << 1) + value5 > 0xFFFF));
    r->x = 0x0F;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4FE8, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24F91, SOM_RTS, "gen", initialize_native54_homing_projectile_and_linked_effect_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 90, 34)
