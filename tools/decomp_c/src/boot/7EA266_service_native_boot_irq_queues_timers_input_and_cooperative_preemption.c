#include "som_c.h"
#include "som_hand_d.h"

/* 7EA266 service_native_boot_irq_queues_timers_input_and_cooperative_preemption   [class D, 133 bytes, 67 instructions]
 * Source: src/boot/service_native_boot_irq_queues_timers_input_and_cooperative_preemption.s
 * Documented in docs/boot-native-active-irq.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
/* D = $4200 in the interrupt handler: direct page accesses are hardware registers, absolute ones are bank $7F */
static void service_native_boot_irq_queues_timers_input_and_cooperative_preemption(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_sep(r, 0x20);
    i_phb(c);
    i_pha(c);
    a_lda(r, 0x7F);
    i_pha(c);
    i_plb(c);
    i_pla(c);
    i_rep(r, 0x20);
    i_pha(c);
    i_phx(c);
    i_phy(c);
    a_lda(r, 0x4200);
    i_tcd(r);
    i_sep(r, 0x20);
    a_lda(r, RAM8(0x1008C));
    if (!r->z) {
        a_lda(r, dp_rd8(c, 0x11)); /* TIMEUP: acknowledge the IRQ */
        a_lda(r, RAM8(0x10090));
        a_ora(r, 0x80);
        RAM8(0x10090) = r->a;
        dp_wr8(c, 0x00, r->a); /* NMITIMEN */
        JSR(c, 0xA294, 0x7EB804); /* queue_oam_shadow_transfer */
        JSR(c, 0xA297, 0x7E9164); /* prepare_transfer_pass */
        JSR(c, 0xA29A, 0x7EC0C2); /* count_ppu_queue_entries */
        i_pha(c);
        JSR(c, 0xA29E, 0x7ECCB7); /* tick_timer_registrations */
        REQUIRE_M8(c);
        do { /* wait for the NMI flag */
            a_lda(r, dp_rd8(c, 0x10));
            a_and(r, 0x80);
        } while (r->z);
        a_lda(r, dp_rd8(c, 0x10)); /* RDNMI: acknowledge */
        a_lda(r, 0x00);
        i_xba(r);
        i_pla(c);
        i_asla(r);
        JSR(c, 0xA2AE, 0x7E91B8); /* program_dma_descriptor_pass */
        JSR(c, 0xA2B1, 0x7EC0FD); /* write_ppu_queue_entries */
        JSR(c, 0xA2B4, 0x7EC9E5); /* execute_copy_queues */
        JSR(c, 0xA2B7, 0x7E92E9); /* cleanup_processed_transfers */
        JSR(c, 0xA2BA, 0x7EC18B); /* apply_ppu_queue_shadow */
        JSR(c, 0xA2BD, 0x7ECD05); /* finish_timer_suffix */
        JSR(c, 0xA2C0, 0x7EA6FF); /* update_controller_states_and_messages */
        JSR(c, 0xA2C3, 0x7EA9C7); /* reap_one_completed_task */
        a_lda(r, dp_rd8(c, 0x10));
        a_lda(r, dp_rd8(c, 0x11));
        REQUIRE_M8(c);
        a_lda(r, RAM8(0x10090));
        a_and(r, 0x7F);
        RAM8(0x10090) = r->a;
        dp_wr8(c, 0x00, r->a);
        JSR(c, 0xA2D4, 0x7EAC44); /* preempt_native_current_task_and_resume_its_pending_message */
        REQUIRE_X16(c);
        a_cpx(r, 0x0000);
        if (!r->z) {
            i_phx(c);
            JSR(c, 0xA2DD, 0x7EACE9); /* current_task_id */
            i_plx(c);
            JSR(c, 0xA2E1, 0x7EB2AB); /* prepend_pending_record */
        }
    }
    i_rep(r, 0x20);
    i_ply(c);
    i_plx(c);
    i_pla(c);
    i_plb(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTI(c);
}
SOM_REGISTER(0x7EA266, SOM_RTI, "hand", service_native_boot_irq_queues_timers_input_and_cooperative_preemption, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 13, -1, 0, 133, 67)
