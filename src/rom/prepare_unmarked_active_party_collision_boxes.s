; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $07C7
prepare_unmarked_active_party_collision_boxes:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0000,Y
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne prepare_unmarked_active_party_collision_boxes_c20853
    sep #$20
    ldx $24
    lda f:$C205F0,X
    ldx $87
    and a:$005A,X
    rep #$20
    bne prepare_unmarked_active_party_collision_boxes_c20853
    lda a:$0002,Y
    sta $5E
    lda a:$0004,Y
    sta $60
    lda a:$0045,Y
    asl
    sta $62
    phy
    sep #$20
    .i16
    ldx #$0000
prepare_unmarked_active_party_collision_boxes_c20801:
    lda a:$00C8,Y
    sta $46,X
    bpl prepare_unmarked_active_party_collision_boxes_c2080e
    .a8
    lda #$FF
    sta $47,X
    bra prepare_unmarked_active_party_collision_boxes_c20810
prepare_unmarked_active_party_collision_boxes_c2080e:
    stz $47,X
prepare_unmarked_active_party_collision_boxes_c20810:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_unmarked_active_party_collision_boxes_c20801
    ply
    .i16
    ldx #$0000
prepare_unmarked_active_party_collision_boxes_c2081c:
    lda a:$00CC,Y
    sta $4E,X
    bpl prepare_unmarked_active_party_collision_boxes_c20829
    .a8
    lda #$FF
    sta $4F,X
    bra prepare_unmarked_active_party_collision_boxes_c2082b
prepare_unmarked_active_party_collision_boxes_c20829:
    stz $4F,X
prepare_unmarked_active_party_collision_boxes_c2082b:
    inx
    inx
    iny
    .i16
    cpx #$0008
    bne prepare_unmarked_active_party_collision_boxes_c2081c
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
prepare_unmarked_active_party_collision_boxes_c20853:
    sec
    rts
