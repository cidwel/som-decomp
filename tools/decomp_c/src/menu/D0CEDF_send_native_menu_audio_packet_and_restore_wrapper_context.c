#include "som_c.h"

/* D0CEDF send_native_menu_audio_packet_and_restore_wrapper_context   [class C, 105 bytes, 61 instructions]
 * Source: src/rom/send_native_menu_audio_packet_and_restore_wrapper_context.s
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void send_native_menu_audio_packet_and_restore_wrapper_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    const uint16_t sp0 = r->sp + 3;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    BUS8_SET(c, (db << 0x10) + 0x1E01, a);
    BUS8_SET(c, (db << 0x10) + 0x1E00, 2);
    BUS8_SET(c, (db << 0x10) + 0x1E02, 0x0F);
    BUS8_SET(c, (db << 0x10) + 0x1E03, 0);
    r->a = (a_hi << 8) | 0x0F;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCEF4, 0xC30004); GUARD_JSL(c, sp_call, 0xCEF4); } /* audio_command_sender_public_jump */
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    if (value & 0x20) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        SET_A8(r, value2);
        r->c = value & 0x01;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->v = value & 0x40;
        r->mf = 1;
        r->xf = value & 0x10;
        r->i = value & 0x04;
        r->d = value & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 2;
        RETURN_RTL(c);
    } else {
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->a = (value4 << 8) | value3;
        r->c = value & 0x01;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->v = value & 0x40;
        r->mf = 0;
        r->xf = value & 0x10;
        r->i = value & 0x04;
        r->d = value & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 3;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xD0CEDF, SOM_RTL, "gen", send_native_menu_audio_packet_and_restore_wrapper_context, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, -1, 105, 61)
