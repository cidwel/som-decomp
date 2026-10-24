; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_tile_workspace_upload_long_wrapper = $C02AD7

.segment "CODE"
.org $553F
construct_nine_native_save_confirmation_tile_rows:
    .i16
    ldx #$008E
    rep #$20
    .a16
    lda #$0009
    sta a:$A171
    .i16
    ldy #$2218
construct_nine_native_save_confirmation_tile_rows_c7554d:
    .a16
    lda #$000C
    sta a:$A173
    tya
    phx
construct_nine_native_save_confirmation_tile_rows_c75555:
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    inc
    inc
    inx
    inx
    dec a:$A173
    bne construct_nine_native_save_confirmation_tile_rows_c75555
    tay
    pla
    clc
    .a16
    adc #$0080
    tax
    tya
    dec a:$A171
    bne construct_nine_native_save_confirmation_tile_rows_c7554d
    sep #$20
    jsl f:native_menu_tile_workspace_upload_long_wrapper
    rts
