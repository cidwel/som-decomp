; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AB03
apply_map_header_transition_flags:
    pha
    .a8
    and #$1F
    sta $80
    pla
    xba
    lda $E8
    .a8
    cmp #$83
    beq apply_map_header_transition_flags_c2ab2d
    lda a:$011F
    rep #$20
    sta a:$011E
    .a16
    and #$2020
    beq apply_map_header_transition_flags_c2ab2d
    .a16
    cmp #$2020
    beq apply_map_header_transition_flags_c2ab2d
    .a16
    eor #$0020
    beq apply_map_header_transition_flags_c2ab2a
    lda a:$010E
apply_map_header_transition_flags_c2ab2a:
    sta a:$0108
apply_map_header_transition_flags_c2ab2d:
    sep #$20
    rtl
