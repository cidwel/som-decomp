; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_death_palettes_graphics_and_selected_actor = $0B14

.segment "CODE"
.org $0AFD
begin_boss_death_initialization_when_control_and_lock_clear:
    ldx $87
    lda a:$0060,X
    .a16
    and #$00FF
    bne begin_boss_death_initialization_when_control_and_lock_clear_c20b12
    lda a:$004C,X
    bne begin_boss_death_initialization_when_control_and_lock_clear_c20b12
    inc a:$0094,X
    jsr prepare_boss_death_palettes_graphics_and_selected_actor
begin_boss_death_initialization_when_control_and_lock_clear_c20b12:
    clc
    rts
