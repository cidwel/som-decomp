; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-page.md.
.setcpu "65816"
.smart
.a8
.i16

read_packed_native_weapon_skill_nibble_and_publish_glyph = $6679
select_native_current_hero_weapon_skill_index = $6C92

.segment "CODE"
.org $6C58
publish_native_skill_count_and_selector_rows:
    jsr select_native_current_hero_weapon_skill_index
    .i16
    ldx #$0000
    jsr read_packed_native_weapon_skill_nibble_and_publish_glyph
    rep #$20
    lda a:$9C00
    sec
    .a16
    sbc #$00B5
    inc
    .a16
    and #$00FF
    sta a:$A200
    sta a:$A175
    .i16
    ldx #$01BA
    .a16
    lda #$2180
publish_native_skill_count_and_selector_rows_c76c7a:
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    pha
    txa
    clc
    .a16
    adc #$0080
    tax
    pla
    inc
    inc
    dec a:$A175
    bne publish_native_skill_count_and_selector_rows_c76c7a
    rts
