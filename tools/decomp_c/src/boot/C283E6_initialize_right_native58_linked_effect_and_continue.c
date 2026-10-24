#include "som_c.h"

/* C283E6 initialize_right_native58_linked_effect_and_continue   [class B, 70 bytes, 27 instructions]
 * Source: src/rom/initialize_right_native58_linked_effect_and_continue.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_right_native58_linked_effect_and_continue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x83EA, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x0132;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x83F6, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x0022 + value, 0x07FF);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00B2 + value2);
    uint16_t value4 = RAM16(OBJECT_PHASE + value3);
    if (value4 == 6) {
        r->a = 0x0133;
        r->x = value2;
        r->y = value3;
        r->c = value4 >= 6;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8426, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_PHASE + value2, (uint16_t)(RAM16(OBJECT_PHASE + value2) + 1));
        r->c = 0;
        r->z = RAM16(OBJECT_PHASE + value2) == 0;
        r->n = RAM16(OBJECT_PHASE + value2) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x002B + value2, RAM16(0x002B + value3));
    RAM16_SET(0x0032 + value2, RAM16(0x0032 + value3));
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x841E, 0xC2842E); /* match_right_child_animation_pointer_and_seed_linked_effect */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC283E6, SOM_RTS, "gen", initialize_right_native58_linked_effect_and_continue, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 70, 27)
