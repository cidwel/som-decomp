#include "som_c.h"

/* C29D93 initialize_pull_spell_and_capture_parent_facing   [class B, 51 bytes, 20 instructions]
 * Source: src/rom/initialize_pull_spell_and_capture_parent_facing.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_pull_spell_and_capture_parent_facing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    RAM16_SET(0x00BE + value, RAM16(0x00B8 + value2));
    uint16_t value4 = RAM16(0x00B4 + value);
    uint16_t value5 = BUS16(c, 0xDCE6FF + (uint16_t)(value4 << 1));
    uint16_t value6 = RAM16(0x0287);
    r->a = value5;
    r->x = value6;
    r->y = value2;
    r->c = value4 & 0x8000;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DAB, 0xC21394); GUARD_JSR(c, sp_call, 0x9DAB); } /* select_boss_animation_and_reset_frame_cursor */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DAE, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9DAE); } /* request_status_spell_start_sound */
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret2 = r->x;
    RAM16_SET(OBJECT_PHASE + x_ret2, (uint16_t)(RAM16(OBJECT_PHASE + x_ret2) + 1));
    RAM16_SET(0x0022 + x_ret2, 0x07FF);
    uint16_t value7 = RAM16(0x0098 + x_ret2);
    RAM16_SET(0x0098 + x_ret2, value7 & 0x7FFF);
    r->a = value7 & 0x7FFF;
    r->z = (value7 & 0x7FFF) == 0;
    r->n = value7 & 0x7FFF & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DC3, 0xC298DA); GUARD_JSR(c, sp_call, 0x9DC3); } /* activate_spell_child_and_clear_fractional_height */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29D93, SOM_RTS, "gen", initialize_pull_spell_and_capture_parent_facing, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 51, 20)
