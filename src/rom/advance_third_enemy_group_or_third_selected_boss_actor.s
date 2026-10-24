; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-enemy-group-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_selected_actor_frame_or_public_boss_pool = $FD07
tail_dispatch_ordinary_enemy_animation_step = $FD1F

.segment "CODE"
.org $FCDE
advance_third_enemy_group_or_third_selected_boss_actor:
    rep #$10
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    bit $ED
    bpl advance_third_enemy_group_or_third_selected_boss_actor_c0fcf3
    .i16
    ldx #$0A00
    jsr advance_selected_actor_frame_or_public_boss_pool
    plb
    rts
advance_third_enemy_group_or_third_selected_boss_actor_c0fcf3:
    .i16
    ldx #$1200
    jsr tail_dispatch_ordinary_enemy_animation_step
    .i16
    ldx #$1400
    jsr tail_dispatch_ordinary_enemy_animation_step
    .i16
    ldx #$1600
    jsr tail_dispatch_ordinary_enemy_animation_step
    plb
    rts
