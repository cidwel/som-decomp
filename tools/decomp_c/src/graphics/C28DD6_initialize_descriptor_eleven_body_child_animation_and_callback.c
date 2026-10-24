#include "som_c.h"

/* C28DD6 initialize_descriptor_eleven_body_child_animation_and_callback   [class B, 68 bytes, 27 instructions]
 * Source: src/rom/initialize_descriptor_eleven_body_child_animation_and_callback.s
 * Documented in docs/boss-descriptor-eleven-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_eleven_body_child_animation_and_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x0157;
    r->x = value;
    JSR(c, 0x8DE3, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0090 + value, 0x8E1A);
    RAM16_SET(0x00B2 + value, 0);
    uint16_t value2 = RAM16(0x0287);
    r->a = 0x8E1A;
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8DF4, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B0 + value3);
    uint16_t value5 = RAM16(OBJECT_PHASE + value4);
    uint8_t a2;
    uint8_t a_hi2;
    bool carry1;
    bool zero2;
    bool negative2;
    if (value5 >= 6) {
        a2 = (uint8_t)value5;
        a_hi2 = value5 >> 8;
        carry1 = value5 >= 6;
        zero2 = value5 == 6;
        negative2 = (uint16_t)(value5 - 6) & 0x8000;
    } else {
        uint16_t value7 = BUS16(c, 0xC28EB0 + (uint16_t)(RAM16(0x007A + value4) << 1));
        uint16_t value8 = RAM16(0x00B2 + value3);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value7 == value8) {
            a1 = (uint8_t)value7;
            a_hi1 = value7 >> 8;
            zero1 = value7 == value8;
            negative1 = (uint16_t)(value7 - value8) & 0x8000;
        } else {
            RAM16_SET(0x00B2 + value3, value7);
            r->a = value7;
            r->x = value3;
            r->y = value4;
            r->c = value7 >= value8;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x8E17, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all3 = r->a;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        carry1 = 0;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = value3;
    r->y = value4;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28DD6, SOM_RTS, "gen", initialize_descriptor_eleven_body_child_animation_and_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 68, 27)
