; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-poll.md.
.setcpu "65816"
.smart
.a8
.i16

read_game_controller_words_through_native_multi5_bios = $CFFE00
routine_00bdbb = $BDBB

.segment "CODE"
.org $951C
detect_controller_interface_change_and_reassign_first_player:
    php
    jsl f:read_game_controller_words_through_native_multi5_bios
    plp
    .a8
    and #$FF
    beq detect_controller_interface_change_and_reassign_first_player_c09527
detect_controller_interface_change_and_reassign_first_player_c09526:
    rts
detect_controller_interface_change_and_reassign_first_player_c09527:
    lda $DB
    beq detect_controller_interface_change_and_reassign_first_player_c09526
    stz $DB
    .a8
    and #$06
    xba
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$10
    .a8
    lda #$00
    tax
    stz a:$E02C,X
    stz a:$E08C,X
    plb
    lda $DA
    ora $D9
    bne detect_controller_interface_change_and_reassign_first_player_c09526
    sep #$30
    .i8
    ldx #$00
    jsl f:routine_00bdbb
    rts
