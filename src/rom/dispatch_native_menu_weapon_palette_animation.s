; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-palette.md.
.setcpu "65816"
.smart
.a8
.i16

cycle_native_weapon_palette_every_third_menu_frame = $CC11
rotate_native_packed_equipment_palettes_and_blink_rows = $CC79

.segment "CODE"
.org $CBF6
dispatch_native_menu_weapon_palette_animation:
    rep #$30
    lda a:$1809
    .a16
    and #$00FF
    dec
    bne dispatch_native_menu_weapon_palette_animation_d0cc10
    lda a:$1803
    .a16
    and #$0080
    beq dispatch_native_menu_weapon_palette_animation_d0cc0d
    jsr rotate_native_packed_equipment_palettes_and_blink_rows
    rtl
dispatch_native_menu_weapon_palette_animation_d0cc0d:
    jsr cycle_native_weapon_palette_every_third_menu_frame
dispatch_native_menu_weapon_palette_animation_d0cc10:
    rtl
