; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


frame_request_flags = $1D04
pending_hdma_flags = $2C
palette_hdma_context = $010E
color_channel_table_address = $4312
address_channel_table_address = $4302
address_channel_current_table = $4308
color_channel_mode_and_port = $4310
address_channel_mode_and_port = $4300
address_channel_table_bank = $4304
color_channel_table_bank = $4314
color_channel_indirect_bank = $4317

.segment "CODE"
.org $C1F4
prepare_map_palette_hdma_channels:
    sep #$20
    lda a:frame_request_flags
    .a8
    and #$20
    bne prepare_map_palette_hdma_channels_c0c1fe
prepare_map_palette_hdma_channels_c0c1fd:
    rts
prepare_map_palette_hdma_channels_c0c1fe:
    lda pending_hdma_flags
    .a8
    and #$03
    bne prepare_map_palette_hdma_channels_c0c1fd
    rep #$20
    lda a:palette_hdma_context
    beq prepare_map_palette_hdma_channels_c0c1fd
    .a16
    lda #$05D0
    sta a:color_channel_table_address
    .a16
    lda #$05DB
    sta a:address_channel_table_address
    sta a:address_channel_current_table
    .a16
    lda #$2242
    sta a:color_channel_mode_and_port
    .a16
    lda #$2100
    sta a:address_channel_mode_and_port
    sep #$20
    stz a:address_channel_table_bank
    stz a:color_channel_table_bank
    .a8
    lda #$7E
    sta a:color_channel_indirect_bank
    .a8
    lda #$03
    tsb pending_hdma_flags
    rts
