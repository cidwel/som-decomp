; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_counted_rom_tile_rectangle = $272B

.segment "CODE"
.org $2642
consume_native_menu_party_variant_rectangle:
    ldx a:$0000,Y
    iny
    iny
    phy
    .i16
    ldy #$7703
    phx
    lda f:$0019FE
    inc
    .i16
    ldx #$FFFF
consume_native_menu_party_variant_rectangle_c02654:
    inx
    .i16
    cpx #$0003
    beq consume_native_menu_party_variant_rectangle_c0265e
    cmp $D9,X
    bne consume_native_menu_party_variant_rectangle_c02654
consume_native_menu_party_variant_rectangle_c0265e:
    lda $EE,X
    .a8
    and #$03
    beq consume_native_menu_party_variant_rectangle_c02667
    .i16
    ldy #$7765
consume_native_menu_party_variant_rectangle_c02667:
    plx
    jsr expand_native_menu_counted_rom_tile_rectangle
    ply
    rts
