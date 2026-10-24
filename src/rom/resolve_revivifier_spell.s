; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
routine_c8e9fc = $E9FC
routine_c8ea69 = $EA69

object_pending_heal = $E1F3
object_pending_damage = $E1F1
object_hp = $E182
object_actor_kind = $E1FB
object_status_high = $E191

.segment "CODE"
.org $ED04
resolve_revivifier_spell:
    ldx $85
    lda a:object_actor_kind,X
    .a8
    bit #$C0
    beq resolve_revivifier_spell_c8ed52
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    jsr routine_c8ea69
    jsr routine_c8e9fc
    lda a:object_status_high,X
    .a8
    and #$7F
    sta a:object_status_high,X
    rep #$20
    lda $89
    sta f:$004204
    sep #$20
    .a8
    lda #$09
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
    sta a:object_pending_heal,X
    lda a:object_hp,X
    bne resolve_revivifier_spell_c8ed4d
    inc a:object_hp,X
resolve_revivifier_spell_c8ed4d:
    stz a:object_pending_damage,X
    sep #$20
resolve_revivifier_spell_c8ed52:
    rts
