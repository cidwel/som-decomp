; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

build_floating_combat_number_tile_records = $8425
load_floating_combat_number_graphic_planes = $85F1
load_object_weapon_palette_from_field_04f = $85D8
wait_for_native_nmi_and_refresh_party_hud_numbers = $E326

.segment "CODE"
.org $810E
create_complete_floating_combat_number:
    stx $14
    sep #$20
    lda a:$E060,X
    beq create_complete_floating_combat_number_c1811c
    .a8
    cmp #$40
    beq create_complete_floating_combat_number_c1811f
    rts
create_complete_floating_combat_number_c1811c:
    jsr load_floating_combat_number_graphic_planes
create_complete_floating_combat_number_c1811f:
    ldx $14
    jsr load_object_weapon_palette_from_field_04f
    rep #$10
    ldx $14
    sep #$20
    .a8
    lda #$03
    sta a:$E084,X
    .a8
    lda #$40
    sta a:$E060,X
    rep #$20
    lda a:$E092,X
    .a16
    and #$3000
    ora a:$E086,X
    sta a:$E0D2,X
    clc
    .a16
    adc #$0002
    sta a:$E0D6,X
    clc
    .a16
    adc #$0002
    .a16
    bit #$0010
    beq create_complete_floating_combat_number_c18155
    .a16
    adc #$0010
create_complete_floating_combat_number_c18155:
    sta a:$E0DA,X
    .a16
    lda #$00F4
    sta a:$E0D0,X
    .a16
    lda #$00FC
    sta a:$E0D4,X
    .a16
    lda #$0004
    sta a:$E0D8,X
    stz a:$E118,X
    lda a:$E074,X
    .a16
    and #$007F
    sta a:$E11A,X
    .a16
    lda #$2808
    sta a:$E11C,X
    stz a:$E11E,X
    jsr build_floating_combat_number_tile_records
    .i16
    cpx #$0600
    bcs create_complete_floating_combat_number_c1818a
    jsr wait_for_native_nmi_and_refresh_party_hud_numbers
create_complete_floating_combat_number_c1818a:
    rep #$10
    ldx $14
    rts
