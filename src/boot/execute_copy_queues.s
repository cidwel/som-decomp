; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

execute_copy_queue_record = $C985
release_copy_queue_record = $C93A

.segment "CODE"
.org $C9E5
execute_copy_queues:
    phd
    php
    rep #$30
    phb
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    ldx #$02FA
execute_copy_queues_c9f9:
    lda a:$0000,X
    .a16
    and #$00FF
    beq execute_copy_queues_ca0d
    clc
    adc a:$02F6
    tax
    phx
    jsr execute_copy_queue_record
    plx
    bra execute_copy_queues_c9f9
execute_copy_queues_ca0d:
    .i16
    ldx #$02FE
    lda a:$0000,X
    .a16
    and #$00FF
    beq execute_copy_queues_ca2f
execute_copy_queues_ca18:
    clc
    adc a:$02F6
    tax
    phx
    jsr execute_copy_queue_record
    plx
    lda a:$0000,X
    pha
    jsr release_copy_queue_record
    pla
    .a16
    and #$00FF
    bne execute_copy_queues_ca18
execute_copy_queues_ca2f:
    stz a:$02FE
    .a16
    lda #$02FE
    sta a:$0300
    plb
    sep #$20
    pla
    pla
    pla
    plp
    pld
    rts
