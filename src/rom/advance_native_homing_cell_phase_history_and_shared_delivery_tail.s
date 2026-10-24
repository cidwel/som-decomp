; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c18952 = $8952

.segment "CODE"
.org $8B26
advance_native_homing_cell_phase_history_and_shared_delivery_tail:
    rep #$20
    lda a:$E113,X
    .a16
    and #$007F
    bne advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b31
    rts
advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b31:
    clc
    adc a:$E11C,X
    .a16
    and #$003F
    sta a:$E11C,X
    lda a:$E12C,X
    clc
    adc a:$E123,X
    .a16
    and #$003F
    sta a:$E12C,X
    lda a:$E13C,X
    clc
    adc a:$E133,X
    .a16
    and #$003F
    sta a:$E13C,X
    sep #$20
    lda a:$E132,X
    sta a:$E133,X
    lda a:$E123,X
    sta a:$E132,X
    lda a:$E122,X
    sta a:$E123,X
    lda a:$E113,X
    sta a:$E122,X
    lda a:$E124,X
    beq advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b7e
    dec
    sta a:$E124,X
    beq advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b7f
    .a8
    cmp #$02
    beq advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b7f
advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b7e:
    rts
advance_native_homing_cell_phase_history_and_shared_delivery_tail_c18b7f:
    brl routine_c18952
