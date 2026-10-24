; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-operands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D503
derive_actor_animation_sound_volume:
    beq derive_actor_animation_sound_volume_c1d517
    lda a:$E020,X
    .a8
    and #$F0
    sta a:$0118
    phy
    ldy a:$E10C,X
    lda a:$E020,X
    ply
    bra derive_actor_animation_sound_volume_c1d51f
derive_actor_animation_sound_volume_c1d517:
    lda a:$E020,X
    .a8
    and #$F0
    sta a:$0118
derive_actor_animation_sound_volume_c1d51f:
    lsr
    lsr
    lsr
    lsr
    ora a:$0118
    sta a:$0119
    rts
