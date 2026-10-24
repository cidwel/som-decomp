; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

request_dialogue_transfer_and_conditional_window_flags = $0FFA

.segment "CODE"
.org $1BC0
exchange_dialogue_tilemap_entry_and_request_upload:
    phb
    phy
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$00
    xba
    lda a:$A156
    dec
    rep #$20
    asl
    asl
    asl
    asl
    asl
    adc a:$A157
    asl
    clc
    .a16
    adc #$9C00
    tay
    lda a:$0000,Y
    pha
    txa
    .a16
    eor #$2000
    sta a:$0000,Y
    pla
    .a16
    and #$DFFF
    tax
    sep #$20
    ply
    plb
    .a8
    lda #$44
    jsr request_dialogue_transfer_and_conditional_window_flags
    rts
