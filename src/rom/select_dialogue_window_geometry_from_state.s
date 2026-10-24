; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0D8B
select_dialogue_window_geometry_from_state:
    phb
    .a8
    lda #$C7
    pha
    plb
    .a8
    lda #$00
    xba
    lda f:$7EA162
    asl
    tax
    lda a:$7147,X
    xba
    lda a:$7148,X
    tay
    lda a:$7153,X
    sta f:$001D1A
    lda a:$7154,X
    sta f:$001D1B
    lda f:$7EA162
    .a8
    cmp #$02
    bne select_dialogue_window_geometry_from_state_c00dc2
    rep #$20
    .a16
    lda #$0500
    sta f:$001D1A
    sep #$20
select_dialogue_window_geometry_from_state_c00dc2:
    lda f:$7EA170
    .a8
    cmp #$51
    beq select_dialogue_window_geometry_from_state_c00de5
    rep #$20
    lda a:$714D,X
    sta f:$7EA169
    lda a:$7141,X
    sta f:$7EA196
    sep #$20
    lda a:$7135,X
    xba
    lda a:$7136,X
    bra select_dialogue_window_geometry_from_state_c00dec
select_dialogue_window_geometry_from_state_c00de5:
    lda a:$713B,X
    xba
    lda a:$713C,X
select_dialogue_window_geometry_from_state_c00dec:
    plb
    rep #$20
    pha
    tya
    xba
    sta a:$A163
    sta a:$A16B
    pla
    sep #$20
    rts
