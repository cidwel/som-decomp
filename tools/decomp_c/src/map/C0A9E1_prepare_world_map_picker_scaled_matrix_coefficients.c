#include "som_c.h"

/* C0A9E1 prepare_world_map_picker_scaled_matrix_coefficients   [class B, 51 bytes, 28 instructions]
 * Source: src/rom/prepare_world_map_picker_scaled_matrix_coefficients.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void prepare_world_map_picker_scaled_matrix_coefficients(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00F6);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA9E7, 0xC09368); GUARD_JSR(c, sp_call, 0xA9E7); } /* derive_world_map_ui_curve_coefficients_and_fraction_bytes */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA9EA, 0xC09332); GUARD_JSR(c, sp_call, 0xA9EA); } /* derive_world_map_ui_quadrant_offsets */
    RAM8(0x0000) = 0;
    RAM8(0x0001) = 0;
    r->a = 0xFF;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA9FA, 0xC092E8); GUARD_JSR(c, sp_call, 0xA9FA); } /* multiply_world_map_ui_direction_by_native_byte_scale */
    uint16_t dp_ret = r->dp;
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x36));
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x36));
    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 0x36), (value3 >> 1) | (value2 >> 0x0F << 0x0F));
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x36));
    BUS16_SET(c, (uint16_t)(dp_ret + 0x36), (uint16_t)((uint16_t)(value2 << 2) - value4));
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x38));
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x38));
    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 0x38), (value6 >> 1) | (value5 >> 0x0F << 0x0F));
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x38));
    BUS16_SET(c, (uint16_t)(dp_ret + 0x38), (uint16_t)((uint16_t)(value5 << 2) - value7));
    r->a = (uint16_t)((uint16_t)(value5 << 2) - value7);
    r->c = (uint16_t)(value5 << 2) >= value7;
    r->v = (((uint16_t)(value5 << 2) ^ value7) & ((uint16_t)(value5 << 2) ^ (uint16_t)((uint16_t)(value5 << 2) - value7)) & 0x8000) != 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A9E1, SOM_RTS, "gen", prepare_world_map_picker_scaled_matrix_coefficients, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 51, 28)
