; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $31C9
terminate_boss_death_explosion_when_animation_timer_zero:
    ldx $87
    lda a:$009E,X
    beq terminate_boss_death_explosion_when_animation_timer_zero_c231d2
    clc
    rts
terminate_boss_death_explosion_when_animation_timer_zero_c231d2:
    sec
    rts
