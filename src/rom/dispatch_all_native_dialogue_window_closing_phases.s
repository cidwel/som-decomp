; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0611
dispatch_all_native_dialogue_window_closing_phases:
    .a8
    lda #$00
    xba
    lda a:$A15E
    asl
    tax
    lda f:$001D05
    .a8
    cmp #$07
    beq dispatch_all_native_dialogue_window_closing_phases_c00626
    jsr ($10D0,X)
    bra dispatch_all_native_dialogue_window_closing_phases_c00629
dispatch_all_native_dialogue_window_closing_phases_c00626:
    jsr ($10A4,X)
dispatch_all_native_dialogue_window_closing_phases_c00629:
    rts
