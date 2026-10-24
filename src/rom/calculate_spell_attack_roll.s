; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_magic_defence_roll = $E990

object_target_divisor = $E176
object_bonus_damage_level = $E1E6

.segment "CODE"
.org $E8C0
calculate_spell_attack_roll:
    jsr calculate_spell_magic_defence_roll
    lda $91
    lsr
    lsr
    sta $8D
    .i16
    ldy #$2ADB
    lda [$DC],Y
    ldy $83
    clc
    adc $8D
    .a8
    cmp #$63
    bcc calculate_spell_attack_roll_c8e8d9
    .a8
    lda #$63
calculate_spell_attack_roll_c8e8d9:
    sta $8D
    lda $96
    clc
    adc $91
    sta $D4
    stz $D5
    lda $9D
    clc
    .a8
    adc #$02
    sta $D0
    jsl f:$C054B2
    rep #$20
    lda $CC
    lsr
    .a16
    cmp #$03E7
    bcc calculate_spell_attack_roll_c8e8fc
    .a16
    lda #$03E7
calculate_spell_attack_roll_c8e8fc:
    sta $89
    sep #$20
    .a8
    lda #$65
    jsl f:$C03884
    cmp $8D
    rep #$20
    bcs calculate_spell_attack_roll_c8e93d
    sep #$20
    lda a:object_bonus_damage_level,Y
    sta f:$004202
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    clc
    adc $89
    sta $89
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
    adc $89
    sta $89
    bra calculate_spell_attack_roll_c8e951
calculate_spell_attack_roll_c8e93d:
    lda $89
    sta $A8
    sep #$20
    lda $8D
    sta $A6
    jsl f:$C05437
    rep #$20
    lda $A4
    sta $89
calculate_spell_attack_roll_c8e951:
    lda $8F
    .a16
    and #$00FF
    sta $A4
    .a16
    lda #$0000
calculate_spell_attack_roll_c8e95b:
    clc
    adc $89
    dec $A4
    bne calculate_spell_attack_roll_c8e95b
    lsr
    sta f:$004204
    sep #$20
    lda a:object_target_divisor,Y
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda f:$004214
    .a16
    cmp #$03E7
    bcc calculate_spell_attack_roll_c8e985
    .a16
    lda #$03E7
calculate_spell_attack_roll_c8e985:
    sta $89
    sta $96
    lsr
    lsr
    sep #$20
    sta $9C
    rts
