#include "som_c.h"

/* C293CB select_native7f_nearest_target_and_primary_spell_gate   [class C, 75 bytes, 33 instructions]
 * Source: src/rom/select_native7f_nearest_target_and_primary_spell_gate.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: B.
 */
static void select_native7f_nearest_target_and_primary_spell_gate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x93CD, 0xC23A41); GUARD_JSR(c, sp_call, 0x93CD); } /* select_nearest_living_target_and_eight_way_direction */
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    if ((RAM16(0x01B1 + value) & 0x40) != 0) {
        uint16_t value3 = RAM16(0x00A9 + value);
        if ((RAM16(0x01B1 + (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) & 0x40) != 0) {
            r->a = 0x0A;
            r->x = 0x0A;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000);
            r->c = 0;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            switch (0x0A) {
            case 0x0000: TAIL_CALL_DYN(c, 0xC29424, SOM_RTS); /* cast_native7f_spell_0222 */
            case 0x0002: TAIL_CALL_DYN(c, 0xC29429, SOM_RTS); /* cast_native7f_spell_0205 */
            case 0x0004: TAIL_CALL_DYN(c, 0xC2942E, SOM_RTS); /* cast_native7f_spell_021c */
            case 0x0006: TAIL_CALL_DYN(c, 0xC29433, SOM_RTS); /* cast_native7f_spell_0204 */
            case 0x0008: TAIL_CALL_DYN(c, 0xC29438, SOM_RTS); /* cast_native7f_spell_0229 */
            case 0x000A: TAIL_CALL_DYN(c, 0xC2943D, SOM_RTS); /* cast_native7f_spell_0026 */
            case 0x000C: TAIL_CALL_DYN(c, 0xC29442, SOM_RTS); /* cast_native7f_spell_0028_and_shared_real_cast_execution */
            default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x9416 + (0x0A))), SOM_RTS);
            }
        }
        r->a = 2;
        r->x = value;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000);
        r->c = (uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9405, 0xC2300B); GUARD_JSR(c, sp_call, 0x9405); } /* draw_boss_frame_random_number */
        bool zero_ret2 = r->z;
        if (zero_ret2) {
            r->a = 0x0C;
            r->x = 0x0C;
            r->c = 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            switch (0x0C) {
            case 0x0000: TAIL_CALL_DYN(c, 0xC29424, SOM_RTS); /* cast_native7f_spell_0222 */
            case 0x0002: TAIL_CALL_DYN(c, 0xC29429, SOM_RTS); /* cast_native7f_spell_0205 */
            case 0x0004: TAIL_CALL_DYN(c, 0xC2942E, SOM_RTS); /* cast_native7f_spell_021c */
            case 0x0006: TAIL_CALL_DYN(c, 0xC29433, SOM_RTS); /* cast_native7f_spell_0204 */
            case 0x0008: TAIL_CALL_DYN(c, 0xC29438, SOM_RTS); /* cast_native7f_spell_0229 */
            case 0x000A: TAIL_CALL_DYN(c, 0xC2943D, SOM_RTS); /* cast_native7f_spell_0026 */
            case 0x000C: TAIL_CALL_DYN(c, 0xC29442, SOM_RTS); /* cast_native7f_spell_0028_and_shared_real_cast_execution */
            default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x9416 + (0x0C))), SOM_RTS);
            }
        }
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0;
    r->x = 0;
    r->c = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    switch (0) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC29424, SOM_RTS); /* cast_native7f_spell_0222 */
    case 0x0002: TAIL_CALL_DYN(c, 0xC29429, SOM_RTS); /* cast_native7f_spell_0205 */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2942E, SOM_RTS); /* cast_native7f_spell_021c */
    case 0x0006: TAIL_CALL_DYN(c, 0xC29433, SOM_RTS); /* cast_native7f_spell_0204 */
    case 0x0008: TAIL_CALL_DYN(c, 0xC29438, SOM_RTS); /* cast_native7f_spell_0229 */
    case 0x000A: TAIL_CALL_DYN(c, 0xC2943D, SOM_RTS); /* cast_native7f_spell_0026 */
    case 0x000C: TAIL_CALL_DYN(c, 0xC29442, SOM_RTS); /* cast_native7f_spell_0028_and_shared_real_cast_execution */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x9416 + (0))), SOM_RTS);
    }
}
SOM_REGISTER(0xC293CB, SOM_RTS, "gen", select_native7f_nearest_target_and_primary_spell_gate, SOM_UNWINDS, L_B, 1, 0, 0, 75, 33)
