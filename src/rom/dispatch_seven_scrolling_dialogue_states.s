; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0900
dispatch_seven_scrolling_dialogue_states:
    phb
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$7D
    sta a:$A170
    .a8
    lda #$01
    sta f:$001D11
    .a8
    lda #$00
    xba
    lda a:$A161
    asl
    tax
    jsr ($0B61,X)
    plb
    rtl
