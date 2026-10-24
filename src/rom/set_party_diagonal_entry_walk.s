; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DE27
set_party_diagonal_entry_walk:
    rep #$10
    .i16
    ldy #$8200
    .a8
    cmp #$0B
    beq set_party_diagonal_entry_walk_c1de4f
    .i16
    ldy #$0200
    .a8
    cmp #$0C
    beq set_party_diagonal_entry_walk_c1de4f
    .i16
    ldy #$0282
    .a8
    cmp #$0D
    beq set_party_diagonal_entry_walk_c1de4f
    .i16
    ldy #$8202
    .a8
    cmp #$0E
    beq set_party_diagonal_entry_walk_c1de4f
    .i16
    ldy #$0202
    .a8
    cmp #$0F
    beq set_party_diagonal_entry_walk_c1de4f
    .i16
    ldy #$8282
set_party_diagonal_entry_walk_c1de4f:
    rep #$20
    tya
    sta a:$E006
    sta a:$E206
    sta a:$E406
    sep #$20
    .a8
    lda #$0C
    sta a:$E00A
    sta a:$E20A
    sta a:$E40A
    rts
