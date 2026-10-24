; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_byte_by_word = $54B6
multiply_byte_word_divide_by_100 = $543B

object_primary_buffs = $E1B0
object_secondary_conditions = $E191
object_weapon_bonus = $E1AE
object_attack_power = $E198
object_charge_stage = $E19B
object_bonus_damage_level = $E1E6
mana_sword_stage_bonus = $CC76

.segment "CODE"
.org $51E7
calculate_physical_attack_roll:
    lda $82
    bne calculate_physical_attack_roll_c051f7
    lda a:mana_sword_stage_bonus
    beq calculate_physical_attack_roll_c051f7
    clc
    adc a:object_charge_stage,Y
    sta a:object_charge_stage,Y
calculate_physical_attack_roll_c051f7:
    lda a:object_attack_power,Y
    sta $D4
    stz $D5
    sep #$20
    lda a:object_charge_stage,Y
    asl
    sta $9D
    clc
    .a8
    adc #$04
    sta $D0
    jsr multiply_byte_by_word
    rep #$20
    lda $CC
    lsr
    lsr
    sta $89
    sta f:$004204
    lsr
    lsr
    sta $AE
    lda a:object_primary_buffs,Y
    .a16
    bit #$0080
    beq calculate_physical_attack_roll_c0522f
    lda $89
    sec
    sbc $AE
    sta $89
    bra calculate_physical_attack_roll_c0523b
calculate_physical_attack_roll_c0522f:
    .a16
    bit #$0040
    beq calculate_physical_attack_roll_c0523b
    lda $89
    clc
    adc $AE
    sta $89
calculate_physical_attack_roll_c0523b:
    sep #$20
    lda a:object_weapon_bonus,Y
    .a8
    and #$0F
    beq calculate_physical_attack_roll_c05261
    sta $A4
    .a8
    lda #$0A
    sec
    sbc $A4
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
    clc
    adc $89
    sta $89
calculate_physical_attack_roll_c05261:
    rep #$20
    lda $8F
    .a16
    and #$00FF
    sta $A4
    .a16
    lda #$0000
calculate_physical_attack_roll_c0526d:
    clc
    adc $89
    dec $A4
    bne calculate_physical_attack_roll_c0526d
    lsr
    .a16
    cmp #$03E7
    bcc calculate_physical_attack_roll_c0527d
    .a16
    lda #$03E7
calculate_physical_attack_roll_c0527d:
    sta $89
    lda a:object_secondary_conditions,Y
    .a16
    bit #$0002
    beq calculate_physical_attack_roll_c0528c
    .a16
    lda #$0001
    sta $89
calculate_physical_attack_roll_c0528c:
    sep #$20
    .a8
    lda #$65
    jsl f:$C03884
    cmp $8D
    bcs calculate_physical_attack_roll_c052c5
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
    bra calculate_physical_attack_roll_c052d8
calculate_physical_attack_roll_c052c5:
    lda $8D
    sta $A6
    rep #$20
    lda $89
    sta $A8
    sep #$20
    jsr multiply_byte_word_divide_by_100
    rep #$20
    lda $A4
calculate_physical_attack_roll_c052d8:
    .a16
    cmp #$03E7
    bcc calculate_physical_attack_roll_c052e0
    .a16
    lda #$03E7
calculate_physical_attack_roll_c052e0:
    sta $89
    sta $96
    sep #$20
    rts
