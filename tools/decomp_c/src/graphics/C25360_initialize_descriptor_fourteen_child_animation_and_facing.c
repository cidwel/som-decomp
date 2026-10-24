#include "som_c.h"

/* C25360 initialize_descriptor_fourteen_child_animation_and_facing   [class B, 63 bytes, 25 instructions]
 * Source: src/rom/initialize_descriptor_fourteen_child_animation_and_facing.s
 * Documented in docs/boss-descriptor-fourteen-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_fourteen_child_animation_and_facing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x5364, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x00B4 + value, 0x87);
    r->a = 0x87;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5376, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0090 + value, 0x539F);
    uint16_t value2 = RAM16(0x00B2 + value);
    uint8_t a_hi1;
    if (value2 == 0) {
        a_hi1 = value2 >> 8;
    } else {
        uint16_t value3 = RAM16(0x0098 + value);
        RAM16_SET(0x0098 + value, value3 | 0x40);
        a_hi1 = (value3 | 0x40) >> 8;
    }
    uint16_t value4 = RAM16(0x0287);
    uint16_t value5 = RAM16(0x00B0 + value4);
    uint16_t value6 = RAM16(OBJECT_PHASE + value5);
    if (value6 >= 6) {
        r->a = value6;
        r->x = value4;
        r->y = value5;
        r->c = 1;
        r->z = value6 == 6;
        r->n = (uint16_t)(value6 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->x = value4;
    r->y = value5;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x539A, 0xC253BD); /* refresh_descriptor_fourteen_child_variant_parent_mode_animation */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25360, SOM_RTS, "gen", initialize_descriptor_fourteen_child_animation_and_facing, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 63, 25)
