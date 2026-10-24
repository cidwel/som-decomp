; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8898
prepare_actor_cast_directional_offset:
    sep #$20
    .a8
    lda #$00
    xba
    lda a:$E010,X
    rep #$20
    beq prepare_actor_cast_directional_offset_c188bd
    bmi prepare_actor_cast_directional_offset_c188ae
    dec
    beq prepare_actor_cast_directional_offset_c188b8
    .a16
    lda #$0018
    bra prepare_actor_cast_directional_offset_c188b1
prepare_actor_cast_directional_offset_c188ae:
    .a16
    lda #$FFE8
prepare_actor_cast_directional_offset_c188b1:
    sta a:$E118,X
    stz a:$E11A,X
    rts
prepare_actor_cast_directional_offset_c188b8:
    .a16
    lda #$0018
    bra prepare_actor_cast_directional_offset_c188c0
prepare_actor_cast_directional_offset_c188bd:
    .a16
    lda #$FFE8
prepare_actor_cast_directional_offset_c188c0:
    sta a:$E11A,X
    stz a:$E118,X
    rts
