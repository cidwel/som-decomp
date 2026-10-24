#include "som_c.h"

/* C23AE7 initialize_terminal_particle_object_palette_animation_and_particles   [class B, 67 bytes, 24 instructions]
 * Source: src/rom/initialize_terminal_particle_object_palette_animation_and_particles.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_terminal_particle_object_palette_animation_and_particles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x07FC, 0x1F);
    RAM16_SET(0x07FE, 0x7FFF);
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0100 + value, 0xEFB4);
    RAM16_SET(0x0018 + value, 0x0F);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0022 + value, 0x07FF);
    r->a = 1;
    r->x = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3B12, 0xC21394); GUARD_JSR(c, sp_call, 0x3B12); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3B18, 0xC23B98); GUARD_JSR(c, sp_call, 0x3B18); } /* initialize_256_native_death_particles */
    uint8_t db_ret = r->db;
    BUS16_SET(c, (db_ret << 0x10) + 0x0351, 1);
    r->a = 0x15;
    r->x = 0x0F;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3B27, 0xC230E3); GUARD_JSR(c, sp_call, 0x3B27); } /* request_boss_sound_with_parameter_word */
    r->c = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23AE7, SOM_RTS, "gen", initialize_terminal_particle_object_palette_animation_and_particles, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 67, 24)
