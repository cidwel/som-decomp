#include "som_c.h"

/* C05B40 enqueue_actor_weapon_level_up_notice   [class B, 53 bytes, 22 instructions]
 * Source: src/rom/enqueue_actor_weapon_level_up_notice.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void enqueue_actor_weapon_level_up_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM16_SET(0x03B4, x);
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B44, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5B44); } /* allocate_message_queue_line */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B47, 0xC05C06); GUARD_JSR(c, sp_call, 0x5B47); } /* append_actor_name_message_token */
    r->x = 0x6265;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B4D, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B4D); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B50, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5B50); } /* allocate_message_queue_line */
    uint16_t a_all4 = r->a;
    uint16_t value = RAM16(0x03B4);
    RAM8(0x0000 + sp0) = RAM8(ACTOR_WEAPON_LEVEL + value);
    uint8_t value3 = RAM8(0xE1E4 + value);
    uint16_t value4 = BUS16(c, 0xC05DFB + ((((a_all4 >> 8 << 8) | value3) & 7) << 1));
    r->a = value4;
    r->x = value4;
    r->c = ((a_all4 >> 8 << 8) | value3) & 7 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B6A, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B6A); } /* append_rom_message_text */
    r->sp += 1;
    r->x = 0x6256;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B70, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B70); } /* append_rom_message_text */
    r->sp += 1;
    uint16_t a_all6 = r->a;
    r->a = (a_all6 >> 8 << 8) | RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC05B34, SOM_RTS); /* external */
}
SOM_REGISTER(0xC05B40, SOM_RTS, "gen", enqueue_actor_weapon_level_up_notice, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 53, 22)
