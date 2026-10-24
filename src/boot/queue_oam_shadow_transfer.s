; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_transfer_descriptor = $8FC7
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $B804
queue_oam_shadow_transfer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02CC
    beq queue_oam_shadow_transfer_b83c
    .a8
    lda #$FF
    xba
    .a8
    lda #$04
    jsr allocate_transfer_descriptor
    .i16
    cpx #$0000
    beq queue_oam_shadow_transfer_b83c
    .a8
    lda #$7F
    sta a:$0004,X
    rep #$20
    lda a:$02CC
    sta a:$0002,X
    .a16
    lda #$0220
    sta a:$0005,X
    stz a:$000A,X
    sep #$20
    jsr submit_transfer_or_program_hdma
queue_oam_shadow_transfer_b83c:
    plb
    plp
    pld
    rts
