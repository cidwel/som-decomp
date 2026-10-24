#include "som_c.h"
#include "som_hand_b.h"

/* C213EB interpret_boss_animation_commands_until_frame_record   [class B, 58 bytes, 28 instructions]
 * Source: src/rom/interpret_boss_animation_commands_until_frame_record.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
/* A command handler that drops frames of its caller (a smashed stack in a fuzzed state, never in the game) would resume the original in the
 * caller of this routine; the state is outside the contract. */
#undef I_JSR
#define I_JSR(c, retpc, target) do { push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rts(c); } else { som_call_nested(c, (target), SOM_RTS); if ((c)->unwound) { (c)->fail = 3; return; } } \
    if (!(c)->fail && (c)->cpu.pc != (uint16_t)((retpc) + 1)) { (c)->fail = 3; return; } } while (0)
static void interpret_boss_animation_commands_until_frame_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x009A + x);
    uint16_t value2 = BUS16(c, 0xDBF9A8 + (uint16_t)(value << 1));
    RAM16_SET(0x0276, value2);
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x009C + value3);
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t x1 = value3;
    uint16_t y1 = value4;
    bool carry1 = value & 0x8000;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value5;
        BUS8_OK(c, (uint32_t)((RAM8(0x0278) << 0x10) + RAM16(0x0276) + y1), value5);
        RAM8(0x0266) = value5;
        if ((value5 & 1) != 0) {
            r->a = (a_hi1 << 8) | value5;
            r->x = x1;
            r->y = (uint16_t)(y1 + 1);
            r->z = 0; /* BIT #$01 on an odd byte */
            r->n = value5 >> 7;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            const uint16_t ret_sp = r->sp;
            JSR(c, 0x140A, 0xC21425); /* dispatch_boss_animation_odd_byte_command */
            /* A garbage command can overwrite the pushed return address or leave S elsewhere; the original then resumes elsewhere. */
            if (r->sp != ret_sp || RAM8(ret_sp) != 0x14 || RAM8(ret_sp - 1) != 0x0A) { c->fail = 3; return; }
            r->mf = 1; /* sep */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            continue;
        }
        a1 = value5;
        y1 = (uint16_t)(y1 + 1);
        break;
    }
    RAM8(0x00A0 + x1) = a1;
    uint8_t value6;
    BUS8_OK(c, (uint32_t)((RAM8(0x0278) << 0x10) + RAM16(0x0276) + y1), value6);
    RAM8(0x00A1 + x1) = value6;
    uint8_t value7;
    BUS8_OK(c, (uint32_t)((RAM8(0x0278) << 0x10) + RAM16(0x0276) + (uint16_t)(y1 + 1)), value7);
    RAM8(0x009E + x1) = value7;
    RAM16_SET(0x009C + x1, (uint16_t)(y1 + 2));
    r->a = (uint16_t)(y1 + 2);
    r->x = x1;
    r->y = (uint16_t)(y1 + 2);
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC213EB, SOM_RTS, "hand", interpret_boss_animation_commands_until_frame_record, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 58, 28)
