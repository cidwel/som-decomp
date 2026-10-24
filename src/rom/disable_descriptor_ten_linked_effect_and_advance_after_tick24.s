; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $7A6B
disable_descriptor_ten_linked_effect_and_advance_after_tick24:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcs disable_descriptor_ten_linked_effect_and_advance_after_tick24_c27a7a
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
disable_descriptor_ten_linked_effect_and_advance_after_tick24_c27a7a:
    stz a:$00A7,X
    inc a:$0094,X
    clc
    rts
