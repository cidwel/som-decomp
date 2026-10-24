#include "som_c.h"
#include "som_hand_d.h"

/* C0F1AE publish_secondary_hero_frame_geometry_with_saved_data_bank   [class A, 25 bytes, 13 instructions]
 * Source: src/rom/publish_secondary_hero_frame_geometry_with_saved_data_bank.s
 * Documented in docs/actor-visual-frame-geometry.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void publish_secondary_hero_frame_geometry_with_saved_data_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    i_sep(r, 0x20);
    i_rep(r, 0x10);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    a_ldx(r, 0x0200);
    JSR(c, 0xF1BC, 0xC0F1CF); /* publish_actor_frame_tiles_points_and_collision_rectangle */
    i_rep(r, 0x10);
    a_ldx(r, 0x0400);
    JSR(c, 0xF1C4, 0xC0F1CF); /* publish_actor_frame_tiles_points_and_collision_rectangle */
    i_plb(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F1AE, SOM_RTS, "hand", publish_secondary_hero_frame_geometry_with_saved_data_bank, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 25, 13)
