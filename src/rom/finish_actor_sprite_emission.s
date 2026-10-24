; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_and_emit_actor_body_sprites = $E5CE

.segment "CODE"
.org $E8C6
finish_actor_sprite_emission:
    sep #$20
    ldx $14
    .i16
    cpx #$0600
    bcc finish_actor_sprite_emission_c0e8d3
    bit $5C
    bmi finish_actor_sprite_emission_c0e8d6
finish_actor_sprite_emission_c0e8d3:
    brl prepare_and_emit_actor_body_sprites
finish_actor_sprite_emission_c0e8d6:
    rts
