#include "som_c.h"

/* C02930 request_native_menu_open_sound_and_fade_in   [class D, 37 bytes, 17 instructions]
 * Source: src/rom/request_native_menu_open_sound_and_fade_in.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void request_native_menu_open_sound_and_fade_in(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA202);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if (value == 0) {
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        r->a = (a_hi << 8) | 0;
        r->z = 1;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2939, 0xC029D2); GUARD_JSR(c, sp_call, 0x2939); } /* expand_local_audio_preset_and_send_four_byte_request */
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    uint8_t a1 = 0;
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y2 = y1;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    for (;;) {
        r->a = (a_hi2 << 8) | a1;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 1;
        r->xf = x_flag;
        r->db = data_bank;
        r->dp = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x293F, 0xC028FF); GUARD_JSR(c, sp_call, 0x293F); } /* await_native_menu_vblank_edge */
        r->sp += 1;
        uint16_t a_all2 = r->a;
        BUS8_SET(c, 0x002100, a1);
        uint8_t a1_next = (uint8_t)(a1 + 2);
        uint8_t a_hi2_next = a_all2 >> 8;
        bool carry2_next = (uint8_t)(a1 + 2) >= 0x0F;
        a1 = a1_next;
        a_hi2 = a_hi2_next;
        carry2 = carry2_next;
        if (!(a1 < 0x0F)) break;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x294D, 0xC028FF); GUARD_JSR(c, sp_call, 0x294D); } /* await_native_menu_vblank_edge */
    BUS8_SET(c, 0x002100, 0x0F);
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02930, SOM_RTS, "gen", request_native_menu_open_sound_and_fade_in, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 37, 17)
