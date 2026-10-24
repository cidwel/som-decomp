; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

expand_and_upload_map_pattern_record = $F7CF

.segment "CODE"
.org $F767
upload_map_expanded_pattern_sets:
    sep #$10
    rep #$20
    .a16
    lda #$0080
    sta a:$4375
    .a16
    lda #$4000
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    .a16
    lda #$7F00
    sta a:$4372
    .a16
    lda #$1801
    sta a:$4370
    .i8
    ldx #$D2
    stx a:$4374
    .i8
    ldx #$80
    stx a:$2115
    .a16
    lda #$0300
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    .a16
    lda #$FF00
    sta a:$4372
    .i8
    ldx #$7F
    stx a:$4374
    phb
    phx
    plb
    .i8
    ldy #$08
    sty $02
    .i8
    ldx #$00
upload_map_expanded_pattern_sets_c1f7b1:
    rep #$20
    .i8
    ldy #$00
upload_map_expanded_pattern_sets_c1f7b5:
    lda f:$D27E70,X
    sta a:$FF10,Y
    inx
    inx
    iny
    iny
    .i8
    cpy #$10
    bcc upload_map_expanded_pattern_sets_c1f7b5
    phx
    jsr expand_and_upload_map_pattern_record
    plx
    dec $02
    bne upload_map_expanded_pattern_sets_c1f7b1
    plb
    rts
