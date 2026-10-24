; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $90B7
append_one_merged_actor_effect_piece:
    sep #$20
    lda a:$E114,Y
    bne append_one_merged_actor_effect_piece_c190c5
    lda a:$E110,Y
    .a8
    cmp #$03
    beq append_one_merged_actor_effect_piece_c190c6
append_one_merged_actor_effect_piece_c190c5:
    rts
append_one_merged_actor_effect_piece_c190c6:
    lda a:$E113,Y
    .a8
    cmp #$50
    bcs append_one_merged_actor_effect_piece_c190c5
    tya
    beq append_one_merged_actor_effect_piece_c190f6
    .a8
    cmp #$10
    beq append_one_merged_actor_effect_piece_c190e5
    lda a:$C000,X
    sec
    .a8
    sbc #$08
    sta a:$C000,X
    lda a:$C001,X
    clc
    .a8
    adc #$08
    bra append_one_merged_actor_effect_piece_c190fc
append_one_merged_actor_effect_piece_c190e5:
    lda a:$C000,X
    clc
    .a8
    adc #$08
    sta a:$C000,X
    lda a:$C001,X
    clc
    .a8
    adc #$05
    bra append_one_merged_actor_effect_piece_c190fc
append_one_merged_actor_effect_piece_c190f6:
    lda a:$C001,X
    sec
    .a8
    sbc #$08
append_one_merged_actor_effect_piece_c190fc:
    sta a:$C001,X
    inc $02
    inx
    inx
    inx
    inx
    rts
