#include "som_c.h"
#include "som_hand_d.h"

/* C20DB2 update_nine_boss_actor_slots_combat_definition_and_animation   [class B, 144 bytes, 64 instructions]
 * Source: src/rom/update_nine_boss_actor_slots_combat_definition_and_animation.s
 * Documented in docs/rom-combat.md
 * Hand-written: the per-slot X is really pushed on the stack (the dispatched definition handlers read it back
 * from the stack), and every dp access stays in bank 0.  Callees that unwind the stack are out of contract.
 */
static void update_nine_boss_actor_slots_combat_definition_and_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->mf) RAM8(0x0E69) = 0; else RAM16_SET(0x0E69, 0);
    i_sep(r, 0x20);
    a_lda(r, RAM8(0x0056));
    RAM8(0x02C9) = r->a;
    if (r->z) JSR(c, 0x0DC1, 0xC20E6A); /* reload_boss_graphics_cache_markers_through_wram_port */
    REQUIRE_X16(c);
    if (r->mf) dp_wr8(c, 0xCA, 0); else dp_wr16(c, 0xCA, 0);
    a_ldx(r, 0x0000); /* slot index */
    do {
        a_lda(r, RAM8(0x0E60 + r->x)); /* slot in use */
        if (!r->z) {
            bool done = false; /* the slot was released: its in-use byte is already cleared */
            bool skip = false;
            i_phx(c);
            i_rep(r, 0x20);
            i_txa(r);
            dp_wr16(c, 0x8B, r->a);
            i_xba(r);
            i_asla(r);
            r->c = 0;
            a_adc(r, 0xE600);
            i_tax(r);
            dp_wr16(c, 0x87, r->x); /* object of the slot */
            a_lda(r, dp_rd16(c, 0x8B));
            i_xba(r);
            i_lsra(r);
            r->c = 0;
            a_adc(r, 0xF800);
            dp_wr16(c, 0x89, r->a);
            a_lda(r, RAM16(0x0098 + r->x));
            a_biti(r, 0x4000);
            if (r->z) {
                a_lda(r, RAM16(0x0099 + r->x));
                a_eor(r, RAM16(0x02C9));
                a_and(r, 0x0003);
                if (!r->z) skip = true;
            }
            if (!skip) {
                a_lda(r, RAM16(0x0098 + r->x));
                a_biti(r, 0x2000);
                if (r->z) {
                    a_lda(r, RAM16(0x0094 + r->x));
                    if (!r->z) {
                        a_lda(r, RAM16(0xCFFF));
                        a_biti(r, 0x0001);
                        if (!r->z) skip = true;
                        else {
                            a_lda(r, RAM16(0x1D04));
                            a_biti(r, 0x0040);
                            if (!r->z) skip = true;
                        }
                    }
                    if (!skip) {
                        JSR(c, 0x0E18, 0xC20E9B); /* store_three_party_relative_distances_and_direction_bits */
                        JSR(c, 0x0E1B, 0xC20F27); /* resolve_boss_contacts_combat_and_publish_counter_request */
                        a_ldx(r, dp_rd16(c, 0x87));
                    }
                }
            }
            if (!skip) {
                JSR(c, 0x0E20, 0xC20F83); /* advance_boss_object_counters_and_dispatch_definition */
                a_ldx(r, dp_rd16(c, 0x87));
                if (r->c) {
                    if (r->mf) RAM8(0x0000 + r->x) = 0; else RAM16_SET(0x0000 + r->x, 0);
                    if (r->mf) RAM8(0x008C + r->x) = 0; else RAM16_SET(0x008C + r->x, 0);
                    i_plx(c);
                    i_sep(r, 0x20);
                    if (r->mf) RAM8(0x0E60 + r->x) = 0; else RAM16_SET(0x0E60 + r->x, 0);
                    done = true;
                } else {
                    JSR(c, 0x0E35, 0xC20E42); /* snapshot_boss_camera_and_tick_enabled_animation */
                }
            }
            if (!done) {
                i_plx(c);
                i_sep(r, 0x20);
            }
        }
        i_inx(r);
        REQUIRE_X16(c);
        a_cpx(r, 0x0009);
    } while (!r->z);
    i_rep(r, 0x20);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20DB2, SOM_RTS, "hand", update_nine_boss_actor_slots_combat_definition_and_animation, 0, L_X | L_Y | L_C | L_V, 2, -1, -1, 144, 64)
