; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

hold_boss_target_with_control_a4 = $620D

.segment "CODE"
.org $52B7
place_boss_target_at_boss_and_set_control_if_idle:
    jsr hold_boss_target_with_control_a4
    lda a:$002B,X
    sta a:$0002,Y
    lda a:$0032,X
    sta a:$0004,Y
    lda a:$0190,Y
    bne place_boss_target_at_boss_and_set_control_if_idle_c252ee
    sep #$20
    lda a:$0060,Y
    bne place_boss_target_at_boss_and_set_control_if_idle_c252ec
    lda a:$000E,Y
    bne place_boss_target_at_boss_and_set_control_if_idle_c252ec
    lda a:$01E5,Y
    .a8
    lda #$24
    sta a:$01E5,Y
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
place_boss_target_at_boss_and_set_control_if_idle_c252ec:
    rep #$20
place_boss_target_at_boss_and_set_control_if_idle_c252ee:
    rts
