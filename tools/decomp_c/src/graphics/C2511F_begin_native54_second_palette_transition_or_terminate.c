#include "som_c.h"

/* C2511F begin_native54_second_palette_transition_or_terminate   [class B, 49 bytes, 22 instructions]
 * Source: src/rom/begin_native54_second_palette_transition_or_terminate.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void begin_native54_second_palette_transition_or_terminate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x00B4 + value);
    uint16_t value3 = RAM16(OBJECT_PHASE + value2);
    if (value3 >= 4) {
        r->a = value3;
        r->x = value2;
        r->c = 1;
        r->z = value3 == 4;
        r->n = (uint16_t)(value3 - 4) & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value5 = RAM16(OBJECT_AGE + value4);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value5 != 0x0C) {
        a1 = (uint8_t)value5;
        a_hi1 = value5 >> 8;
        x1 = value4;
        y1 = y;
        zero1 = value5 == 0x0C;
        negative1 = (uint16_t)(value5 - 0x0C) & 0x8000;
        overflow1 = overflow;
    } else {
        uint16_t value6 = RAM16(0x00B2 + value4);
        r->a = 8;
        r->x = value6;
        r->y = 0x0F;
        r->c = value5 >= 0x0C;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5143, 0xC2272D); GUARD_JSR(c, sp_call, 0x5143); } /* allocate_boss_palette_transition_object */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
        RAM16_SET(OBJECT_PHASE + value7, (uint16_t)(RAM16(OBJECT_PHASE + value7) - 1));
        uint16_t value8 = RAM16(OBJECT_PHASE + value7);
        RAM16_SET(OBJECT_AGE + value7, 0);
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = value7;
        y1 = y_ret;
        zero1 = value8 == 0;
        negative1 = value8 & 0x8000;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2511F, SOM_RTS, "gen", begin_native54_second_palette_transition_or_terminate, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 22)
