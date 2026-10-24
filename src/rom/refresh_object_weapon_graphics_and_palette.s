; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_object_weapon_graphics_resources = $EA41
routine_0185e4 = $185E4
routine_01c599 = $1C599

.segment "CODE"
.org $EA19
refresh_object_weapon_graphics_and_palette:
    stx $14
    sep #$20
    stz a:$E084,X
    stz a:$E00C,X
    jsr prepare_object_weapon_graphics_resources
    rep #$20
    .a16
    lda #$0040
    sta $08
    ldy $00
    stz $00
    .a16
    lda #$00D4
    jsl f:routine_01c599
    jsl f:routine_0185e4
    rts
