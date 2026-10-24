; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
routine_c8ea69 = $EA69

object_pending_damage = $E1F1
object_hp = $E182
object_max_hp = $E184
object_actor_kind = $E1FB

.segment "CODE"
.org $ED82
queue_evil_gate_spell:
    ldx $85
    jsr routine_c8ea69
    jsr calculate_spell_attack_roll
    rep #$20
    lda a:object_hp,X
    clc
    adc a:object_max_hp,X
    lsr
    sta f:$004204
    sep #$20
    .a8
    lda #$0A
    sec
    sbc $9D
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
    sta $89
    lda a:object_actor_kind,X
    .a16
    bit #$0040
    php
    lda $89
    plp
    beq queue_evil_gate_spell_c8edc1
    .a16
    lda #$0001
queue_evil_gate_spell_c8edc1:
    clc
    adc a:object_pending_damage,X
    sta a:object_pending_damage,X
    sep #$20
    rts
