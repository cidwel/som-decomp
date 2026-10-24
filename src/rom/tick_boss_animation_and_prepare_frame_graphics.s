; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

interpret_boss_animation_commands_until_frame_record = $13EB
prepare_boss_animation_frame_geometry_and_collision = $1C37
prepare_boss_animation_graphics_cache_by_mode = $1A81

.segment "CODE"
.org $13AD
tick_boss_animation_and_prepare_frame_graphics:
    lda a:$0098,X
    bpl tick_boss_animation_and_prepare_frame_graphics_c213d0
    sep #$20
    .a8
    lda #$C1
    sta $78
    lda a:$009E,X
    beq tick_boss_animation_and_prepare_frame_graphics_c213c5
    dec a:$009E,X
    bne tick_boss_animation_and_prepare_frame_graphics_c213c5
    jsr interpret_boss_animation_commands_until_frame_record
tick_boss_animation_and_prepare_frame_graphics_c213c5:
    rep #$20
    jsr prepare_boss_animation_graphics_cache_by_mode
    jsr prepare_boss_animation_frame_geometry_and_collision
    rep #$20
    rts
tick_boss_animation_and_prepare_frame_graphics_c213d0:
    sep #$20
    .a8
    lda #$C1
    sta $78
    lda a:$009E,X
    beq tick_boss_animation_and_prepare_frame_graphics_c213e8
    dec a:$009E,X
    bne tick_boss_animation_and_prepare_frame_graphics_c213e8
    jsr interpret_boss_animation_commands_until_frame_record
    rep #$20
    jsr prepare_boss_animation_frame_geometry_and_collision
tick_boss_animation_and_prepare_frame_graphics_c213e8:
    rep #$20
    rts
