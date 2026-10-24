; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-party-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5217
dispatch_native_name_page_party_icon_variant:
    .a8
    lda #$00
    xba
    lda a:$A22B
    asl
    tax
    jsr ($5223,X)
    rtl
