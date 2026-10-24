#include "som_c.h"

/* C29AF7 seed_sixteen_direction_spell_velocity_animation_and_sound   [class B, 105 bytes, 45 instructions]
 * Source: src/rom/seed_sixteen_direction_spell_velocity_animation_and_sound.s
 * Documented in docs/boss-native-spell-projectile-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void seed_sixteen_direction_spell_velocity_animation_and_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->a = RAM16(0x00B8 + x);
    JSR(c, 0x9AFC, 0xC20965); /* derive_fine_direction_to_low_byte_target */
    uint16_t a_all = r->a;
    RAM16_SET(0x0295, a_all >> 4);
    uint16_t value2 = BUS16(c, 0xC29B60 + (a_all >> 4 << 1));
    RAM16_SET(0x0297, value2);
    uint16_t value3 = BUS16(c, 0xC29B80 + (a_all >> 4 << 1));
    RAM16_SET(0x0299, value3);
    uint16_t value4 = BUS16(c, 0xC29BA0 + (a_all >> 4 << 1 << 1 << 1));
    RAM16_SET(0x029B, value4);
    uint16_t value5 = BUS16(c, 0xC29BA2 + (a_all >> 4 << 1 << 1 << 1));
    RAM16_SET(0x029D, value5);
    uint16_t value6 = BUS16(c, 0xC29BA4 + (a_all >> 4 << 1 << 1 << 1));
    RAM16_SET(0x029F, value6);
    uint16_t value7 = BUS16(c, 0xC29BA6 + (a_all >> 4 << 1 << 1 << 1));
    RAM16_SET(0x02A1, value7);
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x003A + value8, RAM16(0x029B));
    RAM16_SET(0x003C + value8, RAM16(0x029D));
    RAM16_SET(0x003E + value8, RAM16(0x029F));
    RAM16_SET(0x0040 + value8, RAM16(0x02A1));
    RAM16_SET(0x0098 + value8, (RAM16(0x0098 + value8) & 0xFF3F) | RAM16(0x0299));
    r->a = RAM16(0x0297);
    r->x = value8;
    r->c = a_all >> 4 << 1 << 1 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9B52, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0090 + value8, 0x9C20);
    RAM16_SET(OBJECT_AGE + value8, 0);
    r->a = 0x9C20;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9B5E, 0xC29AD1); /* request_follow_spell_target_sound */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29AF7, SOM_RTS, "gen", seed_sixteen_direction_spell_velocity_animation_and_sound, 0, 0, 1, 0, 0, 105, 45)
