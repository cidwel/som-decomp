; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $41F6
build_mode_seven_transition_hdma_line_records:
    .i16
    ldx #$1000
    .i16
    ldy #$1020
    lda $4A
    .a8
    cmp #$80
    bcs build_mode_seven_transition_hdma_line_records_c64215
    sta $00,X
    sta a:$0000,Y
    stz $01,X
    lda $48
    sta a:$0001,Y
    lda $49
    sta a:$0002,Y
    bra build_mode_seven_transition_hdma_line_records_c6423c
build_mode_seven_transition_hdma_line_records_c64215:
    .a8
    sbc #$7F
    sta $00,X
    sta a:$0000,Y
    stz $01,X
    .a8
    lda #$7F
    sta $02,X
    sta a:$0003,Y
    stz $03,X
    lda $48
    sta a:$0001,Y
    sta a:$0004,Y
    lda $49
    sta a:$0002,Y
    sta a:$0005,Y
    inx
    inx
    iny
    iny
    iny
build_mode_seven_transition_hdma_line_records_c6423c:
    .a8
    lda #$E0
    sec
    sbc $4A
    .a8
    cmp #$80
    bcs build_mode_seven_transition_hdma_line_records_c6425d
    sta $02,X
    sta a:$0003,Y
    stz $03,X
    .a8
    lda #$00
    sta a:$0004,Y
    sta a:$0005,Y
    stz $04,X
    .a8
    lda #$00
    sta a:$0006,Y
    bra build_mode_seven_transition_hdma_line_records_c64284
build_mode_seven_transition_hdma_line_records_c6425d:
    .a8
    sbc #$7F
    sta $02,X
    sta a:$0003,Y
    stz $03,X
    .a8
    lda #$7F
    sta $04,X
    sta a:$0006,Y
    stz $05,X
    .a8
    lda #$00
    sta a:$0004,Y
    sta a:$0005,Y
    sta a:$0007,Y
    sta a:$0008,Y
    stz $06,X
    .a8
    lda #$00
    sta a:$0009,Y
build_mode_seven_transition_hdma_line_records_c64284:
    rts
