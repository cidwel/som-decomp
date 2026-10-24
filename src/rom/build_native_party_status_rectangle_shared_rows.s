; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6B31
build_native_party_status_rectangle_shared_rows:
    sty a:$A171
build_native_party_status_rectangle_shared_rows_c76b34:
    ldy a:$A173
    phx
build_native_party_status_rectangle_shared_rows_c76b38:
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    inx
    inx
    inc
    inc
    dey
    bne build_native_party_status_rectangle_shared_rows_c76b38
    tay
    pla
    clc
    .a16
    adc #$0080
    tax
    tya
    dec a:$A171
    bne build_native_party_status_rectangle_shared_rows_c76b34
    rts
