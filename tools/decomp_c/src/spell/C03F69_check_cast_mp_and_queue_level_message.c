#include "som_c.h"

/* C03F69 check_cast_mp_and_queue_level_message   [class C, 155 bytes, 67 instructions]
 * Source: src/rom/check_cast_mp_and_queue_level_message.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void check_cast_mp_and_queue_level_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 4;
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, 0x004216);
    uint8_t value2 = BUS8(c, 0xD02ADF + value);
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    RAM8(BATTLE_TEMP_A4) = value2;
    uint8_t value3 = RAM8(ACTOR_MP + battle_attacker_ptr);
    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if (!((uint8_t)(value3 - battle_temp_a4) & 0x80)) {
        r->a = (uint8_t)(value3 - battle_temp_a4);
        r->x = battle_attacker_ptr;
        r->c = value3 >= battle_temp_a4;
        r->v = ((value3 ^ battle_temp_a4) & (value3 ^ (uint8_t)(value3 - battle_temp_a4)) & 0x80) != 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3F8F, 0xC05AFD); GUARD_JSL(c, sp_call, 0x3F8F); } /* queue_cast_spell_level_message */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        a1 = 0;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
    } else {
        a1 = 0xFF;
        a_hi1 = 0;
        x1 = battle_attacker_ptr;
        y1 = y;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value5;
    r->dp = (value7 << 8) | value6;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    r->sp += 4;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC03F69, SOM_RTL, "gen", check_cast_mp_and_queue_level_message, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 155, 67)
