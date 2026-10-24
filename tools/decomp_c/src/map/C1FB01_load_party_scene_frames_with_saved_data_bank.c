#include "som_c.h"

/* C1FB01 load_party_scene_frames_with_saved_data_bank   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/load_party_scene_frames_with_saved_data_bank.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void load_party_scene_frames_with_saved_data_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xFB0A, 0xC1FB0D); /* initialize_twelve_party_scene_animation_frames */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FB01, SOM_RTS, "gen", load_party_scene_frames_with_saved_data_bank, 0, L_B | L_Y | L_C | L_V, 2, 1, 1, 12, 8)
