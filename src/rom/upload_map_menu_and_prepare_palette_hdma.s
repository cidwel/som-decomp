; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_map_palette_hdma_channels = $C1F4
upload_menu_frame_entry = $C00006

.segment "CODE"
.org $C1E7
upload_map_menu_and_prepare_palette_hdma:
    sep #$20
    .a8
    lda #$04
    bit a:$1D04
    beq prepare_map_palette_hdma_channels
    jsl f:upload_menu_frame_entry
