; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_map_expanded_pattern_sets = $F767

.segment "CODE"
.org $F69B
initialize_map_fixed_graphics:
    sep #$30
    rep #$20
    .a16
    lda #$0000
    sta $00
    .a16
    lda #$0000
    sta a:$4372
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$1809
    sta a:$4370
    .a16
    lda #$1000
    sta a:$4375
    .i8
    ldx #$80
    stx a:$2115
    .a16
    lda #$5800
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    jsr upload_map_expanded_pattern_sets
    sep #$20
    lda $E8
    lsr
    bcs initialize_map_fixed_graphics_c1f6d6
    rts
initialize_map_fixed_graphics_c1f6d6:
    sep #$10
    rep #$20
    .a16
    lda #$6C00
    sta a:$4372
    .a16
    lda #$1801
    sta a:$4370
    .a16
    lda #$0800
    sta a:$4375
    .i8
    ldx #$C6
    stx a:$4374
    .i8
    ldx #$80
    stx a:$2115
    .a16
    lda #$4900
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    rts
