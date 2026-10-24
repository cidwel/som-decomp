; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

object_secondary_buff_flags = $E1B1
object_barrier_pool = $E1BD
object_barrier_guard = $E1BF
object_max_hp = $E184
object_spell_target_count = $E176
object_physical_defence = $E1A5

.segment "CODE"
.org $EEB7
apply_lucid_barrier_spell:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda a:object_secondary_buff_flags,X
    .a8
    ora #$10
    sta a:object_secondary_buff_flags,X
    rep #$20
    lda a:object_physical_defence,X
    lsr
    sta f:$004204
    sep #$20
    lda a:object_spell_target_count,Y
    sta f:$004206
    rep #$20
    lda a:object_max_hp,X
    cmp $89
    bcs apply_lucid_barrier_spell_c8eee6
    sta $89
apply_lucid_barrier_spell_c8eee6:
    lda $89
    sta a:object_barrier_pool,X
    sep #$20
    lda f:$004214
    sta a:object_barrier_guard,X
    rts
