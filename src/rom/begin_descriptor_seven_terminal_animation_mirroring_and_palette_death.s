; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_death_palettes_graphics_and_selected_actor = $0B14
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $727D
begin_descriptor_seven_terminal_animation_mirroring_and_palette_death:
    ldx $87
    lda a:$0060,X
    .a16
    and #$00FF
    bne begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272bf
    inc a:$0094,X
    .a16
    lda #$010A
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$007E,X
    bne begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272a0
    lda a:$0098,X
    .a16
    and #$FB3F
    sta a:$0098,X
    bra begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272ac
begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272a0:
    lda a:$0098,X
    .a16
    and #$FB3F
    .a16
    ora #$0040
    sta a:$0098,X
begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272ac:
    sep #$20
    lda a:$0019,X
    sta a:$0018,X
    stz a:$0019,X
    stz a:$001A,X
    rep #$20
    jsr prepare_boss_death_palettes_graphics_and_selected_actor
begin_descriptor_seven_terminal_animation_mirroring_and_palette_death_c272bf:
    clc
    rts
