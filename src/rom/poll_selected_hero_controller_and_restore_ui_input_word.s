; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

poll_three_controller_words_and_publish_pressed_edges = $93B9

.segment "CODE"
.org $87E0
poll_selected_hero_controller_and_restore_ui_input_word:
    sep #$20
    rep #$10
    ldx $D4
    lda f:$7EE02C,X
    .a8
    bit #$02
    bne poll_selected_hero_controller_and_restore_ui_input_word_c087f8
    .a8
    bit #$04
    beq poll_selected_hero_controller_and_restore_ui_input_word_c087fc
    lda $CC
    sta $CE
    bra poll_selected_hero_controller_and_restore_ui_input_word_c087fc
poll_selected_hero_controller_and_restore_ui_input_word_c087f8:
    lda $CC
    sta $CD
poll_selected_hero_controller_and_restore_ui_input_word_c087fc:
    jsr poll_three_controller_words_and_publish_pressed_edges
    sep #$20
    rep #$10
    ldx $D4
    lda f:$7EE02C,X
    .a8
    bit #$02
    bne poll_selected_hero_controller_and_restore_ui_input_word_c0881e
    .a8
    bit #$04
    beq poll_selected_hero_controller_and_restore_ui_input_word_c0881d
    lda $CE
    sta $CC
    lda $46
    sta $42
    lda $47
    sta $43
poll_selected_hero_controller_and_restore_ui_input_word_c0881d:
    rts
poll_selected_hero_controller_and_restore_ui_input_word_c0881e:
    lda $CD
    sta $CC
    lda $44
    sta $42
    lda $45
    sta $43
    rts
