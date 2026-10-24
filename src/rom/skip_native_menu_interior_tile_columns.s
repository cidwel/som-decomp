; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2523
skip_native_menu_interior_tile_columns:
    lda a:$A16C
    .a16
    and #$00FF
    asl
    stx a:$A173
    clc
    adc a:$A173
    tax
    rts
