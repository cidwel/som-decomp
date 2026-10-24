; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_pattern_rows_left = $F804
shift_map_pattern_rows_right = $F817

.segment "CODE"
.org $F7CF
expand_and_upload_map_pattern_record:
    sep #$20
    .i8
    ldx #$10
    .i8
    ldy #$00
    jsr rotate_map_pattern_rows_left
    .i8
    ldx #$10
    .i8
    ldy #$20
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    jsr shift_map_pattern_rows_right
    .a8
    lda #$00
    sta f:$004372
    .a8
    lda #$90
    sta f:$004375
    .a8
    lda #$80
    sta f:$00420B
    rts
