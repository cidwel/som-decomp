; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


object_pending_damage = $E1F1

.segment "CODE"
.org $E9DF
queue_spell_damage_with_minimum_one:
    rep #$20
    lda $89
    sec
    sbc $94
    bpl queue_spell_damage_with_minimum_one_c8e9eb
    .a16
    lda #$0001
queue_spell_damage_with_minimum_one_c8e9eb:
    bne queue_spell_damage_with_minimum_one_c8e9f0
    .a16
    lda #$0001
queue_spell_damage_with_minimum_one_c8e9f0:
    sta $89
    clc
    adc a:object_pending_damage,X
    sta a:object_pending_damage,X
    sep #$20
    rts
