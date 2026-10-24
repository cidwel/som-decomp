#include "som_c.h"

/* C05C38 append_message_byte_decimal   [class A, 52 bytes, 29 instructions]
 * Source: src/rom/append_message_byte_decimal.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void append_message_byte_decimal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(BATTLE_TEMP_AC) = a;
    RAM8(BATTLE_TEMP_A4) = 0;
    RAM8(BATTLE_TEMP_A6) = 0;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        if (!((uint8_t)(a1 - 0x0A) & 0x80)) {
            RAM8(BATTLE_TEMP_A4)++;
            a1 = (uint8_t)(a1 - 0x0A);
            continue;
        }
        a1 = (uint8_t)(a1 - 0x0A);
        break;
    }
    uint8_t a2 = (uint8_t)(a1 + 0x0A);
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        if (!((uint8_t)(a2 - 1) & 0x80)) {
            RAM8(BATTLE_TEMP_A6)++;
            a2 = (uint8_t)(a2 - 1);
            continue;
        }
        a2 = (uint8_t)(a2 - 1);
        break;
    }
    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
    uint16_t y1;
    if ((uint8_t)(battle_temp_a4 + 0xB5) == 0xB5) {
        y1 = y;
    } else {
        RAM8(BATTLE_TEMP_A4) = (uint8_t)(battle_temp_a4 + 0xB5);
        RAM8(0xFE00 + y) = RAM8(BATTLE_TEMP_A4);
        y1 = (uint16_t)(y + 1);
    }
    uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
    RAM8(0xFE00 + y1) = (uint8_t)(battle_temp_a6 + 0xB5);
    r->a = (a_hi2 << 8) | (uint8_t)(battle_temp_a6 + 0xB5);
    r->x = x;
    r->y = (uint16_t)(y1 + 1);
    r->c = battle_temp_a6 + 0xB5 > 0xFF;
    r->v = ((battle_temp_a6 ^ (uint8_t)(battle_temp_a6 + 0xB5)) & ((uint8_t)(battle_temp_a6 + 0xB5) ^ 0xB5) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05C38, SOM_RTS, "gen", append_message_byte_decimal, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 52, 29)
