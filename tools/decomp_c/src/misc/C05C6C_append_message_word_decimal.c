#include "som_c.h"

/* C05C6C append_message_word_decimal   [class B, 89 bytes, 48 instructions]
 * Source: src/rom/append_message_word_decimal.s
 * Entry: M=8 bit X=16 bit DB=any D=$0300.  Callers read: BXYCV.
 */
static void append_message_word_decimal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    RAM8(0x03B6) = 0xC0;
    RAM16_SET(0x03B4, 0);
    RAM16_SET(0x03B0, 5);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0;
    uint16_t y1 = 0x5CC5;
    bool overflow1 = overflow;
    do {
        uint16_t value = BUS16_RDL(c, (RAM8(0x03B6) << 0x10) + RAM16(0x03B4) + y1, RAM8(0x03B6));
        RAM16_SET(BATTLE_TEMP_AC, value);
        BUS16_SET(c, (uint16_t)(x1 + 0x03A4), 0xB5);
        uint16_t value2 = RAM16(0x03D0);
        uint8_t a1 = (uint8_t)value2;
        uint8_t a_hi2 = value2 >> 8;
        for (;;) {
            uint16_t battle_temp_ac = RAM16(BATTLE_TEMP_AC);
            if (!((uint16_t)(((a_hi2 << 8) | a1) - battle_temp_ac) & 0x8000)) {
                uint16_t value3 = BUS16_RDP(c, (uint16_t)(x1 + 0x03A4));
                BUS16_RMW_SET(c, (uint16_t)(x1 + 0x03A4), (uint16_t)(value3 + 1));
                uint8_t a1_next = (uint8_t)(((a_hi2 << 8) | a1) - battle_temp_ac);
                uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a1) - battle_temp_ac) >> 8;
                a1 = a1_next;
                a_hi2 = a_hi2_next;
                continue;
            }
            uint8_t a1_next2 = (uint8_t)(((a_hi2 << 8) | a1) - battle_temp_ac);
            uint8_t a_hi2_next2 = (uint16_t)(((a_hi2 << 8) | a1) - battle_temp_ac) >> 8;
            a1 = a1_next2;
            a_hi2 = a_hi2_next2;
            break;
        }
        uint16_t battle_temp_ac2 = RAM16(BATTLE_TEMP_AC);
        RAM16_SET(0x03D0, (uint16_t)(((a_hi2 << 8) | a1) + battle_temp_ac2));
        RAM16_SET(0x03B0, (uint16_t)(RAM16(0x03B0) - 1));
        a_hi1 = (uint16_t)(((a_hi2 << 8) | a1) + battle_temp_ac2) >> 8;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 2);
        overflow1 = ((((a_hi2 << 8) | a1) ^ (uint16_t)(((a_hi2 << 8) | a1) + battle_temp_ac2)) & (battle_temp_ac2 ^ (uint16_t)(((a_hi2 << 8) | a1) + battle_temp_ac2)) & 0x8000) != 0;
    } while (RAM16(0x03B0) != 0);
    RAM8(0x03B2) = 4;
    uint8_t a_hi3 = a_hi1;
    uint16_t x2 = 0;
    bool carry1 = 0;
    for (;;) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(x2 + 0x03A4));
        uint16_t x3;
        if (value4 != 0xB5) {
            x3 = x2;
        } else {
            RAM8(0x03B2)--;
            if (RAM8(0x03B2) != 0) {
                x2 = (uint16_t)(x2 + 1);
                carry1 = value4 >= 0xB5;
                continue;
            }
            x3 = (uint16_t)(x2 + 1);
        }
        x2 = x3;
        carry1 = value4 >= 0xB5;
        break;
    }
    RAM8(0x03B2)++;
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t a_hi4 = a_hi3;
    uint16_t x4 = x2;
    uint16_t y2 = (value6 << 8) | value5;
    do {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(x4 + 0x03A4));
        BUS8_SET(c, (db << 0x10) + 0xFE00 + y2, value7);
        RAM8(0x03B2)--;
        x4 = (uint16_t)(x4 + 1);
        y2 = (uint16_t)(y2 + 1);
    } while (RAM8(0x03B2) != 0);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi4 << 8) | a;
    r->x = (value9 << 8) | value8;
    r->y = y2;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05C6C, SOM_RTS, "gen", append_message_word_decimal, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 89, 48)
