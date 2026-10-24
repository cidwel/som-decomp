#include "som_c.h"
#include "som_hand_d.h"

/* 7E97EF release_nine_native_title_particle_sprite_records   [class A, 25 bytes, 15 instructions]
 * Source: src/boot/release_nine_native_title_particle_sprite_records.s
 * Documented in docs/boot-native-title-particle-stop.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void release_nine_native_title_particle_sprite_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 0)) return;
L_7E97EF:;
    i_php(c);
    i_sep(r, 0x20);
    a_ldy(r, 0x0);
    a_lda(r, 0x9);
    STA(c, DP, 0x1);
L_7E97F9:;
    i_phy(c);
    LDX(c, DPY, 0xc);
    JSR(c, 0x97FE, 0x7EB786); /* release_native_sprite_or_linked_group */
    REQUIRE_M8X16(c); /* PLY, INY and DEC dp are assembled for a short accumulator and wide index registers */
    i_ply(c);
    i_iny(r);
    i_iny(r);
    DEC(c, DP, 0x1);
    if (!r->z) goto L_7E97F9;
    i_plp(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E97EF, SOM_RTS, "hand", release_nine_native_title_particle_sprite_records, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 25, 15)
