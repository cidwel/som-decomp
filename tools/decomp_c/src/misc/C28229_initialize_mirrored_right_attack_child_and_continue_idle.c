#include "som_c.h"

/* C28229 initialize_mirrored_right_attack_child_and_continue_idle   [class B, 84 bytes, 32 instructions]
 * Source: src/rom/initialize_mirrored_right_attack_child_and_continue_idle.s
 * Documented in docs/boss-native58-grandchildren.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_mirrored_right_attack_child_and_continue_idle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x822D, 0xC20CE0); GUARD_JSR(c, sp_call, 0x822D); } /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x011B;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8239, 0xC21394); GUARD_JSR(c, sp_call, 0x8239); } /* select_boss_animation_and_reset_frame_cursor */
    uint16_t value2 = RAM16(0x0098 + value);
    RAM16_SET(0x0098 + value, value2 | 0x40);
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value3 = RAM16(0x0287);
    r->a = value2 | 0x40;
    r->x = value3;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x824D, 0xC28322); GUARD_JSR(c, sp_call, 0x824D); } /* follow_mirrored_linked_child_with_sine_direction_offset */
    uint16_t x_ret = r->x;
    uint16_t value4 = RAM16(0x00B2 + x_ret);
    uint16_t value5 = RAM16(OBJECT_PHASE + value4);
    if (value5 == 6) {
        r->a = value5;
        r->y = value4;
        r->c = 1;
        r->z = value5 == 6;
        r->n = (uint16_t)(value5 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x00B4 + value4);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if ((value6 & 0x4000) == 0) {
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        zero1 = (value6 & 0x4000) == 0;
        negative1 = value6 & 0x8000;
    } else {
        RAM16_SET(0x00B4 + x_ret, value6 & 0xFF);
        RAM16_SET(OBJECT_PHASE + x_ret, (uint16_t)(RAM16(OBJECT_PHASE + x_ret) + 1));
        r->a = 0x011C;
        r->y = value4;
        r->c = value5 >= 6;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8272, 0xC21394); GUARD_JSR(c, sp_call, 0x8272); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x00B4 + value4, 0);
        a1 = 0;
        a_hi1 = 0;
        zero1 = 1;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = value4;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28229, SOM_RTS, "gen", initialize_mirrored_right_attack_child_and_continue_idle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 84, 32)
