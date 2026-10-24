; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DD55
copy_map_object_record_to_cache:
    .i16
    ldy #$0000
    rep #$20
    lda [$0D],Y
    sta a:$C808,X
    iny
    iny
    lda [$0D],Y
    sta a:$C80A,X
    pha
    iny
    iny
    lda [$0D],Y
    sta a:$C80C,X
    iny
    iny
    lda [$0D],Y
    sta a:$C80E,X
    pla
    sep #$20
    lsr
    sta $00
    xba
    .a8
    and #$80
    ora $00
    .a8
    and #$C0
    sta a:$C807,X
    .a8
    lda #$01
    sta a:$C800,X
    rts
