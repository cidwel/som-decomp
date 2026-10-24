; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FD52
configure_map_backgrounds:
    sep #$30
    .a8
    lda #$09
    sta $29
    sta a:$2105
    .a8
    lda #$51
    sta a:$2107
    .a8
    lda #$39
    sta a:$2108
    lda $E8
    lsr
    .a8
    lda #$58
    bcc configure_map_backgrounds_c1fd6e
    .a8
    lda #$5C
configure_map_backgrounds_c1fd6e:
    sta a:$2109
    stz a:$210A
    .a8
    lda #$00
    .a8
    and #$F0
    sta $02
    lsr
    lsr
    lsr
    lsr
    ora $02
    sta a:$210B
    .a8
    lda #$40
    lsr
    lsr
    lsr
    lsr
    sta a:$210C
    lda $B8
    .a8
    and #$F8
    .a8
    cmp #$F8
    beq configure_map_backgrounds_c1fd95
    rts
configure_map_backgrounds_c1fd95:
    .a8
    lda #$07
    sta $29
    sta a:$2105
    .a8
    lda #$01
    stz a:$211B
    sta a:$211B
    stz a:$211C
    stz a:$211C
    stz a:$211D
    stz a:$211D
    stz a:$211E
    sta a:$211E
    cli
    rts
