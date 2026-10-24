; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


window_channel_mode_and_port = $4330
window_channel_table_address = $4332
window_channel_table_bank_and_count_low = $4334
window_channel_count_high_and_indirect_bank = $4336
mode_channel_mode_and_port = $4320
mode_channel_table_address = $4322
mode_channel_table_bank_and_count_low = $4324

.segment "CODE"
.org $C7B2
configure_map_overlay_hdma_channels:
    rep #$20
    .a16
    lda #$2641
    sta a:window_channel_mode_and_port
    .a16
    lda #$EF00
    sta a:window_channel_table_address
    .a16
    lda #$007E
    sta a:window_channel_table_bank_and_count_low
    xba
    sta a:window_channel_count_high_and_indirect_bank
    .a16
    lda #$0500
    sta a:mode_channel_mode_and_port
    .a16
    lda #$EF20
    sta a:mode_channel_table_address
    .a16
    lda #$007E
    sta a:mode_channel_table_bank_and_count_low
    rts
