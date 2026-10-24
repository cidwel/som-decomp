#include "som_c.h"

/* C00FE1 close_temporary_dialogue_and_reset_message_workspace   [class A, 25 bytes, 12 instructions]
 * Source: src/rom/close_temporary_dialogue_and_reset_message_workspace.s
 * Documented in docs/event-dialogue-pause.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYV.
 */
static void close_temporary_dialogue_and_reset_message_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->db = 0x7E;
    r->sp -= 1;
    JSL(c, 0x0FE9, 0xC00EBF); /* reset_map_menu_state */
    r->sp += 1;
    uint16_t a_all = r->a;
    RAM8(0xA162) = 0;
    RAM8(0xA170) = 0x50;
    r->a = (a_all >> 8 << 8) | 0x50;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    JSL(c, 0x0FF7, 0xC01063); /* clear_map_menu_workspace */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00FE1, SOM_RTS, "gen", close_temporary_dialogue_and_reset_message_workspace, 0, L_B | L_Y | L_V, 2, 1, 0, 25, 12)
