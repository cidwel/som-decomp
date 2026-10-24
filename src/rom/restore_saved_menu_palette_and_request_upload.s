; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

request_menu_palette_upload = $CDA9

.segment "CODE"
.org $CD6D
restore_saved_menu_palette_and_request_upload:
    rep #$30
    .i16
    ldx #$0000
    lda f:$7E8000,X
    sta a:$0600,X
    .i16
    ldx #$0020
restore_saved_menu_palette_and_request_upload_d0cd7c:
    lda f:$7E8000,X
    sta a:$0600,X
    inx
    inx
    .i16
    cpx #$0100
    bcc restore_saved_menu_palette_and_request_upload_d0cd7c
    jsr request_menu_palette_upload
    rtl
