; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

derive_low_byte_target_manhattan_distance = $08E3

.segment "CODE"
.org $08D9
derive_target_manhattan_distance_in_sixteen_pixel_units:
    jsr derive_low_byte_target_manhattan_distance
    sta $99
    lsr
    lsr
    lsr
    lsr
    rts
