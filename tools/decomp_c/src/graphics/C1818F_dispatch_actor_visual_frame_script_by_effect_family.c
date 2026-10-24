#include "som_c.h"
#include "som_hand_d.h"

/* C1818F dispatch_actor_visual_frame_script_by_effect_family   [class B, 32 bytes, 16 instructions]
 * Source: src/rom/dispatch_actor_visual_frame_script_by_effect_family.s
 * Documented in docs/actor-visual-effect-scripts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void dispatch_actor_visual_frame_script_by_effect_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_sep(r, 0x20);
    RAM8(0xE00C + r->x) = 0;
    a_and(r, 0xE0);
    a_cmp(r, 0x80);
    if (r->z) {
        JSR(c, 0x819C, 0xC18245); /* advance_and_finish_native_ordinary_cast_frame_script */
        RETURN_RTL(c);
    }
    a_cmp(r, 0xE0);
    if (r->z) {
        JSR(c, 0x81A4, 0xC1824E); /* advance_native_cell_cast_frame_script_and_homing_cell */
        RETURN_RTL(c);
    }
    a_cmp(r, 0xC0);
    if (r->z) {
        JSR(c, 0x81AC, 0xC181AF); /* advance_and_finish_native_motion_effect_frame_script */
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1818F, SOM_RTL, "hand", dispatch_actor_visual_frame_script_by_effect_family, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 32, 16)
