#include "som_c.h"

/* C28E46 initialize_descriptor_eleven_height_child_animation_and_callback   [class B, 74 bytes, 30 instructions]
 * Source: src/rom/initialize_descriptor_eleven_height_child_animation_and_callback.s
 * Documented in docs/boss-descriptor-eleven-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_eleven_height_child_animation_and_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x015A;
    r->x = value;
    JSR(c, 0x8E53, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0090 + value, 0x8E92);
    RAM16_SET(0x00B2 + value, 0);
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00B0 + value2);
    uint16_t value4 = RAM16(OBJECT_PHASE + value3);
    if (value4 >= 6) {
        RAM16_SET(OBJECT_PHASE + value2, (uint16_t)(RAM16(OBJECT_PHASE + value2) + 1));
        r->a = 0x0133;
        r->x = value2;
        r->y = value3;
        r->c = value4 >= 6;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8E8D, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = BUS16(c, 0xC28EE8 + (uint16_t)(RAM16(0x007A + value3) << 1));
    uint16_t value7 = RAM16(0x00B2 + value2);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value6 == value7) {
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        zero1 = value6 == value7;
        negative1 = (uint16_t)(value6 - value7) & 0x8000;
    } else {
        RAM16_SET(0x00B2 + value2, value6);
        r->a = value6;
        r->x = value2;
        r->y = value3;
        r->c = value6 >= value7;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8E82, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all3 = r->a;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value2;
    r->y = value3;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28E46, SOM_RTS, "gen", initialize_descriptor_eleven_height_child_animation_and_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 74, 30)
