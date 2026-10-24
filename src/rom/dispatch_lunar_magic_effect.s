; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
select_spell_element_multiplier = $E8A0

lunar_effect_table = $EF19

.segment "CODE"
.org $EEF5
dispatch_lunar_magic_effect:
    ldx $85
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    .a8
    lda #$08
    jsl f:$C03884
    rep #$20
    .a16
    and #$000F
    sep #$20
    pha
    jsl f:$C05BA4
    .a8
    lda #$00
    xba
    pla
    asl
    tax
    jsr (lunar_effect_table,X)
    rts
