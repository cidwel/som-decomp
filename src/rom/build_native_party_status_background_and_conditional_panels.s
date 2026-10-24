; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16

build_four_row_native_party_status_rectangle_prefix = $6B23
build_ten_row_native_party_status_rectangle_prefix = $6B2B
native_menu_tile_workspace_upload_long_wrapper = $C02AD7
read_selected_native_party_status_excluding_low_two_bits = $6AA4

.segment "CODE"
.org $6ADF
build_native_party_status_background_and_conditional_panels:
    rep #$20
    .a16
    lda #$2050
    .i16
    ldx #$00E2
    .i16
    ldy #$0005
    jsr build_ten_row_native_party_status_rectangle_prefix
    .i16
    ldx #$00EC
    .i16
    ldy #$0002
    jsr build_ten_row_native_party_status_rectangle_prefix
    jsr read_selected_native_party_status_excluding_low_two_bits
    beq build_native_party_status_background_and_conditional_panels_c76b1c
    .i16
    ldx #$0402
    .i16
    ldy #$000E
    lda a:$9000,X
    .a16
    ora #$1400
    jsr build_four_row_native_party_status_rectangle_prefix
    .a16
    lda #$2022
    sta a:$9500
    sta a:$9540
    .a16
    lda #$6022
    sta a:$951E
    sta a:$955E
build_native_party_status_background_and_conditional_panels_c76b1c:
    sep #$20
    jsl f:native_menu_tile_workspace_upload_long_wrapper
    rts
