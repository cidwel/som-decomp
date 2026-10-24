; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E382
advance_actor_sprite_visibility_timer:
    dec
    dec
    sta a:$E00F,X
    bmi advance_actor_sprite_visibility_timer_c0e38c
    .a8
    cmp #$01
    rts
advance_actor_sprite_visibility_timer_c0e38c:
    clc
    rts
