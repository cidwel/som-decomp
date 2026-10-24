#include "som_c.h"

/* C2BF1D initialize_actor_charge_effect_records   [class B, 102 bytes, 47 instructions]
 * Source: src/rom/initialize_actor_charge_effect_records.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void initialize_actor_charge_effect_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM8(0xE061 + x) == 0) {
        uint8_t value2 = RAM8(0xD030 + (x >> 3));
        if (value2 == 0) {
            r->y = x >> 3;
            RETURN_RTL(c);
        }
        RAM8(0xE02E + x) = 0;
        RAM8(0xE061 + x)++;
        r->a = (x >> 0x0B << 8) | value2;
        r->y = x >> 3;
        JSR(c, 0xBF3B, 0xC2C021); /* prepare_actor_charge_effect_primary_record */
        bool overflow_ret = r->v;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xBF3E, 0xC2C000); /* copy_actor_charge_effect_secondary_records */
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        uint8_t value4 = RAM8(ACTOR_CHARGE_STAGE + x_ret2);
        bool overflow4;
        if (value4 < 6) {
            bool overflow2;
            if (value4 < 3) {
                overflow2 = overflow_ret;
            } else {
                RAM8(0xD010 + y_ret) = RAM8(0xD000 + y_ret) | 0x50;
                uint8_t value6 = RAM8(0xD000 + y_ret);
                bool overflow1;
                if ((value6 & 7) != 2) {
                    overflow1 = overflow_ret;
                } else {
                    uint8_t value7 = RAM8(0xD00A + y_ret);
                    RAM8(0xD01A + y_ret) = (uint8_t)(value7 + 2);
                    RAM8(0xD02A + y_ret) = (uint8_t)((uint8_t)(value7 + 2) + 2 + (value7 + 2 > 0xFF));
                    overflow1 = (((uint8_t)(value7 + 2) ^ (uint8_t)((uint8_t)(value7 + 2) + 2 + (value7 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value7 + 2) + 2 + (value7 + 2 > 0xFF)) ^ 2) & 0x80) != 0;
                }
                overflow2 = overflow1;
            }
            overflow4 = overflow2;
        } else {
            uint8_t value8 = RAM8(0xD000 + y_ret);
            RAM8(0xD010 + y_ret) = value8 | 0x50;
            RAM8(0xD020 + y_ret) = value8 | 0xA0;
            uint8_t value9 = RAM8(0xD000 + y_ret);
            bool overflow3;
            if ((value9 & 7) != 2) {
                overflow3 = overflow_ret;
            } else {
                uint8_t value10 = RAM8(0xD00A + y_ret);
                RAM8(0xD01A + y_ret) = (uint8_t)(value10 + 2);
                RAM8(0xD02A + y_ret) = (uint8_t)((uint8_t)(value10 + 2) + 2 + (value10 + 2 > 0xFF));
                overflow3 = (((uint8_t)(value10 + 2) ^ (uint8_t)((uint8_t)(value10 + 2) + 2 + (value10 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value10 + 2) + 2 + (value10 + 2 > 0xFF)) ^ 2) & 0x80) != 0;
            }
            overflow4 = overflow3;
        }
        RAM8(0xE08D + x_ret2)++;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xBF81, 0xC2BF83); /* prepare_actor_charge_effect_eight_tiles */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2BF1D, SOM_RTL, "gen", initialize_actor_charge_effect_records, 0, L_X | L_Y | L_V, 1, 1, 0, 102, 47)
