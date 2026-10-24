; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-poll.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_button_mappings_to_three_controller_words = $9434
detect_controller_interface_change_and_reassign_first_player = $951C
transfer_controller_reset_hotkey_to_cold_boot = $93B3

.segment "CODE"
.org $93B9
poll_three_controller_words_and_publish_pressed_edges:
    sep #$20
    jsr detect_controller_interface_change_and_reassign_first_player
    rep #$20
    lda $42
    .a16
    bit #$000F
    beq poll_three_controller_words_and_publish_pressed_edges_c093c9
    stz $42
poll_three_controller_words_and_publish_pressed_edges_c093c9:
    .a16
    cmp #$3030
    beq transfer_controller_reset_hotkey_to_cold_boot
    lda $44
    .a16
    bit #$000F
    beq poll_three_controller_words_and_publish_pressed_edges_c093d7
    stz $44
poll_three_controller_words_and_publish_pressed_edges_c093d7:
    .a16
    cmp #$3030
    beq transfer_controller_reset_hotkey_to_cold_boot
    lda $46
    .a16
    bit #$000F
    beq poll_three_controller_words_and_publish_pressed_edges_c093e5
    stz $46
poll_three_controller_words_and_publish_pressed_edges_c093e5:
    .a16
    cmp #$3030
    beq transfer_controller_reset_hotkey_to_cold_boot
    jsr apply_native_button_mappings_to_three_controller_words
    lda $47
    lsr
    lsr
    lsr
    lsr
    ora $46
    sta $02
    lda $45
    lsr
    lsr
    lsr
    lsr
    ora $44
    sta $01
    lda $43
    lsr
    lsr
    lsr
    lsr
    ora $42
    sta $00
    eor $E9
    and $00
    ora $CC
    sta $CC
    lda $01
    eor $EA
    and $01
    ora $CD
    sta $CD
    lda $02
    eor $EB
    and $02
    ora $CE
    sta $CE
    lda $00
    sta $E9
    lda $01
    sta $EA
    lda $02
    sta $EB
    rts
