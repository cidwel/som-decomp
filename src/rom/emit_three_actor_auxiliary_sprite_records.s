; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_one_actor_auxiliary_sprite_record = $C3E5

.segment "CODE"
.org $C3C1
emit_three_actor_auxiliary_sprite_records:
    phx
    rep #$20
    txa
    lsr
    lsr
    lsr
    tay
    clc
    .a16
    adc #$0010
    pha
    jsr emit_one_actor_auxiliary_sprite_record
    rep #$20
    pla
    tay
    clc
    .a16
    adc #$0010
    pha
    jsr emit_one_actor_auxiliary_sprite_record
    rep #$20
    ply
    jsr emit_one_actor_auxiliary_sprite_record
    plx
    rtl
