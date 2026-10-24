; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-projectile-child.md.
.setcpu "65816"
.smart
.a8
.i16

seed_sixteen_direction_spell_velocity_animation_and_sound = $9AF7

.segment "CODE"
.org $9AE5
advance_directional_spell_after_initial_animation:
    ldx $87
    lda a:$009E,X
    bne advance_directional_spell_after_initial_animation_c29af5
    inc a:$0094,X
    stz a:$000B,X
    jsr seed_sixteen_direction_spell_velocity_animation_and_sound
advance_directional_spell_after_initial_animation_c29af5:
    clc
    rts
