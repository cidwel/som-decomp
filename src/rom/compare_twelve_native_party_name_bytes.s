; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5181
compare_twelve_native_party_name_bytes:
    rep #$20
    lda a:$A22B
    .a16
    and #$00FF
    asl
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tax
    lda a:$A175
    .a16
    and #$00FF
    dec
    asl
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tay
    sep #$20
    .a8
    lda #$0C
    sta a:$A1D0
compare_twelve_native_party_name_bytes_c751ad:
    lda a:$CC00,Y
    cmp a:$CC00,X
    beq compare_twelve_native_party_name_bytes_c751ba
    .a8
    lda #$01
    sta a:$A171
compare_twelve_native_party_name_bytes_c751ba:
    inx
    iny
    dec a:$A1D0
    bne compare_twelve_native_party_name_bytes_c751ad
    rts
