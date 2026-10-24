; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_menu_single_window = $1D24
upload_menu_title_and_padding = $1D52
upload_menu_two_row_window = $1CDE

.segment "CODE"
.org $1CBE
upload_menu_window_and_title:
    lda a:$1D11
    .a8
    and #$04
    beq upload_menu_window_and_title_c01cc8
    jsr upload_menu_title_and_padding
upload_menu_window_and_title_c01cc8:
    lda a:$1D04
    .a8
    and #$02
    beq upload_menu_window_and_title_c01cdd
    jsr upload_menu_two_row_window
    jsr upload_menu_single_window
    lda a:$1D04
    .a8
    and #$F5
    sta a:$1D04
upload_menu_window_and_title_c01cdd:
    rts
