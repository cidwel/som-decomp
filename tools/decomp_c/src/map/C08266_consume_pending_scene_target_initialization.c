#include "som_c.h"

/* C08266 consume_pending_scene_target_initialization   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/consume_pending_scene_target_initialization.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void consume_pending_scene_target_initialization(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x00FE);
    if (!(value & 0x80)) {
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x00FE) = 0;
    r->a = (a >> 8 << 8) | value;
    r->mf = 1;
    TAIL_CALL(c, 0xC08E3B, SOM_RTS); /* initialize_scene_target_with_full_direction_branches */
}
SOM_REGISTER(0xC08266, SOM_RTS, "gen", consume_pending_scene_target_initialization, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 12, 6)
