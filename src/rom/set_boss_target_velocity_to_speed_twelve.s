; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_target_velocity_from_normalized_displacement = $3313

.segment "CODE"
.org $560B
set_boss_target_velocity_to_speed_twelve:
    .a16
    lda #$000C
    jsr derive_boss_target_velocity_from_normalized_displacement
    rts
