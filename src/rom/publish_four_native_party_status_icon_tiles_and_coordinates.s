; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $63C5
publish_four_native_party_status_icon_tiles_and_coordinates:
    rep #$20
    lda a:$A17E
    clc
    .a16
    adc #$1848
    sta a:$9C02,X
    inc
    sta a:$9C06,X
    inc
    sta a:$9C0A,X
    inc
    sta a:$9C0E,X
    lda a:$A159
    sta a:$9C00,X
    clc
    .a16
    adc #$0008
    sta a:$9C04,X
    clc
    .a16
    adc #$0800
    sta a:$9C0C,X
    sec
    .a16
    sbc #$0008
    sta a:$9C08,X
    txa
    sec
    .a16
    sbc #$0010
    tax
    sep #$20
    rts
