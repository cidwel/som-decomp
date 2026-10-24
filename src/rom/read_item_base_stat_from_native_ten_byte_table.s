; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D9DE
read_item_base_stat_from_native_ten_byte_table:
    rep #$30
    phx
    .a16
    and #$003F
    asl
    pha
    asl
    asl
    clc
    adc $01,S
    tax
    pla
    lda f:$D03ED1,X
    .a16
    and #$00FF
    plx
    rts
