#include "som_c.h"

/* C039A4 cap_combat_24bit_value_at_9999999   [class B, 43 bytes, 21 instructions]
 * Source: src/rom/cap_combat_24bit_value_at_9999999.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XYCV.
 */
static void cap_combat_24bit_value_at_9999999(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0xD2));
    if (value < 0x98) {
        r->c = value >= 0x98;
        RETURN_RTS(c);
    }
    if (value == 0x98) {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0xD0));
        if (value2 <= 0x967F) {
            r->c = value2 <= 0x967F;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp + 0xD0), 0x967F);
        r->c = value2 <= 0x967F;
        RETURN_RTS(c);
    }
    if (value >= 0x98) {
        BUS8_SET(c, (uint16_t)(dp + 0xD2), 0x98);
        BUS16_SET(c, (uint16_t)(dp + 0xD0), 0x967F);
        r->c = value >= 0x98;
        RETURN_RTS(c);
    }
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0xD0));
    if (value3 <= 0x967F) {
        r->c = value3 <= 0x967F;
        RETURN_RTS(c);
    }
    BUS16_SET(c, (uint16_t)(dp + 0xD0), 0x967F);
    r->c = value3 <= 0x967F;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC039A4, SOM_RTS, "gen", cap_combat_24bit_value_at_9999999, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 43, 21)
