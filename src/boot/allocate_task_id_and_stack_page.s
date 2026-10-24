; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_initial_task_stack = $AA42

.segment "CODE"
.org $AA77
allocate_task_id_and_stack_page:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0003
    tcd
    tcs
    lda $04,S
    sep #$20
    sty $04
    sta $01
    stx $02
    .i16
    ldx #$00AA
    .i16
    ldy #$0014
allocate_task_id_and_stack_page_aa93:
    lda a:$0000,X
    beq allocate_task_id_and_stack_page_aaa1
    inx
    dey
    bne allocate_task_id_and_stack_page_aa93
    .i16
    ldx #$0000
    bra allocate_task_id_and_stack_page_aacc
allocate_task_id_and_stack_page_aaa1:
    lda $01
    sta a:$0000,X
    tya
    sec
    .a8
    sbc #$17
    .a8
    eor #$FF
    ldx $02
    sta a:$0004,X
    dec
    xba
    .a8
    lda #$00
    rep #$20
    clc
    .a16
    adc #$01F6
    sta a:$0006,X
    sec
    .a16
    sbc #$00F6
    tax
    ldy $04
    jsr prepare_initial_task_stack
    sep #$20
    ldx $02
allocate_task_id_and_stack_page_aacc:
    rep #$20
    tsc
    clc
    .a16
    adc #$0005
    tcs
    plp
    pld
    rts
