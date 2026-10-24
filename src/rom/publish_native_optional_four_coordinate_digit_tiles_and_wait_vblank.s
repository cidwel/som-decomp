; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-coordinates.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five = $DE82
split_native_coordinate_word_into_two_digit_selectors = $DEE1
wait_menu_vblank_through_native_long_wrapper = $C0693F

.segment "CODE"
.org $DE29
publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank:
    rep #$30
    lda f:$7ECFF5
    .a16
    and #$00FF
    beq publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank_d0de81
    .a16
    lda #$B010
    sta a:$09FC
    .a16
    lda #$3350
    sta a:$09FE
    lda f:$7EE002
    jsr split_native_coordinate_word_into_two_digit_selectors
    sep #$30
    sta a:$1880
    sty a:$1881
    rep #$30
    lda f:$7EE004
    jsr split_native_coordinate_word_into_two_digit_selectors
    sep #$30
    sta a:$1882
    sty a:$1883
    rep #$30
    .i16
    ldx #$0000
    .a16
    lda #$7500
    jsr expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five
    .a16
    lda #$7510
    jsr expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five
    .a16
    lda #$7600
    jsr expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five
    .a16
    lda #$7610
    jsr expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five
    jsl f:wait_menu_vblank_through_native_long_wrapper
publish_native_optional_four_coordinate_digit_tiles_and_wait_vblank_d0de81:
    rtl
