#include "som_c.h"
#include "som_hand_b.h"

/* D0DCF0 initialize_native_pair_of_equipment_flight_records   [class B, 84 bytes, 32 instructions]
 * Source: src/rom/initialize_native_pair_of_equipment_flight_records.s
 * Documented in docs/event-menu-equipment-flight.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
/* D0DD38 (inside this routine): store the slot number in A * 4 + $0848 into field $0C of the flight record at X. */
static void assign_oam_slot_to_flight_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    r->a &= 0x00FF;
    hand_nz16(r, r->a);
    r->c = (r->a >> 15) & 1;
    r->a = (uint16_t)(r->a << 2);
    r->c = 0; /* CLC */
    r->a = hand_adc16(r, r->a, 0x0848);
    bus16_dp_set(c, (uint16_t)(r->dp + 0x0C + r->x), r->a);
}

static void initialize_native_pair_of_equipment_flight_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint32_t bank = (uint32_t)r->db << 16;
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    bus16_set_once(c, bank + 0x1826, 0);
    r->mf = 1; /* SEP #$20 */
    r->x = BUS16(c, bank + 0x184F);
    hand_nz16(r, r->x);
    r->y = 0x1832;
    JSR_CHK(c, 0xDCFF, 0xD0DD8F); /* initialize_equipment_flight_origin_from_actor_coordinates */
    r->x = BUS16(c, bank + 0x1851);
    hand_nz16(r, r->x);
    r->y = 0x1842;
    JSR_CHK(c, 0xDD08, 0xD0DD8F);
    r->x = 0x1832;
    hand_lda8(r, BUS8(c, bank + 0x1842));
    BUS8_SET(c, bank + 0x1821, (uint8_t)r->a);
    hand_lda8(r, BUS8(c, bank + 0x1832));
    JSR_CHK(c, 0xDD17, 0xD0DD44); /* derive_opposed_native_fixed_point_flight_steps */
    r->x = 0x1836;
    hand_lda8(r, BUS8(c, bank + 0x1843));
    BUS8_SET(c, bank + 0x1821, (uint8_t)r->a);
    hand_lda8(r, BUS8(c, bank + 0x1833));
    JSR_CHK(c, 0xDD26, 0xD0DD44);
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    r->x = 0x1832;
    r->a = BUS16(c, bank + 0x185C);
    hand_nz16(r, r->a);
    push16(c, 0xDD31); /* JSR D0DD38 */
    assign_oam_slot_to_flight_record(c);
    r->sp += 2; /* RTS */
    r->x = 0x1842;
    r->a = BUS16(c, bank + 0x180A);
    hand_nz16(r, r->a);
    assign_oam_slot_to_flight_record(c); /* falls through into the same code */
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DCF0, SOM_RTS, "hand", initialize_native_pair_of_equipment_flight_records, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 84, 32)
