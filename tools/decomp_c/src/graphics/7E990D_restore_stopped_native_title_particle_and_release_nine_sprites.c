#include "som_c.h"

/* 7E990D restore_stopped_native_title_particle_and_release_nine_sprites   [class A, 15 bytes, 9 instructions]
 * Source: src/boot/restore_stopped_native_title_particle_and_release_nine_sprites.s
 * Documented in docs/boot-native-title-particle-stop.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void restore_stopped_native_title_particle_and_release_nine_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9915, 0x7EAD41); GUARD_JSR(c, sp_call, 0x9915); } /* select_native_task_stack_page_as_direct_page */
    r->sp += 3;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9918, 0x7E97EF); GUARD_JSR(c, sp_call, 0x9918); } /* release_nine_native_title_particle_sprite_records */
    r->sp += 3;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0x7E990D, SOM_RTL, "gen", restore_stopped_native_title_particle_and_release_nine_sprites, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 15, 9)
