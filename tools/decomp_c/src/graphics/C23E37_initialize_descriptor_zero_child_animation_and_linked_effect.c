#include "som_c.h"

/* C23E37 initialize_descriptor_zero_child_animation_and_linked_effect   [class B, 50 bytes, 19 instructions]
 * Source: src/rom/initialize_descriptor_zero_child_animation_and_linked_effect.s
 * Documented in docs/boss-descriptor-zero-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_zero_child_animation_and_linked_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x002B + value, 0x014E);
    RAM16_SET(0x0032 + value, 0x013E);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0000 + value, 1);
    r->a = 0xE7;
    r->x = value;
    JSR(c, 0x3E53, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    r->a = 1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3E59, 0xC23385); /* allocate_parent_linked_boss_effect_and_copy_coordinates */
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(OBJECT_AGE + value2);
    bool zero1;
    bool negative1;
    if (value3 < 0x10) {
        zero1 = value3 == 0x10;
        negative1 = (uint16_t)(value3 - 0x10) & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value2, (uint16_t)(RAM16(OBJECT_PHASE + value2) + 1));
        zero1 = RAM16(OBJECT_PHASE + value2) == 0;
        negative1 = RAM16(OBJECT_PHASE + value2) & 0x8000;
    }
    r->a = value3;
    r->x = value2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23E37, SOM_RTS, "gen", initialize_descriptor_zero_child_animation_and_linked_effect, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 50, 19)
