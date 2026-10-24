; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_object_weapon_graphics_and_palette = $EA19

.segment "CODE"
.org $E9F8
refresh_three_party_weapon_graphics_with_saved_bank:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$10
    .i16
    ldx #$0000
    jsr refresh_object_weapon_graphics_and_palette
    rep #$10
    .i16
    ldx #$0200
    jsr refresh_object_weapon_graphics_and_palette
    rep #$10
    .i16
    ldx #$0400
    jsr refresh_object_weapon_graphics_and_palette
    plb
    rts
