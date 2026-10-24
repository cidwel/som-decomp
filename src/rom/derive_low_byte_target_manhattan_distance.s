; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

derive_actor_manhattan_distance_from_selected_boss = $08F1

.segment "CODE"
.org $08E3
derive_low_byte_target_manhattan_distance:
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    jsr derive_actor_manhattan_distance_from_selected_boss
    rts
