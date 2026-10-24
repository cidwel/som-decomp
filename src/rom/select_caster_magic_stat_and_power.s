; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


object_spell_id = $E170
object_intelligence = $E18B
object_wisdom = $E18C
object_intelligence_spell_power = $E1FD
object_wisdom_spell_power = $E1FE

.segment "CODE"
.org $E855
select_caster_magic_stat_and_power:
    lda a:object_spell_id,Y
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    .a8
    lda #$06
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004216
    .a8
    cmp #$03
    bcc select_caster_magic_stat_and_power_c8e883
    lda a:object_wisdom_spell_power,Y
    sta $96
    lda a:object_wisdom,Y
    sta $91
    rts
select_caster_magic_stat_and_power_c8e883:
    lda a:object_intelligence,Y
    sta $91
    lda a:object_intelligence_spell_power,Y
    sta $96
    rts
