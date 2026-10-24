#include "som_c.h"

/* C231E0 initialize_animation_linked_child_depth_and_existing_seed   [class B, 68 bytes, 30 instructions]
 * Source: src/rom/initialize_animation_linked_child_depth_and_existing_seed.s
 * Documented in docs/boss-animation-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_animation_linked_child_depth_and_existing_seed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0022 + value, 0x07FF);
    r->a = RAM16(0x009A + value);
    r->x = value;
    JSR(c, 0x31F6, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B0 + value3);
    RAM16_SET(0x0295, RAM16(0x002B + value4));
    RAM16_SET(0x0297, RAM16(0x0032 + value4));
    RAM16_SET(0x002B + value3, (uint16_t)(RAM16(0x0295) + RAM16(0x00B2 + value3)));
    uint16_t value9 = RAM16(0x0297);
    uint16_t value10 = RAM16(0x00B4 + value3);
    RAM16_SET(0x0032 + value3, (uint16_t)(value9 + value10));
    uint16_t value11 = RAM16(0x009E + value3);
    if (value11 != 0) {
        r->a = value11;
        r->x = value3;
        r->c = 0;
        r->z = value11 == 0;
        r->n = value11 & 0x8000;
        r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value11;
    r->x = value3;
    r->c = 1;
    r->z = value11 == 0;
    r->n = value11 & 0x8000;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC231E0, SOM_RTS, "gen", initialize_animation_linked_child_depth_and_existing_seed, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 68, 30)
