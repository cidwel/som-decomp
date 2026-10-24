#include "som_c.h"

/* C09EF5 forward_ui_party_icon_to_native_packed_sprite_emitter   [class A, 13 bytes, 6 instructions]
 * Source: src/rom/forward_ui_party_icon_to_native_packed_sprite_emitter.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void forward_ui_party_icon_to_native_packed_sprite_emitter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0004, x);
    RAM16_SET(0x0006, y);
    RAM16_SET(0x0002, 4);
    r->a = 4;
    r->x = a;
    TAIL_CALL(c, 0xC0E640, SOM_RTS); /* emit_packed_actor_sprite_list */
}
SOM_REGISTER(0xC09EF5, SOM_RTS, "gen", forward_ui_party_icon_to_native_packed_sprite_emitter, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 13, 6)
