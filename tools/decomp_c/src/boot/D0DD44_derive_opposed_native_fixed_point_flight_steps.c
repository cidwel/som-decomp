#include "som_c.h"
#include "som_hand_b.h"

/* D0DD44 derive_opposed_native_fixed_point_flight_steps   [class C, 75 bytes, 37 instructions]
 * Source: src/rom/derive_opposed_native_fixed_point_flight_steps.s
 * Documented in docs/event-menu-equipment-flight.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void derive_opposed_native_fixed_point_flight_steps(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint32_t bank = (uint32_t)r->db << 16;
    r->mf = 1; /* SEP #$20 */
    i_php(c);
    uint8_t first = (uint8_t)r->a;
    BUS8_SET(c, bank + 0x1820, first);
    r->y = 0xFFFF;
    r->c = 1;
    uint8_t second = BUS8(c, bank + 0x1821);
    uint8_t gap = hand_sbc8(r, first, second);
    if (!r->c) { /* second > first: use the opposite order and the opposite sign */
        r->c = 1;
        gap = hand_sbc8(r, BUS8(c, bank + 0x1821), BUS8(c, bank + 0x1820));
        r->y = 1;
    }
    r->a = (r->a & 0xFF00) | gap;
    r->mf = 0; /* REP #$20 */
    r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); /* XBA */
    r->a &= 0xFF00;
    hand_nz16(r, r->a);
    i_phy(c);
    r->y = r->a;
    hand_nz16(r, r->y);
    i_php(c);
    r->mf = 1; /* SEP #$20 */
    hand_lda8(r, 0x33);
    JSL_CHK(c, 0xDD6D, 0xD0D7E2); /* divide_menu_number_using_snes_arithmetic_registers */
    r->mf = 0; /* REP #$20 */
    r->a = BUS16(c, bank + 0x4214); /* absolute, so the data bank decides whether this is the divider */
    hand_nz16(r, r->a);
    hand_plp(c);
    i_ply(c);
    hand_cmp16(r, r->y, 0xFFFF);
    if (r->y == 0xFFFF) {
        r->a = (uint16_t)((r->a ^ 0xFFFF) + 1);
        hand_nz16(r, r->a);
    }
    uint16_t step = r->a;
    const uint16_t record = (uint16_t)(r->dp + r->x);
    bus16_dp_set(c, (uint16_t)(record + 0x04), step);
    r->a = (uint16_t)((step ^ 0xFFFF) + 1);
    bus16_dp_set(c, (uint16_t)(record + 0x14), r->a);
    r->a = 0;
    bus16_dp_set(c, (uint16_t)(record + 0x06), 0);
    bus16_dp_set(c, (uint16_t)(record + 0x16), 0);
    hand_plp(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DD44, SOM_RTS, "hand", derive_opposed_native_fixed_point_flight_steps, 0, L_B | L_Y | L_C | L_V, 4, 1, 0, 75, 37)
