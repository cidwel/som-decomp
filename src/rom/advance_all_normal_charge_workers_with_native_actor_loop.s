; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-frame-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_charge_status_and_offscreen_retention_worker = $FBB0

.segment "CODE"
.org $FB8F
advance_all_normal_charge_workers_with_native_actor_loop:
    rep #$10
    sep #$20
    .i16
    ldx #$0A00
    bit $ED
    bmi advance_all_normal_charge_workers_with_native_actor_loop_c0fb9d
    .i16
    ldx #$1600
advance_all_normal_charge_workers_with_native_actor_loop_c0fb9d:
    phx
    jsr advance_actor_charge_status_and_offscreen_retention_worker
    rep #$30
    plx
    txa
    sec
    .a16
    sbc #$0200
    tax
    .i16
    cpx #$0600
    bcs advance_all_normal_charge_workers_with_native_actor_loop_c0fb9d
    rts
