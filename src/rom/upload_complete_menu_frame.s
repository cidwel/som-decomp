; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_menu_text_or_clear = $1C1A
upload_menu_window_and_title = $1CBE

.segment "CODE"
.org $1BF7
upload_complete_menu_frame:
    php
    sep #$20
    rep #$10
    phb
    .a8
    lda #$00
    pha
    plb
    jsr upload_menu_window_and_title
    jsr upload_menu_text_or_clear
    lda a:$1D05
    .a8
    cmp #$07
    bne upload_complete_menu_frame_c01c12
    .a8
    lda #$5A
    bra upload_complete_menu_frame_c01c14
upload_complete_menu_frame_c01c12:
    .a8
    lda #$5E
upload_complete_menu_frame_c01c14:
    trb a:$1D04
    plb
    plp
    rtl
