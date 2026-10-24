#include "som_c.h"

/* C27B0F initialize_native58_parent_and_four_linked_objects   [class B, 177 bytes, 66 instructions]
 * Source: src/rom/initialize_native58_parent_and_four_linked_objects.s
 * Documented in docs/boss-native58-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native58_parent_and_four_linked_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x7B13, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x0121;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B1C, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x00B2 + value, 0);
    RAM16_SET(0x00B4 + value, 0);
    RAM16_SET(0x00B6 + value, 0);
    RAM16_SET(0x00B8 + value, 0);
    RAM16_SET(0x003C + value, 0);
    RAM16_SET(0x0040 + value, 0);
    RAM16_SET(0x001E + value, 6);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B3A, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all3 = r->a;
    uint16_t value2 = RAM16(0x0287);
    RAM16_SET(0x00A9 + value2, a_all3);
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B42, 0xC23372); /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    uint16_t value3 = RAM16(0x0042 + value2);
    RAM16_SET(0x0299, value3);
    r->a = value3;
    r->x = 0x7EC3;
    r->y = 0x1801;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B50, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x0287));
    RAM16_SET(0x0042 + x_ret2, RAM16(0x0299));
    RAM16_SET(0x0182 + x_ret2, 1);
    RAM16_SET(0x0295, x_ret2);
    r->a = 1;
    r->x = 0x8009;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B6B, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret3 = r->x;
    RAM16_SET(0x00B0 + x_ret3, RAM16(0x0287));
    RAM16_SET(0x0042 + x_ret3, RAM16(0x0299));
    RAM16_SET(0x0182 + x_ret3, 1);
    RAM16_SET(0x0297, x_ret3);
    r->a = 1;
    r->x = 0x8374;
    r->y = 0x2A29;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B86, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret4 = r->x;
    RAM16_SET(0x00B0 + x_ret4, RAM16(0x0295));
    RAM16_SET(0x0042 + x_ret4, RAM16(0x0299));
    uint16_t value10 = RAM16(0x0287);
    RAM16_SET(0x00B2 + x_ret4, value10);
    r->a = value10;
    r->x = 0x83D8;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7B9E, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret5 = r->x;
    RAM16_SET(0x00B0 + x_ret5, RAM16(0x0297));
    RAM16_SET(0x0042 + x_ret5, RAM16(0x0299));
    RAM16_SET(0x00B2 + x_ret5, RAM16(0x0287));
    uint16_t value14 = RAM16(0x0287);
    uint16_t value15 = RAM16(OBJECT_AGE + value14);
    bool zero1;
    bool negative1;
    if (value15 < 0x3C) {
        zero1 = value15 == 0x3C;
        negative1 = (uint16_t)(value15 - 0x3C) & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value14, (uint16_t)(RAM16(OBJECT_PHASE + value14) + 1));
        uint16_t value16 = RAM16(OBJECT_PHASE + value14);
        RAM16_SET(OBJECT_AGE + value14, 0);
        zero1 = value16 == 0;
        negative1 = value16 & 0x8000;
    }
    r->a = value15;
    r->x = value14;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27B0F, SOM_RTS, "gen", initialize_native58_parent_and_four_linked_objects, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 177, 66)
