; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

copy_far_stack_arguments = $C44E

.segment "CODE"
.org $C985
execute_copy_queue_record:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    lda a:$0004,X
    .a16
    and #$00FF
    bne execute_copy_queue_record_c99b
    .a16
    lda #$0100
execute_copy_queue_record_c99b:
    .a16
    cmp #$0004
    bcs execute_copy_queue_record_c9be
    sta $01
    lda a:$0001,X
    sta $02
    sep #$20
    lda a:$0003,X
    sta $04
    .i16
    ldy #$0000
execute_copy_queue_record_c9b1:
    lda a:$0005,X
    sta [$02],Y
    inx
    iny
    dec $01
    bne execute_copy_queue_record_c9b1
    bra execute_copy_queue_record_c9de
execute_copy_queue_record_c9be:
    pha
    ldy a:$0005,X
    phy
    sep #$20
    lda a:$0007,X
    pha
    ldy a:$0001,X
    phy
    lda a:$0003,X
    pha
    jsr copy_far_stack_arguments
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    sep #$20
execute_copy_queue_record_c9de:
    pla
    pla
    pla
    pla
    plp
    pld
    rts
