#include "som_c.h"

/* C28380 initialize_left_native58_linked_effect_and_continue   [class B, 49 bytes, 20 instructions]
 * Source: src/rom/initialize_left_native58_linked_effect_and_continue.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_left_native58_linked_effect_and_continue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x8384, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x012C;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8390, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x0022 + value, 0x07FF);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00B2 + value2);
    uint16_t value4 = RAM16(OBJECT_PHASE + value3);
    if (value4 == 6) {
        r->a = value4;
        r->x = value2;
        r->y = value3;
        r->c = 1;
        r->z = value4 == 6;
        r->n = (uint16_t)(value4 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x83AC, 0xC283B1); /* match_left_child_animation_pointer_and_seed_linked_effect */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28380, SOM_RTS, "gen", initialize_left_native58_linked_effect_and_continue, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 20)
