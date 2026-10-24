; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


object_magic_evasion = $E1A7
object_magic_defence = $E1A8

.segment "CODE"
.org $E990
calculate_spell_magic_defence_roll:
    .a8
    lda #$65
    jsl f:$C03884
    cmp a:object_magic_evasion,X
    rep #$20
    bcs calculate_spell_magic_defence_roll_c8e9c0
    lda a:object_magic_defence,X
    lsr
    lsr
    lsr
    lsr
    sep #$20
    jsl f:$C03884
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:object_magic_defence,X
    .a16
    cmp #$03E7
    bcc calculate_spell_magic_defence_roll_c8e9bb
    .a16
    lda #$03E7
calculate_spell_magic_defence_roll_c8e9bb:
    sta $94
    sep #$20
    rts
calculate_spell_magic_defence_roll_c8e9c0:
    lda a:object_magic_defence,X
    lsr
    lsr
    clc
    adc a:object_magic_defence,X
    sta $A8
    sep #$20
    lda a:object_magic_evasion,X
    sta $A6
    jsl f:$C05437
    rep #$20
    lda $A4
    sta $94
    sep #$20
    rts
