; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0715d = $715D
set_native_menu_ring_center_from_hero_position_and_offset = $7134
set_shop_hero_context_count_menu_descriptors_and_select_angle_table = $714C

.segment "CODE"
.org $7108
select_native_menu_ring_hero_and_shop_geometry:
    rep #$30
    .i16
    ldy #$FFEB
    lda a:$1808
    .a16
    and #$000F
    xba
    asl
    tax
    .i16
    cpx #$0400
    bcc select_native_menu_ring_hero_and_shop_geometry_c0711e
    .i16
    ldy #$FFEE
select_native_menu_ring_hero_and_shop_geometry_c0711e:
    jsr set_native_menu_ring_center_from_hero_position_and_offset
    lda a:$1847
    .a16
    and #$00FF
    beq routine_c0715d
    dec
    beq set_shop_hero_context_count_menu_descriptors_and_select_angle_table
    .i16
    ldy #$FFF8
    jsr set_native_menu_ring_center_from_hero_position_and_offset
    bra routine_c0715d
