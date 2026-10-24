; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_actor_cast_radial_target_presentation = $8A61
select_actor_cast_presentation_record = $86D1

.segment "CODE"
.org $8B82
prepare_actor_cast_three_target_presentation:
    rep #$20
    lda a:$E118,X
    clc
    .a16
    adc #$0008
    sta a:$E128,X
    sec
    .a16
    sbc #$0010
    sta a:$E138,X
    lda a:$E11A,X
    clc
    .a16
    adc #$0005
    sta a:$E12A,X
    .a16
    adc #$0003
    sta a:$E13A,X
    sec
    .a16
    sbc #$0010
    sta a:$E11A,X
    stz a:$E11C,X
    txy
    jsr select_actor_cast_presentation_record
    tax
    sep #$20
    lda f:$D02AA1,X
    tyx
    pha
    sta a:$E110,X
    sta a:$E120,X
    sta a:$E130,X
    lda a:$E111,X
    .a8
    and #$0F
    .a8
    cmp #$08
    bne prepare_actor_cast_three_target_presentation_c18bd2
    .a8
    lda #$40
    tsb $F1
prepare_actor_cast_three_target_presentation_c18bd2:
    lda a:$E179,X
    bne prepare_actor_cast_three_target_presentation_c18bdd
    lda a:$E178,X
    sta a:$E179,X
prepare_actor_cast_three_target_presentation_c18bdd:
    lda a:$E17A,X
    bne prepare_actor_cast_three_target_presentation_c18be8
    lda a:$E178,X
    sta a:$E17A,X
prepare_actor_cast_three_target_presentation_c18be8:
    lda a:$E178,X
    .a8
    and #$07
    dec
    asl
    sta a:$E117,X
    stz a:$E116,X
    lda a:$E179,X
    .a8
    and #$07
    dec
    asl
    sta a:$E127,X
    stz a:$E126,X
    lda a:$E17A,X
    .a8
    and #$07
    dec
    asl
    sta a:$E137,X
    stz a:$E136,X
    pla
    bne prepare_actor_cast_three_target_presentation_c18c2e
prepare_actor_cast_three_target_presentation_c18c12:
    lda a:$E178,X
    cmp a:$E17A,X
    bne prepare_actor_cast_three_target_presentation_c18c1f
    .a8
    lda #$80
    sta a:$E137,X
prepare_actor_cast_three_target_presentation_c18c1f:
    lda a:$E178,X
    cmp a:$E179,X
    bne prepare_actor_cast_three_target_presentation_c18c2c
    .a8
    lda #$80
    sta a:$E127,X
prepare_actor_cast_three_target_presentation_c18c2c:
    clc
    rts
prepare_actor_cast_three_target_presentation_c18c2e:
    .a8
    cmp #$04
    bne prepare_actor_cast_three_target_presentation_c18c35
    brl prepare_actor_cast_radial_target_presentation
prepare_actor_cast_three_target_presentation_c18c35:
    bcs prepare_actor_cast_three_target_presentation_c18c12
    .a8
    lda #$05
    sta a:$E114,X
    .a8
    lda #$0F
    sta a:$E124,X
    .a8
    lda #$19
    sta a:$E134,X
    .a8
    lda #$70
    sta a:$E115,X
    sta a:$E125,X
    sta a:$E135,X
    stz a:$E113,X
    stz a:$E123,X
    stz a:$E133,X
    lda a:$E010,X
    bmi prepare_actor_cast_three_target_presentation_c18c73
    beq prepare_actor_cast_three_target_presentation_c18c81
    .a8
    cmp #$01
    beq prepare_actor_cast_three_target_presentation_c18c85
    .a8
    lda #$C0
    sta a:$E112,X
    .a8
    lda #$00
    sta a:$E122,X
    .a8
    lda #$40
    bra prepare_actor_cast_three_target_presentation_c18c91
prepare_actor_cast_three_target_presentation_c18c73:
    .a8
    lda #$C0
    sta a:$E112,X
    .a8
    lda #$40
    sta a:$E122,X
    .a8
    lda #$80
    bra prepare_actor_cast_three_target_presentation_c18c91
prepare_actor_cast_three_target_presentation_c18c81:
    .a8
    lda #$C0
    bra prepare_actor_cast_three_target_presentation_c18c87
prepare_actor_cast_three_target_presentation_c18c85:
    .a8
    lda #$40
prepare_actor_cast_three_target_presentation_c18c87:
    sta a:$E112,X
    .a8
    lda #$00
    sta a:$E122,X
    .a8
    lda #$80
prepare_actor_cast_three_target_presentation_c18c91:
    sta a:$E132,X
    sec
    rts
