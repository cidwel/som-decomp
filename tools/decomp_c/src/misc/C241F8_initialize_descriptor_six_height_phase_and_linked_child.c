#include "som_c.h"

/* C241F8 initialize_descriptor_six_height_phase_and_linked_child   [class A, 27 bytes, 10 instructions]
 * Source: src/rom/initialize_descriptor_six_height_phase_and_linked_child.s
 * Documented in docs/boss-descriptor-six.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_six_height_phase_and_linked_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x41FA, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0066 + x, 0x10);
    RAM16_SET(0x007E + x, 0);
    r->a = 0x10;
    r->x = 0x4091;
    r->y = 0x3801;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x420C, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x00B0 + x_ret, value);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC241F8, SOM_RTS, "gen", initialize_descriptor_six_height_phase_and_linked_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 27, 10)
