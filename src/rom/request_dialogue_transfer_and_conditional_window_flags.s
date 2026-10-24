; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0FFA
request_dialogue_transfer_and_conditional_window_flags:
    phb
    xba
    .a8
    lda #$00
    pha
    plb
    xba
    pha
    tsb a:$1D12
    pla
    xba
    lda a:$1D05
    .a8
    cmp #$07
    beq request_dialogue_transfer_and_conditional_window_flags_c0101e
    lda f:$7EA187
    .a8
    bit #$01
    bne request_dialogue_transfer_and_conditional_window_flags_c0101e
    lda f:$7EA162
    .a8
    cmp #$01
    beq request_dialogue_transfer_and_conditional_window_flags_c01022
request_dialogue_transfer_and_conditional_window_flags_c0101e:
    xba
    tsb a:$1D04
request_dialogue_transfer_and_conditional_window_flags_c01022:
    plb
    rts
