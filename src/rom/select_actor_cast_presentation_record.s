; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $86D1
select_actor_cast_presentation_record:
    sep #$20
    lda a:$E111,X
    xba
    lda a:$E170,X
    rep #$20
    pha
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    asl
    asl
    sta $18
    pla
    sep #$20
    xba
    .a8
    cmp #$88
    bne select_actor_cast_presentation_record_c186f4
    .a8
    lda #$30
    bra select_actor_cast_presentation_record_c186ff
select_actor_cast_presentation_record_c186f4:
    rep #$20
    .a16
    and #$000E
    asl
    asl
    clc
    .a16
    adc #$0008
select_actor_cast_presentation_record_c186ff:
    rep #$20
    .a16
    and #$003F
    ora $18
    rts
