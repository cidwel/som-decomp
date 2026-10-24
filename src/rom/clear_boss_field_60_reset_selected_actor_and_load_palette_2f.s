; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963
copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $5586
clear_boss_field_60_reset_selected_actor_and_load_palette_2f:
    stz a:$0060,X
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    .a16
    lda #$002F
    .i16
    ldx #$000D
    jsr copy_boss_palette_with_cpu_words
    .a16
    lda #$002F
    .i16
    ldx #$000E
    jsr copy_boss_palette_with_cpu_words
    rts
