#include "som_c.h"

/* C27480 update_leaping_projectile_direction_velocity_and_collision   [class B, 110 bytes, 44 instructions]
 * Source: src/rom/update_leaping_projectile_direction_velocity_and_collision.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void update_leaping_projectile_direction_velocity_and_collision(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = RAM16(0x00A9 + RAM16(0x0287));
    JSR(c, 0x7487, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
    uint16_t a_all = r->a;
    uint16_t value3 = RAM16(0x0287);
    RAM16_SET(0x00AB + value3, a_all);
    RAM16_SET(0x021A, 4);
    RAM16_SET(0x020D, 0xDC00);
    RAM16_SET(0x020C, 0xE545);
    r->a = 0xE545;
    r->x = value3;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x749E, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
    RAM16_SET(0x0246, RAM16(0x003C + value3));
    uint16_t value5 = RAM16(0x0040 + value3);
    RAM16_SET(0x024E, value5);
    RAM16_SET(0x0256, 0);
    RAM16_SET(0x025E, 0);
    r->a = value5;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x74AF, 0xC22E50); /* derive_eight_way_direction_from_coordinate_pairs */
    uint16_t a_all3 = r->a;
    uint16_t value6 = BUS16(c, 0xDCE535 + (uint16_t)(a_all3 << 1));
    RAM16_SET(0x0297, value6);
    uint16_t value7 = BUS16(c, 0xDCE525 + (uint16_t)(a_all3 << 1));
    uint16_t value8 = RAM16(0x0287);
    r->a = value7;
    r->x = value8;
    r->c = a_all3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x74C0, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0098 + value8, (RAM16(0x0098 + value8) & 0xFF3F) | RAM16(0x0297));
    uint16_t value11 = RAM16(0x0032 + value8);
    RAM16_SET(0x0022 + value8, value11);
    r->a = value11;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x74D4, 0xC23F64); /* test_parent_status_or_projectile_collision */
    bool carry_ret4 = r->c;
    if (carry_ret4) {
        r->a = 0x015C;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x74DD, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        r->a = 0x27;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x74E3, 0xC224C3); /* prepare_boss_loader_resource_expansion */
        uint16_t value12 = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value12, (uint16_t)(RAM16(OBJECT_PHASE + value12) + 1));
        uint16_t value13 = RAM16(OBJECT_PHASE + value12);
        RAM16_SET(0x0090 + value12, 0);
        r->x = value12;
        r->c = 0;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27480, SOM_RTS, "gen", update_leaping_projectile_direction_velocity_and_collision, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 110, 44)
