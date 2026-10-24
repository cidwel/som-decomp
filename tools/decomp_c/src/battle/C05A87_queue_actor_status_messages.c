#include "som_c.h"

/* C05A87 queue_actor_status_messages   [class B, 118 bytes, 61 instructions]
 * Source: src/rom/queue_actor_status_messages.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_actor_status_messages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE1E7 + x);
    if (value < 0x83) {
        RAM16_SET(0x03B4, 0x5DBB);
        uint16_t value2 = RAM16(0x0398);
        RAM16_SET(BATTLE_DIV_WORK, value2);
        if (!(RAM8(ACTOR_KIND_FLAGS + x) & 0x80)) {
            RAM8(0x03D9) &= 0x7F;
        }
        RAM16_SET(0x03D0, 0x0F);
        RAM16_SET(BATTLE_MUL_WORK, 0x8000);
        RAM8(0x03B6) = 0xC0;
        uint8_t a1 = 0xC0;
        uint8_t a_hi1 = 0x80;
        uint16_t y1 = value2;
        bool carry1 = value >= 0x83;
        bool overflow1 = overflow;
        do {
            uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
            uint16_t battle_div_work = RAM16(BATTLE_DIV_WORK);
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t y2;
            bool overflow2;
            if ((battle_mul_work & battle_div_work) != 0) {
                uint16_t value6 = BUS16(c, (RAM8(0x03B6) << 0x10) + RAM16(0x03B4) + (uint16_t)(RAM16(0x03D0) << 1));
                r->x = value6;
                r->v = battle_div_work & 0x4000;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0300;
                r->sp -= 4;
                JSR(c, 0x5AD9, 0xC05CCF); /* allocate_message_queue_line */
                r->sp += 4;
                uint16_t x_ret = r->x;
                uint16_t y_ret = r->y;
                RAM8(0xFE00 + (uint16_t)(y_ret - 1)) = 0xC0;
                uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
                RAM16_SET(0xFE0F + (uint16_t)((uint16_t)(y_ret - 1) + 1), battle_defender_ptr);
                uint16_t value7 = RAM16(ACTOR_STATUS + battle_defender_ptr);
                RAM16_SET(0xFE11 + (uint16_t)((uint16_t)(y_ret - 1) + 1), value7);
                r->a = value7;
                r->x = battle_defender_ptr;
                r->y = (uint16_t)((uint16_t)(y_ret - 1) + 1);
                r->mf = 1;
                r->xf = 0;
                r->sp -= 6;
                JSR(c, 0x5AF4, 0xC05C06); /* append_actor_name_message_token */
                r->sp += 6;
                bool overflow_ret = r->v;
                r->x = x_ret;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 4;
                JSR(c, 0x5AF8, 0xC05C2A); /* append_rom_message_text */
                r->sp += 4;
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                a2 = (uint8_t)a_all3;
                a_hi2 = a_all3 >> 8;
                y2 = y_ret3;
                overflow2 = overflow_ret;
            } else {
                a2 = (uint8_t)battle_mul_work;
                a_hi2 = battle_mul_work >> 8;
                y2 = y1;
                overflow2 = battle_div_work & 0x4000;
            }
            RAM16_SET(0x03D0, (uint16_t)(RAM16(0x03D0) - 1));
            uint16_t battle_mul_work2 = RAM16(BATTLE_MUL_WORK);
            RAM16_SET(BATTLE_MUL_WORK, RAM16(BATTLE_MUL_WORK) >> 1);
            a1 = a2;
            a_hi1 = a_hi2;
            y1 = y2;
            carry1 = battle_mul_work2 & 0x01;
            overflow1 = overflow2;
        } while (RAM16(BATTLE_MUL_WORK) != 0);
        r->a = (a_hi1 << 8) | a1;
        r->x = x;
        r->y = y;
        r->c = carry1;
        r->z = x == 0;
        r->n = x & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        RETURN_RTL(c);
    }
    SET_A8(r, value);
    r->c = value >= 0x83;
    r->z = value == 0x83;
    r->n = (uint8_t)(value - 0x83) & 0x80;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05A87, SOM_RTL, "gen", queue_actor_status_messages, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 118, 61)
