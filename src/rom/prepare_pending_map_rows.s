; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_queued_map_row = $C820
select_pending_map_row_edges = $C7E3

pending_row_flags = $2E
queued_row_flags = $82

.segment "CODE"
.org $C7C3
prepare_pending_map_rows:
    sep #$30
    lda pending_row_flags
    beq prepare_pending_map_rows_c0c7ce
    .a8
    cmp #$C0
    bcc prepare_pending_map_rows_c0c7d5
prepare_pending_map_rows_c0c7cd:
    rts
prepare_pending_map_rows_c0c7ce:
    lda queued_row_flags
    beq prepare_pending_map_rows_c0c7cd
    brl prepare_queued_map_row
prepare_pending_map_rows_c0c7d5:
    tax
    phb
    .a8
    lda #$7F
    pha
    plb
    txa
    jsr select_pending_map_row_edges
    sep #$20
    plb
    rts
