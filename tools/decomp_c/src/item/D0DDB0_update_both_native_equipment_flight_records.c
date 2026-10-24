#include "som_c.h"
#include "som_hand_b.h"

/* D0DDB0 update_both_native_equipment_flight_records   [class B, 121 bytes, 67 instructions]
 * Source: src/rom/update_both_native_equipment_flight_records.s
 * Documented in docs/event-menu-equipment-flight.md
 * Hand-written: the local subroutine D0DDBD (integrate one flight record at X) is implemented
 * below with its real stack use, dp,X accesses (bank 0, 16-bit wrap) and flags.
 */
static int dp_unmapped(uint16_t a) { return a >= 0x2000 && a < 0x8000; }

static void xba_op(Cpu *r)
{
    r->a = (uint16_t)((r->a << 8) | (r->a >> 8));
    hand_nz8(r, (uint8_t)r->a);
}

static void set_lo(Cpu *r, uint8_t v) { r->a = (uint16_t)((r->a & 0xFF00) | v); }

static void integrate_native_equipment_flight_and_publish_or_hide_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint32_t bank = (uint32_t)r->db << 16;
    #define DPX(o) ((uint16_t)(r->dp + (o) + r->x))
    /* Reads that land in the unmapped/hardware part of bank 0 return open bus; those states are out of contract. */
    #define RDB(o) ({ uint16_t a_ = DPX(o); if (dp_unmapped(a_)) { c->fail = 3; return; } (uint8_t)som_rd(c, a_); })
    #define RDW(o) ({ uint16_t a_ = DPX(o); if (dp_unmapped(a_) || dp_unmapped((uint16_t)(a_ + 1))) { c->fail = 3; return; } bus16_dp(c, a_); })
    r->mf = 0; /* callers enter with M=16 */
    r->xf = 0;
    r->a = RDW(0x0C);
    hand_nz16(r, r->a);
    r->y = r->a;
    r->mf = 1; /* SEP #$20 */
    uint8_t v = RDB(0x03);
    hand_lda8(r, v);
    r->c = 1;
    set_lo(r, hand_sbc8(r, (uint8_t)r->a, 3));
    som_wr(c, DPX(0x03), (uint8_t)r->a);
    for (int i = 0; i < 3; i++) {
        r->c = r->a & 1;
        set_lo(r, (uint8_t)r->a >> 1);
    }
    hand_nz8(r, (uint8_t)r->a);
    r->z = (((uint8_t)r->a & 0x10) == 0);
    if (!r->z) set_lo(r, (uint8_t)r->a | 0xE0);
    if (!r->z) hand_nz8(r, (uint8_t)r->a);
    r->c = 0;
    set_lo(r, hand_adc8(r, (uint8_t)r->a, RDB(0x02)));
    som_wr(c, DPX(0x02), (uint8_t)r->a);
    r->c = (uint8_t)r->a >= 0xE8;
    hand_nz8(r, (uint8_t)((uint8_t)r->a - 0xE8));
    if (r->c) {
        r->mf = 1;
        uint8_t n = (uint8_t)som_rd(c, 0x1826 + bank);
        (void)n;
        {
            uint8_t cur = (uint8_t)som_rd(c, bank + 0x1826);
            uint8_t nv = (uint8_t)(cur + 1);
            som_wr(c, bank + 0x1826, nv);
            hand_nz8(r, nv);
        }
        set_lo(r, 0xE8);
        hand_nz8(r, 0xE8);
        som_wr(c, bank + (uint16_t)(r->y + 1), 0xE8);
        return;
    }
    set_lo(r, (uint8_t)~(uint8_t)r->a);
    hand_nz8(r, (uint8_t)r->a);
    set_lo(r, (uint8_t)((uint8_t)r->a + 1));
    hand_nz8(r, (uint8_t)r->a);
    push8(c, (uint8_t)r->a);
    r->mf = 0; /* REP #$20 */
    r->a = RDW(0x0A);
    hand_nz16(r, r->a);
    r->c = 0;
    r->a = hand_adc16(r, r->a, RDW(0x08));
    r->mf = 1; /* SEP #$20 */
    som_wr(c, DPX(0x0A), (uint8_t)r->a);
    xba_op(r);
    r->c = 0;
    set_lo(r, hand_adc8(r, (uint8_t)r->a, RDB(0x01)));
    som_wr(c, DPX(0x01), (uint8_t)r->a);
    r->c = 0;
    set_lo(r, hand_adc8(r, (uint8_t)r->a, c->wram[(r->sp + 1) & 0x1FFFF]));
    c->wram[(r->sp + 1) & 0x1FFFF] = (uint8_t)r->a;
    r->sp++; /* PLA (8-bit) */
    hand_lda8(r, c->wram[r->sp & 0x1FFFF]);
    r->c = (uint8_t)r->a >= 0xF0;
    hand_nz8(r, (uint8_t)((uint8_t)r->a - 0xF0));
    if (r->c) {
        set_lo(r, 0xE8);
        hand_nz8(r, 0xE8);
    }
    xba_op(r);
    r->mf = 0; /* REP #$20 */
    r->a &= 0xFF00;
    hand_nz16(r, r->a);
    push16(c, r->a);
    r->a = RDW(0x06);
    hand_nz16(r, r->a);
    r->c = 0;
    r->a = hand_adc16(r, r->a, RDW(0x04));
    r->mf = 1; /* SEP #$20 */
    som_wr(c, DPX(0x06), (uint8_t)r->a);
    xba_op(r);
    r->c = 0;
    set_lo(r, hand_adc8(r, (uint8_t)r->a, RDB(0x00)));
    som_wr(c, DPX(0x00), (uint8_t)r->a);
    r->mf = 0; /* REP #$20 */
    r->a &= 0x00FF;
    hand_nz16(r, r->a);
    r->a |= (uint16_t)(c->wram[(r->sp + 1) & 0x1FFFF] | (c->wram[(r->sp + 2) & 0x1FFFF] << 8));
    hand_nz16(r, r->a);
    bus16_set_once(c, bank + r->y, r->a);
    r->sp += 2; /* PLA (16-bit) */
    r->a = (uint16_t)(c->wram[r->sp - 1 & 0x1FFFF] | (c->wram[r->sp & 0x1FFFF] << 8));
    hand_nz16(r, r->a);
    #undef DPX
}

static void update_both_native_equipment_flight_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    r->x = 0x1832;
    push16(c, 0xDDB7); /* JSR D0DDBD */
    integrate_native_equipment_flight_and_publish_or_hide_oam(c);
    r->sp += 2;
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    r->x = 0x1842;
    integrate_native_equipment_flight_and_publish_or_hide_oam(c); /* falls through, RTS returns to our caller */
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DDB0, SOM_RTS, "hand", update_both_native_equipment_flight_records, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 121, 67)
