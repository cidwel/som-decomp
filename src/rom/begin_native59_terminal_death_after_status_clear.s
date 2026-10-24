; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_death_palettes_graphics_and_selected_actor = $0B14

.segment "CODE"
.org $8817
begin_native59_terminal_death_after_status_clear:
    ldx $87
    lda a:$0060,X
    .a16
    and #$00FF
    bne begin_native59_terminal_death_after_status_clear_c28827
    inc a:$0094,X
    jsr prepare_boss_death_palettes_graphics_and_selected_actor
begin_native59_terminal_death_after_status_clear_c28827:
    clc
    rts
