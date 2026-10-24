; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_death_palettes_graphics_and_selected_actor = $0B14
release_selected_party_control_without_palette_or_music = $EFBE

.segment "CODE"
.org $7A56
begin_descriptor_ten_terminal_release_and_death_preparation:
    ldx $87
    lda a:$0060,X
    .a16
    and #$00FF
    bne begin_descriptor_ten_terminal_release_and_death_preparation_c27a69
    inc a:$0094,X
    jsr release_selected_party_control_without_palette_or_music
    jsr prepare_boss_death_palettes_graphics_and_selected_actor
begin_descriptor_ten_terminal_release_and_death_preparation_c27a69:
    clc
    rts
