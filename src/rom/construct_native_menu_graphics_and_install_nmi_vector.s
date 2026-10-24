; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

configure_native_menu_background_and_scroll_ports = $27E0
expand_native_menu_glyph_grid_to_two_bitplanes = $2169
initialize_native_menu_frame_tiles_and_palette = $1F97
initialize_native_menu_page_palette = $20E4
seed_native_menu_grid_from_actual_rom = $21BE
upload_native_menu_actor_tiles_and_palette = $2010
upload_native_menu_assembled_text_tiles = $23BA

.segment "CODE"
.org $281E
construct_native_menu_graphics_and_install_nmi_vector:
    pha
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$01
    sta f:$004200
    .a8
    lda #$00
    sta f:$00420C
    stz a:$A20B
    stz a:$A20A
    stz a:$A211
    stz a:$A17B
    .a8
    lda #$05
    sta f:$001D05
    .a8
    lda #$00
    sta f:$001D04
    sta f:$001D12
    sta f:$001D00
    .a8
    lda #$10
    tsb a:$A212
    .a8
    lda #$80
    sta f:$002100
    sta f:$002115
    jsr initialize_native_menu_frame_tiles_and_palette
    jsr configure_native_menu_background_and_scroll_ports
    jsr seed_native_menu_grid_from_actual_rom
    jsr expand_native_menu_glyph_grid_to_two_bitplanes
    .i16
    ldx #$0420
    stx a:$A191
    .i16
    ldx #$6000
    stx a:$A18C
    jsr upload_native_menu_assembled_text_tiles
    jsr upload_native_menu_actor_tiles_and_palette
    pla
    jsr initialize_native_menu_page_palette
    rep #$20
    lda f:$000102
    sta a:$A21D
    lda f:$000100
    sta a:$A21B
    .a16
    lda #$20A7
    sta f:$000101
    sep #$20
    .a8
    lda #$C0
    sta f:$000103
    .a8
    lda #$5C
    sta f:$000100
    rts
