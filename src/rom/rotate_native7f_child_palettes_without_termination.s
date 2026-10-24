; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_four_words_in_each_of_two_native7f_palette_groups = $98A1

.segment "CODE"
.org $989C
rotate_native7f_child_palettes_without_termination:
    jsr rotate_four_words_in_each_of_two_native7f_palette_groups
    clc
    rts
