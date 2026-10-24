#include "som_c.h"

/* C209D6 classify_masked_party_status_by_native_priority   [class B, 79 bytes, 37 instructions]
 * Source: src/rom/classify_masked_party_status_by_native_priority.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void classify_masked_party_status_by_native_priority(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    BUS16_SET(c, (uint16_t)(dp + 0x95), y);
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000));
    if (value == 0) {
        r->a = 0xFFFF;
        r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
        r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 1;
        r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x95));
    BUS16_SET(c, (uint16_t)(dp + 0x95), value & value2);
    if ((value & value2 & 0x8000) == 0) {
        if ((value & value2 & 0x0200) == 0) {
            if ((value & value2 & 0x7F) == 0) {
                if ((value & value2 & 0x0180) == 0) {
                    if ((value & value2 & 0x1C00) == 0) {
                        if ((value & value2 & 0x6000) == 0) {
                            r->a = 0xFFFF;
                            r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
                            r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
                            r->z = 0;
                            r->n = 1;
                            r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                            RETURN_RTS(c);
                        }
                        r->a = 5;
                        r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
                        r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
                        r->z = 0;
                        r->n = 0;
                        r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                        RETURN_RTS(c);
                    }
                    r->a = 4;
                    r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
                    r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
                    r->z = 0;
                    r->n = 0;
                    r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    RETURN_RTS(c);
                }
                r->a = 3;
                r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
                r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            r->a = 2;
            r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
            r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        r->a = 1;
        r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
        r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = 0;
    r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
    r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC209D6, SOM_RTS, "gen", classify_masked_party_status_by_native_priority, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 79, 37)
