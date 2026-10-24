; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $B20B
take_record_link:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    beq take_record_link_b236
    .i16
    cpx #$FFFF
    beq take_record_link_b232
    lda a:$0000,X
    pha
    phx
    jsr current_task_id
    .a16
    and #$00FF
    plx
    sta a:$0000,X
    pla
    bra take_record_link_b236
take_record_link_b232:
    .i16
    ldx #$0000
    txa
take_record_link_b236:
    plb
    plp
    pld
    rts
