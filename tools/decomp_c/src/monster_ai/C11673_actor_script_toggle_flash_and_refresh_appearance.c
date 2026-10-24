#include "som_c.h"

/* C11673 actor_script_toggle_flash_and_refresh_appearance   [class B, 69 bytes, 30 instructions]
 * Source: src/rom/actor_script_toggle_flash_and_refresh_appearance.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_toggle_flash_and_refresh_appearance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0191 + y);
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if ((value & 0xDF) != 0) {
        a1 = value & 0xDF;
        a_hi2 = a_hi;
        x1 = x;
        carry1 = carry;
        zero1 = (value & 0xDF) == 0;
        negative1 = value & 0xDF & 0x80;
        overflow1 = overflow;
    } else {
        uint8_t value2 = RAM8(0x01E9 + y);
        RAM8(0x01E3 + y) = value2;
        uint8_t value3 = RAM8(0x01E4 + y);
        RAM8(0x01E4 + y) = (value3 & 0x80) ^ 0x80;
        uint8_t a_hi1;
        if (((value3 & 0x80) ^ 0x80) != 0) {
            a_hi1 = value2;
        } else {
            uint8_t value4 = RAM8(0x01E8 + y);
            RAM8(0x01E3 + y) = value4;
            a_hi1 = value4;
        }
        BUS16_SET(c, 0x004202, (a_hi1 << 8) | 0x0C);
        uint16_t value5 = BUS16(c, 0x004216);
        uint8_t value6 = BUS8(c, 0xD01000 + value5);
        uint8_t value7 = RAM8(0x01E4 + y);
        RAM8(0x01E4 + y) = value6 | value7;
        r->a = (value5 >> 8 << 8) | (value6 | value7);
        r->x = y;
        r->z = y == 0;
        r->n = y & 0x8000;
        r->sp -= 2;
        JSR(c, 0x16B3, 0xC11660); /* actor_script_refresh_appearance_preserving_context */
        r->sp += 2;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x1 = x_ret;
        carry1 = carry_ret;
        zero1 = y == 0;
        negative1 = y & 0x8000;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC11673, SOM_RTS, "gen", actor_script_toggle_flash_and_refresh_appearance, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 69, 30)
