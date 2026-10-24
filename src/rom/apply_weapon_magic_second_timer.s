; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

boy_weapon_type = $E1E4
boy_saber_hits = $E19D
weapon_magic_second_timer = $CC79

.segment "CODE"
.org $ED68
apply_weapon_magic_second_timer:
    ldx $85
    lda a:boy_weapon_type
    .a8
    cmp #$01
    beq apply_weapon_magic_second_timer_c8ed72
    rts
apply_weapon_magic_second_timer_c8ed72:
    stz a:boy_saber_hits
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda $9C
    sta a:weapon_magic_second_timer
    rts
