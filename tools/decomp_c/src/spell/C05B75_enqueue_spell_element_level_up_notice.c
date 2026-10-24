#include "som_c.h"

/* C05B75 enqueue_spell_element_level_up_notice   [class B, 47 bytes, 20 instructions]
 * Source: src/rom/enqueue_spell_element_level_up_notice.s
 * Documented in docs/actor-cast-spell-dispatch.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void enqueue_spell_element_level_up_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x03B4, x);
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B79, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5B79); } /* allocate_message_queue_line */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B7C, 0xC05C06); GUARD_JSR(c, sp_call, 0x5B7C); } /* append_actor_name_message_token */
    r->x = 0x6279;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B82, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B82); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B85, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5B85); } /* allocate_message_queue_line */
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    RAM8(0xFE00 + y_ret4) = 0x56;
    uint8_t value2 = RAM8(0xE177 + RAM16(0x03B4));
    RAM8(0xFE00 + (uint16_t)(y_ret4 + 1)) = (uint8_t)(value2 + 0x2A);
    r->a = (a_all4 >> 8 << 8) | (uint8_t)(value2 + 0x2A);
    r->x = 0x6256;
    r->y = (uint16_t)(y_ret4 + 2);
    r->c = value2 + 0x2A > 0xFF;
    r->v = ((value2 ^ (uint8_t)(value2 + 0x2A)) & ((uint8_t)(value2 + 0x2A) ^ 0x2A) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B9D, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5B9D); } /* append_rom_message_text */
    uint16_t a_all5 = r->a;
    r->a = (a_all5 >> 8 << 8) | RAM8(0x039D);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BA2, 0xC05B34); GUARD_JSR(c, sp_call, 0x5BA2); } /* external */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05B75, SOM_RTL, "gen", enqueue_spell_element_level_up_notice, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 47, 20)
