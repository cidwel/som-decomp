; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

release_eight_byte_record = $B1DD

.segment "CODE"
.org $B16F
release_records_held_by_task:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    .a16
    and #$00FF
    sta $01
    .i16
    ldy #$0100
    ldx a:$02C4
release_records_held_by_task_b18e:
    lda a:$0000,X
    cmp $01
    bne release_records_held_by_task_b198
    jsr release_eight_byte_record
release_records_held_by_task_b198:
    clc
    txa
    .a16
    adc #$0008
    tax
    dey
    bne release_records_held_by_task_b18e
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
