#include "som_c.h"

/* C05921 enqueue_new_spell_buff_notices   [class B, 62 bytes, 32 instructions]
 * Source: src/rom/enqueue_new_spell_buff_notices.s
 * Documented in docs/actor-cast-spell-remaining.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: B.
 */
static void enqueue_new_spell_buff_notices(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    if (RAM8(0xE1E7 + x) < 0x83) {
        RAM16_SET(BATTLE_MUL_WORK, y);
        RAM8(0x03AA) = 7;
        RAM8(0x03AB) = 0;
        uint8_t a_hi1 = a_hi;
        uint16_t y1 = y;
        bool overflow1 = overflow;
        do {
            uint8_t battle_mul_work = RAM8(BATTLE_MUL_WORK);
            RAM8(BATTLE_MUL_WORK) <<= 1;
            uint8_t a_hi2;
            uint16_t y2;
            bool overflow2;
            if (battle_mul_work & 0x80) {
                uint16_t value2 = RAM16(0x03AA);
                uint16_t value3 = BUS16(c, 0xC05E49 + (uint16_t)(value2 << 1));
                r->x = (uint16_t)(value2 << 1);
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0300;
                r->sp -= 2;
                JSR(c, 0x594A, 0xC05CCF); /* allocate_message_queue_line */
                r->sp += 2;
                uint16_t a_all = r->a;
                uint16_t y_ret = r->y;
                uint8_t value4 = RAM8(0xFE00 + (uint16_t)(y_ret - 1));
                RAM8(0xFE00 + (uint16_t)(y_ret - 1)) = value4 >> 1;
                uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
                r->a = (a_all >> 8 << 8) | (value4 >> 1);
                r->x = battle_defender_ptr;
                r->y = (uint16_t)((uint16_t)(y_ret - 1) + 1);
                r->c = value4 & 0x01;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                JSR(c, 0x5958, 0xC05C06); /* append_actor_name_message_token */
                r->sp += 2;
                bool overflow_ret = r->v;
                r->x = value3;
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0x595C, 0xC05C2A); /* append_rom_message_text */
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                a_hi2 = a_all3 >> 8;
                y2 = y_ret3;
                overflow2 = overflow_ret;
            } else {
                a_hi2 = a_hi1;
                y2 = y1;
                overflow2 = overflow1;
            }
            RAM8(0x03AA)--;
            a_hi1 = a_hi2;
            y1 = y2;
            overflow1 = overflow2;
        } while (!(RAM8(0x03AA) & 0x80));
        r->a = (a_hi1 << 8) | a;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05921, SOM_RTL, "gen", enqueue_new_spell_buff_notices, 0, L_B, 2, 1, 0, 62, 32)
