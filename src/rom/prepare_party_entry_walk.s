; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

place_party_at_bottom_entry = $DE87
place_party_at_left_entry = $DEAF
place_party_at_right_entry = $DECD
place_party_at_top_entry = $DE69
set_party_diagonal_entry_walk = $DE27

.segment "CODE"
.org $DD66
prepare_party_entry_walk:
    sep #$20
    rep #$10
    ldx $D4
    lda $E8
    .a8
    and #$03
    bne prepare_party_entry_walk_c1ddac
    lda $E1
    bne prepare_party_entry_walk_c1dd77
    rts
prepare_party_entry_walk_c1dd77:
    pha
    .a8
    lda #$20
    sta $FF
    pla
    .a8
    cmp #$05
    bcs prepare_party_entry_walk_c1dda9
    lda $E0
    bmi prepare_party_entry_walk_c1dd91
    lda a:$E010,X
    bmi prepare_party_entry_walk_c1dda6
    beq prepare_party_entry_walk_c1dd95
    lsr
    bcs prepare_party_entry_walk_c1dd9c
    bcc prepare_party_entry_walk_c1dda3
prepare_party_entry_walk_c1dd91:
    .a8
    and #$60
    bne prepare_party_entry_walk_c1dd98
prepare_party_entry_walk_c1dd95:
    brl place_party_at_bottom_entry
prepare_party_entry_walk_c1dd98:
    .a8
    cmp #$20
    bne prepare_party_entry_walk_c1dd9f
prepare_party_entry_walk_c1dd9c:
    brl place_party_at_top_entry
prepare_party_entry_walk_c1dd9f:
    .a8
    cmp #$40
    bne prepare_party_entry_walk_c1dda6
prepare_party_entry_walk_c1dda3:
    brl place_party_at_left_entry
prepare_party_entry_walk_c1dda6:
    brl place_party_at_right_entry
prepare_party_entry_walk_c1dda9:
    brl set_party_diagonal_entry_walk
prepare_party_entry_walk_c1ddac:
    .a8
    and #$02
    bne prepare_party_entry_walk_c1ddb4
    .a8
    lda #$28
    bra prepare_party_entry_walk_c1ddb6
prepare_party_entry_walk_c1ddb4:
    .a8
    lda #$A8
prepare_party_entry_walk_c1ddb6:
    sta a:$E00F
    sta a:$E20F
    sta a:$E40F
    lda $D5
    beq prepare_party_entry_walk_c1dded
    .a8
    cmp #$02
    beq prepare_party_entry_walk_c1ddda
    .a8
    lda #$82
    sta a:$E206
    sta a:$E006
    .a8
    lda #$08
    sta a:$E00A
    .a8
    lda #$12
    sta a:$E20A
    rts
prepare_party_entry_walk_c1ddda:
    .a8
    lda #$82
    sta a:$E406
    sta a:$E006
    .a8
    lda #$08
    sta a:$E00A
    .a8
    lda #$12
    sta a:$E40A
    rts
prepare_party_entry_walk_c1dded:
    .a8
    lda #$82
    sta a:$E206
    sta a:$E406
    .a8
    lda #$08
    sta a:$E40A
    .a8
    lda #$12
    sta a:$E20A
    rts
