; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7303
select_alive_hero_nearest_on_vertical_axis:
    lda a:$0032,X
    sta $95
    .a16
    lda #$07FF
    sta $97
    stz $99
    .i16
    ldy #$0000
select_alive_hero_nearest_on_vertical_axis_c27312:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne select_alive_hero_nearest_on_vertical_axis_c2733d
    lda a:$0190,X
    bmi select_alive_hero_nearest_on_vertical_axis_c2733d
    lda a:$0004,X
    sec
    sbc $95
    bpl select_alive_hero_nearest_on_vertical_axis_c27335
    eor $C7
    inc
select_alive_hero_nearest_on_vertical_axis_c27335:
    cmp $97
    bcs select_alive_hero_nearest_on_vertical_axis_c2733d
    sta $97
    sty $99
select_alive_hero_nearest_on_vertical_axis_c2733d:
    iny
    .i16
    cpy #$0003
    bcc select_alive_hero_nearest_on_vertical_axis_c27312
    ldx $87
    lda $99
    sta a:$00A9,X
    rts
