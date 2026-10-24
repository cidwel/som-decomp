; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $12FF
dispatch_native_dialogue_window_completion_phase:
    .a8
    lda #$00
    xba
    lda f:$001D05
    .a8
    cmp #$07
    beq dispatch_native_dialogue_window_completion_phase_c01314
    lda a:$A15F
    asl
    tax
    jsr ($10BE,X)
    bra dispatch_native_dialogue_window_completion_phase_c01321
dispatch_native_dialogue_window_completion_phase_c01314:
    .a8
    lda #$01
    sta a:$A16F
    lda a:$A15C
    asl
    tax
    jsr ($1098,X)
dispatch_native_dialogue_window_completion_phase_c01321:
    rts
