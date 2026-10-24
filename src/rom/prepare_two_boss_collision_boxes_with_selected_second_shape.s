; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $06FE
prepare_two_boss_collision_boxes_with_selected_second_shape:
    lda a:$00CA,X
    ora a:$00CE,X
    bne prepare_two_boss_collision_boxes_with_selected_second_shape_c20708
    sec
    rts
prepare_two_boss_collision_boxes_with_selected_second_shape_c20708:
    lda a:$002B,X
    sta $5E
    lda a:$0066,X
    lsr
    .a16
    eor #$FFFF
    inc
    clc
    adc a:$0032,X
    sta $60
    lda a:$0066,X
    sta $62
    txy
    sep #$20
    .i16
    ldx #$0000
prepare_two_boss_collision_boxes_with_selected_second_shape_c20726:
    lda a:$00C8,Y
    sta $46,X
    bpl prepare_two_boss_collision_boxes_with_selected_second_shape_c20733
    .a8
    lda #$FF
    sta $47,X
    bra prepare_two_boss_collision_boxes_with_selected_second_shape_c20735
prepare_two_boss_collision_boxes_with_selected_second_shape_c20733:
    stz $47,X
prepare_two_boss_collision_boxes_with_selected_second_shape_c20735:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_two_boss_collision_boxes_with_selected_second_shape_c20726
    ldy $87
    .i16
    ldx #$0000
prepare_two_boss_collision_boxes_with_selected_second_shape_c20742:
    lda a:$00CC,Y
    sta $4E,X
    bpl prepare_two_boss_collision_boxes_with_selected_second_shape_c2074f
    .a8
    lda #$FF
    sta $4F,X
    bra prepare_two_boss_collision_boxes_with_selected_second_shape_c20751
prepare_two_boss_collision_boxes_with_selected_second_shape_c2074f:
    stz $4F,X
prepare_two_boss_collision_boxes_with_selected_second_shape_c20751:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_two_boss_collision_boxes_with_selected_second_shape_c20742
    rep #$20
    lda $5E
    clc
    adc $46
    sta $46
    lda $60
    clc
    adc $48
    sta $48
    lda $5E
    clc
    adc $4E
    sta $4E
    lda $60
    clc
    adc $50
    sta $50
    clc
    rts
