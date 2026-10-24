; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

select_pending_map_column_edges = $C908

pending_column_flags = $2F

.segment "CODE"
.org $C8EF
prepare_pending_map_columns:
    sep #$30
    lda pending_column_flags
    beq prepare_pending_map_columns_c0c8f9
    .a8
    cmp #$C0
    bcc prepare_pending_map_columns_c0c8fa
prepare_pending_map_columns_c0c8f9:
    rts
prepare_pending_map_columns_c0c8fa:
    tax
    phb
    .a8
    lda #$7F
    pha
    plb
    txa
    jsr select_pending_map_column_edges
    sep #$20
    plb
    rts
