; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

object_pending_heal = $E1F3

.segment "CODE"
.org $EBB3
queue_cure_water_healing:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    rep #$20
    lda a:object_pending_heal,X
    clc
    adc $89
    sta a:object_pending_heal,X
    sep #$20
    rts
