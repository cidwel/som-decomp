; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

apply_critical_hit_or_weapon_gauge = $532C
apply_lucid_barrier_absorption = $541B
calculate_physical_attack_roll = $51E7
calculate_physical_defence_roll = $52E7

object_attack_element = $E195
object_barrier_points = $E1BF
object_last_attacker = $E1EC
object_actor_kind = $E1FB
object_pending_damage = $E1F1
object_pending_heal = $E1F3
object_enemy_type = $E192

.segment "CODE"
.org $514B
resolve_and_queue_physical_damage:
    lda a:object_barrier_points,X
    sta $90
    lda $82
    sta a:object_last_attacker,X
    rep #$20
    lda $87
    sta $94
    sep #$20
    jsr calculate_physical_attack_roll
    jsr calculate_physical_defence_roll
    jsr apply_critical_hit_or_weapon_gauge
    jsr apply_lucid_barrier_absorption
    rep #$20
    lda $89
    sec
    sbc $94
    beq resolve_and_queue_physical_damage_c05174
    bpl resolve_and_queue_physical_damage_c0519a
resolve_and_queue_physical_damage_c05174:
    sep #$20
    jsl f:$C04E6B
    lda a:object_actor_kind,X
    bpl resolve_and_queue_physical_damage_c05180
    rts
resolve_and_queue_physical_damage_c05180:
    rep #$20
    lda a:object_pending_damage,X
    sep #$20
    bne resolve_and_queue_physical_damage_c05199
    lda a:$E175,X
    bne resolve_and_queue_physical_damage_c05199
    stz a:$E17B,X
    stz a:$E17C,X
    .a8
    lda #$D0
    sta a:$E175,X
resolve_and_queue_physical_damage_c05199:
    rts
resolve_and_queue_physical_damage_c0519a:
    sta $89
    lda a:object_attack_element,Y
    .a16
    bit #$0040
    beq resolve_and_queue_physical_damage_c051db
    lda a:object_enemy_type,X
    .a16
    bit #$0020
    bne resolve_and_queue_physical_damage_c051c0
    lda $89
    clc
    adc a:object_pending_damage,X
    sta a:object_pending_damage,X
    lda $89
    clc
    adc a:object_pending_heal,Y
    sta a:object_pending_heal,Y
    bra resolve_and_queue_physical_damage_c051e4
resolve_and_queue_physical_damage_c051c0:
    lda $89
    clc
    adc a:object_pending_damage,Y
    sta a:object_pending_damage,Y
    lda $89
    clc
    adc a:object_pending_heal,X
    sta a:object_pending_heal,X
    sep #$20
    lda $82
    sta a:object_last_attacker,Y
    bra resolve_and_queue_physical_damage_c051e4
resolve_and_queue_physical_damage_c051db:
    lda $89
    clc
    adc a:object_pending_damage,X
    sta a:object_pending_damage,X
resolve_and_queue_physical_damage_c051e4:
    sep #$20
    rts
