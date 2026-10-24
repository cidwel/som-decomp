; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4E35
replace_previous_body_segment_shape:
    lda a:$00B2,X
    beq replace_previous_body_segment_shape_c24e4e
    sep #$20
    lda a:$0000,Y
    .a8
    and #$0F
    lsr
    tax
    lda f:$DCE633,X
    sta a:$0000,Y
    rep #$20
    ldx $87
replace_previous_body_segment_shape_c24e4e:
    rts
