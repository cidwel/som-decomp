; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

request_dialogue_transfer_and_conditional_window_flags = $0FFA

.segment "CODE"
.org $0229
dispatch_all_native_dialogue_window_construction_phases:
    tyx
    inx
    lda f:$001D03
    phb
    pha
    plb
    lda a:$0000,X
    plb
    .a8
    lda #$00
    xba
    lda a:$A15C
    asl
    tax
    lda f:$001D05
    .a8
    cmp #$07
    beq dispatch_all_native_dialogue_window_construction_phases_c0024b
    jsr ($10C4,X)
    bra dispatch_all_native_dialogue_window_construction_phases_c00260
dispatch_all_native_dialogue_window_construction_phases_c0024b:
    lda a:$A162
    bne dispatch_all_native_dialogue_window_construction_phases_c00255
    .a8
    lda #$01
    sta a:$A162
dispatch_all_native_dialogue_window_construction_phases_c00255:
    stz a:$A16F
    jsr ($10A8,X)
    .a8
    lda #$20
    jsr request_dialogue_transfer_and_conditional_window_flags
dispatch_all_native_dialogue_window_construction_phases_c00260:
    rts
