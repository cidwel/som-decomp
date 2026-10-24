; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8A61
prepare_actor_cast_radial_target_presentation:
    lda a:$E137,X
    cmp a:$E117,X
    bne prepare_actor_cast_radial_target_presentation_c18a6c
    stz a:$E130,X
prepare_actor_cast_radial_target_presentation_c18a6c:
    lda a:$E127,X
    cmp a:$E117,X
    bne prepare_actor_cast_radial_target_presentation_c18a77
    stz a:$E120,X
prepare_actor_cast_radial_target_presentation_c18a77:
    rep #$20
    lda a:$E110,X
    sta a:$E120,X
    sta a:$E130,X
    stz a:$E12E,X
    stz a:$E11E,X
    stz a:$E13C,X
    .a16
    lda #$0008
    sta a:$E12C,X
    .a16
    lda #$0010
    sta a:$E11C,X
    stz a:$E112,X
    .a16
    lda #$0404
    sta a:$E122,X
    sta a:$E132,X
    stz a:$E124,X
    lda a:$E118,X
    sta a:$E128,X
    sta a:$E138,X
    lda a:$E12A,X
    sta a:$E11A,X
    txa
    lsr
    tay
    .a16
    lda #$0010
    sta $00
    .a16
    lda #$CB00
prepare_actor_cast_radial_target_presentation_c18ac0:
    sta a:$C060,Y
    iny
    iny
    dec $00
    bne prepare_actor_cast_radial_target_presentation_c18ac0
    sep #$20
    .a8
    lda #$00
    xba
    lda a:$E010,X
    rep #$20
    beq prepare_actor_cast_radial_target_presentation_c18b00
    bmi prepare_actor_cast_radial_target_presentation_c18aed
    dec
    beq prepare_actor_cast_radial_target_presentation_c18b13
    lda a:$E118,X
    clc
    .a16
    adc #$000C
    sta a:$E128,X
    clc
    .a16
    adc #$0012
    sta a:$E138,X
    bra prepare_actor_cast_radial_target_presentation_c18b24
prepare_actor_cast_radial_target_presentation_c18aed:
    lda a:$E118,X
    sec
    .a16
    sbc #$000C
    sta a:$E128,X
    sec
    .a16
    sbc #$0012
    sta a:$E138,X
    bra prepare_actor_cast_radial_target_presentation_c18b24
prepare_actor_cast_radial_target_presentation_c18b00:
    lda a:$E11A,X
    sec
    .a16
    sbc #$000C
    sta a:$E12A,X
    sec
    .a16
    sbc #$0012
    sta a:$E13A,X
    bra prepare_actor_cast_radial_target_presentation_c18b24
prepare_actor_cast_radial_target_presentation_c18b13:
    lda a:$E11A,X
    clc
    .a16
    adc #$000C
    sta a:$E12A,X
    clc
    .a16
    adc #$0012
    sta a:$E13A,X
prepare_actor_cast_radial_target_presentation_c18b24:
    sec
    rts
