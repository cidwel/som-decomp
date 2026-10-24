; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c8e5f2 = $E5F2

object_status_word = $E190
object_status_high = $E191
object_actor_kind = $E1FB
object_rebuild_flags = $E1FA
object_effective_attack_row = $E1E3
object_weapon_type = $E1E4
object_primary_weapon_row = $E1E8
object_secondary_weapon_row = $E1E9
object_timer_phase = $E1B9
object_cast_phase = $E175

.segment "CODE"
.org $E5FF
select_actor_status_attack_row:
    lda a:object_actor_kind,X
    .a8
    bit #$40
    bne routine_c8e5f2
    stz $A4
    lda a:object_status_high,X
    bpl select_actor_status_attack_row_c8e631
    lda a:object_actor_kind,X
    bpl select_actor_status_attack_row_c8e628
    lda $99
    beq select_actor_status_attack_row_c8e623
    .a8
    lda #$1E
    sta a:object_timer_phase,X
    stz a:object_cast_phase,X
    .a8
    lda #$FF
    jmp select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e623:
    .a8
    lda #$F1
    jmp select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e628:
    .a8
    bit #$01
    bne select_actor_status_attack_row_c8e64f
    .a8
    lda #$00
    jmp select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e631:
    .a8
    bit #$02
    beq select_actor_status_attack_row_c8e637
    inc $A4
select_actor_status_attack_row_c8e637:
    .a8
    bit #$40
    beq select_actor_status_attack_row_c8e650
    lda a:object_actor_kind,X
    .a8
    bit #$81
    bne select_actor_status_attack_row_c8e647
    .a8
    lda #$F6
    jmp select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e647:
    .a8
    lda #$FD
    clc
    adc $A4
    jmp select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e64f:
    rts
select_actor_status_attack_row_c8e650:
    .a8
    bit #$01
    beq select_actor_status_attack_row_c8e67a
    .a8
    lda #$F7
    sta $A6
    lda a:object_actor_kind,X
    .a8
    bit #$81
    bne select_actor_status_attack_row_c8e663
    .a8
    lda #$F2
    sta $A6
select_actor_status_attack_row_c8e663:
    stz $A4
    lda $9D
    .a8
    cmp #$04
    bcc select_actor_status_attack_row_c8e673
    inc $A4
    .a8
    cmp #$08
    bcc select_actor_status_attack_row_c8e673
    inc $A4
select_actor_status_attack_row_c8e673:
    lda $A4
    clc
    adc $A6
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e67a:
    rep #$20
    lda a:object_status_word,X
    .a16
    bit #$1060
    sep #$20
    beq select_actor_status_attack_row_c8e695
    lda a:object_actor_kind,X
    .a8
    bit #$81
    bne select_actor_status_attack_row_c8e691
    .a8
    lda #$00
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e691:
    .a8
    lda #$F1
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e695:
    lda a:object_status_high,X
    .a8
    bit #$04
    beq select_actor_status_attack_row_c8e6ae
    lda a:object_actor_kind,X
    .a8
    bit #$81
    bne select_actor_status_attack_row_c8e6a7
    .a8
    lda #$F5
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e6a7:
    .a8
    lda #$FB
    clc
    adc $A4
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e6ae:
    lda $A4
    beq select_actor_status_attack_row_c8e6b6
    .a8
    lda #$FA
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e6b6:
    lda a:object_weapon_type,X
    bpl select_actor_status_attack_row_c8e6c0
    lda a:object_secondary_weapon_row,X
    bra select_actor_status_attack_row_c8e6c3
select_actor_status_attack_row_c8e6c0:
    lda a:object_primary_weapon_row,X
select_actor_status_attack_row_c8e6c3:
    cmp a:object_effective_attack_row,X
    beq select_actor_status_attack_row_c8e6d3
    sta a:object_effective_attack_row,X
    .a8
    lda #$04
    ora a:object_rebuild_flags,X
    sta a:object_rebuild_flags,X
select_actor_status_attack_row_c8e6d3:
    rts
