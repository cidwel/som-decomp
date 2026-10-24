; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

await_native_saved_slot_menu_frame_wrapper = $C02AEA
decode_native_saved_slot_font_rows_wrapper = $C02ADB
upload_native_saved_slot_text_rows_wrapper = $C02ADF

.segment "CODE"
.org $5D9A
render_native_saved_slot_text_rows_with_real_vblank:
    stz a:$9C00,X
    .a8
    lda #$7E
    sta f:$001D03
    rep #$20
    .a16
    lda #$9C00
    sta f:$001D01
    sep #$20
    stz a:$A1C5
    .a8
    lda #$01
    trb a:$A212
    .a8
    lda #$00
    sta f:$001D00
render_native_saved_slot_text_rows_with_real_vblank_c75dbc:
    jsl f:decode_native_saved_slot_font_rows_wrapper
    jsl f:await_native_saved_slot_menu_frame_wrapper
    jsl f:upload_native_saved_slot_text_rows_wrapper
    rep #$20
    lda a:$A18C
    clc
    adc a:$A199
    sta a:$A18C
    sep #$20
    dec a:$A171
    bne render_native_saved_slot_text_rows_with_real_vblank_c75dbc
    rts
