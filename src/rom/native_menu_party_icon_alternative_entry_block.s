; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-party-icons.md.
.setcpu "65816"
.smart
.a8
.i16

append_two_native_menu_four_tile_icon_groups = $5F13
select_native_menu_icon_position_and_tile_cursor = $5F20

.segment "CODE"
.org $5EC8
native_menu_party_icon_alternative_entry_block:
    .a8
    lda #$00
    bra native_menu_party_icon_alternative_entry_block_c75ede
    .a8
    lda #$01
    bra native_menu_party_icon_alternative_entry_block_c75ede
    .a8
    lda #$08
    bra native_menu_party_icon_alternative_entry_block_c75ede
    .a8
    lda #$09
    bra native_menu_party_icon_alternative_entry_block_c75ede
    .a8
    lda #$04
    bra native_menu_party_icon_alternative_entry_block_c75ede
    .a8
    lda #$05
native_menu_party_icon_alternative_entry_block_c75ede:
    jsr select_native_menu_icon_position_and_tile_cursor
    bra append_two_native_menu_four_tile_icon_groups
    .a8
    lda #$0A
    bra native_menu_party_icon_alternative_entry_block_c75eed
    .a8
    lda #$02
    bra native_menu_party_icon_alternative_entry_block_c75eed
    .a8
    lda #$06
native_menu_party_icon_alternative_entry_block_c75eed:
    jsr select_native_menu_icon_position_and_tile_cursor
    lda a:$A159
    pha
    .i16
    ldx #$5FC7
    jsr append_two_native_menu_four_tile_icon_groups
    pla
    sta a:$A159
    inc a:$A15A
    jsr append_two_native_menu_four_tile_icon_groups
    .a8
    lda #$F8
    sta a:$9C69
    sta a:$9C6D
    sta a:$9C89
    sta a:$9C8D
    rts
