; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16

load_object_weapon_palette_from_field_04f = $85D8
routine_01c599 = $1C599

.segment "CODE"
.org $860A
load_hero_cast_graphics_and_palette:
    rep #$30
    stx $14
    .a16
    lda #$0040
    sta $08
    lda $01
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $00
    asl
    adc $00
    .a16
    adc #$DF00
    tay
    .a16
    lda #$0000
    sta $00
    .a16
    lda #$00D0
    jsl f:routine_01c599
    jmp load_object_weapon_palette_from_field_04f
