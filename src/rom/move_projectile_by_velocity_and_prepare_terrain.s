; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7

.segment "CODE"
.org $3F4C
move_projectile_by_velocity_and_prepare_terrain:
    lda a:$002B,X
    clc
    adc a:$003C,X
    sta a:$002B,X
    lda a:$0032,X
    clc
    adc a:$0040,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    rts
