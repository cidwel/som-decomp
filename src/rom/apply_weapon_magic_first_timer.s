; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

boy_weapon_type = $E1E4
boy_saber_hits = $E19D
weapon_magic_first_timer = $CC78

.segment "CODE"
.org $ECEA
apply_weapon_magic_first_timer:
    ldx $85
    lda a:boy_weapon_type
    .a8
    cmp #$01
    beq apply_weapon_magic_first_timer_c8ecf4
    rts
apply_weapon_magic_first_timer_c8ecf4:
    stz a:boy_saber_hits
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda $9C
    sta a:weapon_magic_first_timer
    rts
