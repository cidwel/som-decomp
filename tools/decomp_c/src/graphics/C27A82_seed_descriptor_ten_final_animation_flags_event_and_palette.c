#include "som_c.h"

/* C27A82 seed_descriptor_ten_final_animation_flags_event_and_palette   [class B, 40 bytes, 15 instructions]
 * Source: src/rom/seed_descriptor_ten_final_animation_flags_event_and_palette.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void seed_descriptor_ten_final_animation_flags_event_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0098 + value, 0x9811);
    r->a = 0x015C;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7A92, 0xC21394); GUARD_JSR(c, sp_call, 0x7A92); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_AGE + value, 0);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7A98, 0xC20B4F); GUARD_JSR(c, sp_call, 0x7A98); } /* boss_death_initialization_reserved_return */
    r->a = 0x8A00;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7A9E, 0xC23963); GUARD_JSR(c, sp_call, 0x7A9E); } /* boss_external_actor_command_if_selected */
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x48;
    r->x = 0x0F;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AA7, 0xC226F9); GUARD_JSR(c, sp_call, 0x7AA7); } /* copy_boss_palette_with_cpu_words */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27A82, SOM_RTS, "gen", seed_descriptor_ten_final_animation_flags_event_and_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 40, 15)
