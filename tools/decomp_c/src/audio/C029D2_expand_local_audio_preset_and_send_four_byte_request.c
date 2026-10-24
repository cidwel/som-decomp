#include "som_c.h"

/* C029D2 expand_local_audio_preset_and_send_four_byte_request   [class B, 42 bytes, 25 instructions]
 * Source: src/rom/expand_local_audio_preset_and_send_four_byte_request.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void expand_local_audio_preset_and_send_four_byte_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0;
    uint8_t a1 = 4;
    uint8_t a_hi1 = (((a_hi << 8) | a) & 0xFF) << 1 << 1 >> 8;
    uint16_t x1 = (((a_hi << 8) | a) & 0xFF) << 1 << 1;
    uint16_t y1 = 0;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0xC02A34 + x1);
        BUS8_SET(c, 0x001E00 + y1, value);
        uint8_t a1_next = (uint8_t)(a1 - 1);
        uint8_t a_hi1_next = value;
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool zero1_next = (uint8_t)(a1 - 1) == 0;
        bool negative1_next = (uint8_t)(a1 - 1) & 0x80;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(a1 != 0)) break;
    }
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = (((a_hi << 8) | a) & 0xFF) << 1 & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->v = overflow;
    r->db = value2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x29FA, 0xC30004); GUARD_JSL(c, sp_call, 0x29FA); } /* audio_command_sender_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC029D2, SOM_RTS, "gen", expand_local_audio_preset_and_send_four_byte_request, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 42, 25)
