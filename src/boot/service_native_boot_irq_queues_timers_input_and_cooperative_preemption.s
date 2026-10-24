; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-active-irq.md.
.setcpu "65816"
.smart
.a8
.i16

apply_ppu_queue_shadow = $C18B
cleanup_processed_transfers = $92E9
count_ppu_queue_entries = $C0C2
current_task_id = $ACE9
execute_copy_queues = $C9E5
finish_timer_suffix = $CD05
preempt_native_current_task_and_resume_its_pending_message = $AC44
prepare_transfer_pass = $9164
prepend_pending_record = $B2AB
program_dma_descriptor_pass = $91B8
queue_oam_shadow_transfer = $B804
reap_one_completed_task = $A9C7
tick_timer_registrations = $CCB7
update_controller_states_and_messages = $A6FF
write_ppu_queue_entries = $C0FD

.segment "CODE"
.org $A266
service_native_boot_irq_queues_timers_input_and_cooperative_preemption:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    pha
    phx
    phy
    .a16
    lda #$4200
    tcd
    sep #$20
    lda a:$008C
    bne service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a286
    jmp service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a2e2
service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a286:
    lda $11
    lda a:$0090
    .a8
    ora #$80
    sta a:$0090
    sta $00
    jsr queue_oam_shadow_transfer
    jsr prepare_transfer_pass
    jsr count_ppu_queue_entries
    pha
    jsr tick_timer_registrations
service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a29f:
    lda $10
    .a8
    and #$80
    beq service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a29f
    lda $10
    .a8
    lda #$00
    xba
    pla
    asl
    jsr program_dma_descriptor_pass
    jsr write_ppu_queue_entries
    jsr execute_copy_queues
    jsr cleanup_processed_transfers
    jsr apply_ppu_queue_shadow
    jsr finish_timer_suffix
    jsr update_controller_states_and_messages
    jsr reap_one_completed_task
    lda $10
    lda $11
    lda a:$0090
    .a8
    and #$7F
    sta a:$0090
    sta $00
    jsr preempt_native_current_task_and_resume_its_pending_message
    .i16
    cpx #$0000
    beq service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a2e2
    phx
    jsr current_task_id
    plx
    jsr prepend_pending_record
service_native_boot_irq_queues_timers_input_and_cooperative_preemption_a2e2:
    rep #$20
    ply
    plx
    pla
    plb
    plp
    pld
    rti
