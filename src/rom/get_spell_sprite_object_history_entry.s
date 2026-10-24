; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EFAE
get_spell_sprite_object_history_entry:
    phd
    php
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    phx
    clc
    adc $01,S
    clc
    .a16
    adc #$0050
    ply
    tay
    plp
    pld
    rts
