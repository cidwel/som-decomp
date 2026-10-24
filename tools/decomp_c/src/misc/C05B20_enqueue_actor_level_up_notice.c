#include "som_c.h"

/* C05B20 enqueue_actor_level_up_notice   [class B, 32 bytes, 13 instructions]
 * Source: src/rom/enqueue_actor_level_up_notice.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void enqueue_actor_level_up_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x03B4, x);
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B24, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5B24); } /* allocate_message_queue_line */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B27, 0xC05C06); GUARD_JSR(c, sp_call, 0x5B27); } /* append_actor_name_message_token */
    r->x = 0x6256;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B2D, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B2D); } /* append_rom_message_text */
    uint16_t a_all3 = r->a;
    uint16_t value = RAM16(0x03B4);
    r->a = (a_all3 >> 8 << 8) | (uint8_t)(RAM8(ACTOR_LEVEL + value) + 1);
    r->x = value;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B36, 0xC05C38); GUARD_JSR(c, sp_call, 0x5B36); } /* append_message_byte_decimal */
    r->x = 0x6263;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B3C, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B3C); } /* append_rom_message_text */
    r->x = RAM16(0x03B4);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05B20, SOM_RTS, "gen", enqueue_actor_level_up_notice, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 32, 13)
