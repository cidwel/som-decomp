#include "som_c.h"
#include "som_hand_b.h"

/* C2661C initialize_descriptor_nine_collision_child_animation_height   [class B, 92 bytes, 38 instructions]
 * Source: src/rom/initialize_descriptor_nine_collision_child_animation_height.s
 * Documented in docs/boss-descriptor-nine-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_nine_collision_child_animation_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    r->a = 0xC7;
    r->x = value;
    JSR_CHK(c, 0x6629, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->x = RAM16(0x0287);
    r->mf = 0;
    r->xf = 0;
    JSR_CHK(c, 0x6634, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B0 + value3);
    uint16_t value5 = RAM16(OBJECT_PHASE + value4);
    if (value5 >= 6) {
        r->a = value5;
        r->x = value4;
        r->c = 1;
        r->z = value5 == 6;
        r->n = (uint16_t)(value5 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0295, RAM16(0x002B + value4));
    RAM16_SET(0x0297, RAM16(0x0032 + value4));
    RAM16_SET(0x0299, RAM16(0x0088 + value4));
    RAM16_SET(0x029B, RAM16(0x0098 + value4) & 0xC0);
    RAM16_SET(0x002B + value3, RAM16(0x0295));
    RAM16_SET(0x0032 + value3, RAM16(0x0297));
    uint16_t flags = (uint16_t)((RAM16(0x0098 + value3) & 0xFF3F) | RAM16(0x029B));
    RAM16_SET(0x0098 + value3, flags);
    r->a = flags;
    r->x = value3;
    r->z = flags == 0;
    r->n = flags >> 15;
    r->mf = 0;
    r->xf = 0;
    JSR_CHK(c, 0x6673, 0xC26678); /* refresh_descriptor_nine_child_animation_from_parent_byte_key */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2661C, SOM_RTS, "hand", initialize_descriptor_nine_collision_child_animation_height, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 92, 38)
