; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

choose_native59_distinct_color_and_publish_status_palette_sound = $8528
consume_native59_status_and_enter_hurt_phase = $857D
move_native59_one_step_toward_farthest_party_target = $8597

.segment "CODE"
.org $84FC
wait_native59_distance_or_refresh_variant_zero_palette:
    ldx $87
    jsr consume_native59_status_and_enter_hurt_phase
    bcs wait_native59_distance_or_refresh_variant_zero_palette_c28523
    lda a:$00AD,X
    cmp a:$002D,X
    bcc wait_native59_distance_or_refresh_variant_zero_palette_c28510
    inc a:$0094,X
    clc
    rts
wait_native59_distance_or_refresh_variant_zero_palette_c28510:
    lda a:$0042,X
    bne wait_native59_distance_or_refresh_variant_zero_palette_c28523
    lda a:$00B6,X
    .a16
    cmp #$0001
    bcc wait_native59_distance_or_refresh_variant_zero_palette_c28523
    stz a:$00B6,X
    jsr choose_native59_distinct_color_and_publish_status_palette_sound
wait_native59_distance_or_refresh_variant_zero_palette_c28523:
    jsr move_native59_one_step_toward_farthest_party_target
    clc
    rts
