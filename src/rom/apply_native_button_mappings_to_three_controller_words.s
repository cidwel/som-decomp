; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-mapping.md.
.setcpu "65816"
.smart
.a8
.i16

permute_native_controller_button_bits = $9476

.segment "CODE"
.org $9434
apply_native_button_mappings_to_three_controller_words:
    sep #$30
    ldx $EE
    beq apply_native_button_mappings_to_three_controller_words_c0944b
    lda $43
    ora $42
    beq apply_native_button_mappings_to_three_controller_words_c0944b
    lda $43
    ldy $42
    jsr permute_native_controller_button_bits
    sta $43
    sty $42
apply_native_button_mappings_to_three_controller_words_c0944b:
    ldx $EF
    beq apply_native_button_mappings_to_three_controller_words_c09460
    lda $45
    ora $44
    beq apply_native_button_mappings_to_three_controller_words_c09460
    lda $45
    ldy $44
    jsr permute_native_controller_button_bits
    sta $45
    sty $44
apply_native_button_mappings_to_three_controller_words_c09460:
    ldx $F0
    beq apply_native_button_mappings_to_three_controller_words_c09475
    lda $47
    ora $46
    beq apply_native_button_mappings_to_three_controller_words_c09475
    lda $47
    ldy $46
    jsr permute_native_controller_button_bits
    sta $47
    sty $46
apply_native_button_mappings_to_three_controller_words_c09475:
    rts
