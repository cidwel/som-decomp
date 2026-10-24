; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

configure_map_overlay_hdma_channels = $C7B2

second_layer_scroll_x = $B4
second_layer_scroll_y = $B6
dma7_source_address = $4372
dma7_source_bank = $4374
dma7_mode_and_port = $4370
dma7_byte_count = $4375
vram_increment_mode = $2115
vram_word_address = $2116
dma_enable = $420B
vram_word_data = $2118
pending_hdma_flags = $2C
first_window_selection = $2123
second_window_selection = $2124
main_screen_window_mask = $212E
overlay_configuration_source = $C80340

overlay_window_buffer = $7EEF80
first_window_pointer = $7EEF01
second_window_pointer = $7EEF04
fourth_window_pointer = $7EEF0A
third_window_pointer = $7EEF07
first_mode_control_record = $7EEF20
second_mode_control_record = $7EEF22
mode_control_terminator = $7EEF24
window_control_terminator = $7EEF0C
first_window_line_count = $7EEF00
second_window_line_count = $7EEF03
third_window_line_count = $7EEF06
fourth_window_line_count = $7EEF09

.segment "CODE"
.org $CEC1
initialize_map_overlay_graphics_and_windows:
    rep #$20
    lda second_layer_scroll_x
    dec
    dec
    sta second_layer_scroll_x
    lda second_layer_scroll_y
    dec
    sta second_layer_scroll_y
    sep #$10
    .a16
    lda #$0380
    sta a:dma7_source_address
    .i8
    ldx #$C8
    stx a:dma7_source_bank
    .a16
    lda #$1801
    sta a:dma7_mode_and_port
    .a16
    lda #$0060
    sta a:dma7_byte_count
    .i8
    ldx #$80
    stx a:vram_increment_mode
    .a16
    lda #$4100
    sta a:vram_word_address
    .i8
    ldx #$80
    stx a:dma_enable
    lda f:overlay_configuration_source
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    asl
    .a16
    ora #$5800
    sta a:vram_word_address
    .i8
    ldx #$10
initialize_map_overlay_graphics_and_windows_c2cf0b:
    .a16
    lda #$3020
    sta a:vram_word_data
    .a16
    lda #$3021
    sta a:vram_word_data
    dex
    bne initialize_map_overlay_graphics_and_windows_c2cf0b
    .i8
    ldx #$10
initialize_map_overlay_graphics_and_windows_c2cf1c:
    .a16
    lda #$3022
    sta a:vram_word_data
    .a16
    lda #$3023
    sta a:vram_word_data
    dex
    bne initialize_map_overlay_graphics_and_windows_c2cf1c
    .i8
    ldx #$10
initialize_map_overlay_graphics_and_windows_c2cf2d:
    .a16
    lda #$3424
    sta a:vram_word_data
    .a16
    lda #$3425
    sta a:vram_word_data
    dex
    bne initialize_map_overlay_graphics_and_windows_c2cf2d
    .i8
    ldx #$00
initialize_map_overlay_graphics_and_windows_c2cf3e:
    lda f:overlay_configuration_source,X
    sta f:overlay_window_buffer,X
    inx
    inx
    .i8
    cpx #$80
    bcc initialize_map_overlay_graphics_and_windows_c2cf3e
    .a16
    lda #$0001
    sta f:overlay_window_buffer
    .a16
    lda #$EF80
    sta f:first_window_pointer
    sta f:second_window_pointer
    sta f:fourth_window_pointer
    .a16
    lda #$EF82
    sta f:third_window_pointer
    .a16
    lda #$0960
    sta f:first_mode_control_record
    .a16
    lda #$0160
    sta f:second_mode_control_record
    .a16
    lda #$0000
    sta f:mode_control_terminator
    jsr configure_map_overlay_hdma_channels
    sep #$20
    .a8
    lda #$00
    sta f:window_control_terminator
    lda f:overlay_configuration_source
    asl
    asl
    sta f:first_window_line_count
    dec
    sta f:second_window_line_count
    .a8
    lda #$9F
    sta f:third_window_line_count
    .a8
    lda #$40
    sta f:fourth_window_line_count
    .a8
    lda #$0C
    sta pending_hdma_flags
    .a8
    lda #$22
    sta a:first_window_selection
    .a8
    lda #$03
    sta a:second_window_selection
    .a8
    lda #$01
    sta a:main_screen_window_mask
    rtl
