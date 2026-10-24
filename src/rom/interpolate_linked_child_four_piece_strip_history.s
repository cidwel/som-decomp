; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

shift_linked_child_signed_word_right_once = $5EC3

.segment "CODE"
.org $5EC9
interpolate_linked_child_four_piece_strip_history:
    ldx $87
    lda a:$007A,X
    xba
    asl
    sta $06
    lda a:$00B6,X
    dec
    bpl interpolate_linked_child_four_piece_strip_history_c25edb
    .a16
    lda #$000F
interpolate_linked_child_four_piece_strip_history_c25edb:
    asl
    asl
    sta $08
    lda a:$00B8,X
    sta $00
    lda a:$00BA,X
    sta $02
    stz $0A
    bra interpolate_linked_child_four_piece_strip_history_c25f03
interpolate_linked_child_four_piece_strip_history_c25eed:
    lda $0A
    dec
    xba
    lsr
    lsr
    clc
    adc $06
    adc $08
    tay
    lda a:$F500,Y
    sta $00
    lda a:$F502,Y
    sta $02
interpolate_linked_child_four_piece_strip_history_c25f03:
    lda $0A
    inc
    .a16
    cmp #$0004
    bne interpolate_linked_child_four_piece_strip_history_c25f1b
    lda $00
    jsr shift_linked_child_signed_word_right_once
    sta $00
    lda $02
    jsr shift_linked_child_signed_word_right_once
    sta $02
    bra interpolate_linked_child_four_piece_strip_history_c25f3a
interpolate_linked_child_four_piece_strip_history_c25f1b:
    xba
    lsr
    lsr
    clc
    adc $06
    adc $08
    tay
    lda a:$F500,Y
    clc
    adc $00
    jsr shift_linked_child_signed_word_right_once
    sta $00
    lda a:$F502,Y
    clc
    adc $02
    jsr shift_linked_child_signed_word_right_once
    sta $02
interpolate_linked_child_four_piece_strip_history_c25f3a:
    lda $0A
    xba
    lsr
    lsr
    sta $04
    lda a:$00B6,X
    asl
    asl
    clc
    adc $04
    adc $06
    tay
    lda $00
    sta a:$F500,Y
    lda $02
    sta a:$F502,Y
    inc $0A
    lda $0A
    .a16
    cmp #$0004
    bne interpolate_linked_child_four_piece_strip_history_c25eed
    rts
