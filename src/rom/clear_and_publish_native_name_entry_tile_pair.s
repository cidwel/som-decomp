; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5119
clear_and_publish_native_name_entry_tile_pair:
    rep #$20
    .a16
    lda #$0000
    sta a:$A1A0
    sta a:$A1A2
    rep #$20
    lda a:$A156
    .a16
    and #$00FF
    xba
    lsr
    lsr
    clc
    adc a:$A157
    tax
    lda a:$A1A0
    sta a:$9000,X
    lda a:$A1A2
    sta a:$9040,X
    sep #$20
    .a8
    lda #$02
    tsb a:$A20A
    rtl
