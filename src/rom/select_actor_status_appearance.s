; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

random_byte_long_wrapper = $C0389C
rebuild_actor_attributes_native = $C04530

object_status_word = $E190
object_status_high = $E191
object_actor_kind = $E1FB
object_original_id = $E1E7
object_appearance_id = $E180
object_rebuild_flags = $E1FA
object_effective_attack_row = $E1E3
object_weapon_type = $E1E4
object_primary_weapon_row = $E1E8
object_secondary_weapon_row = $E1E9
monster_change_form_ids = $C8E5F3

.segment "CODE"
.org $E52F
select_actor_status_appearance:
    stz $A4
    lda a:object_status_high,X
    .a8
    bit #$02
    beq select_actor_status_appearance_c8e53a
    inc $A4
select_actor_status_appearance_c8e53a:
    lda a:object_actor_kind,X
    bmi select_actor_status_appearance_c8e542
    jmp select_actor_status_appearance_c8e5a3
select_actor_status_appearance_c8e542:
    lda a:object_status_word,X
    .a8
    bit #$40
    beq select_actor_status_appearance_c8e550
    .a8
    lda #$EC
    clc
    adc $A4
    bra select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e550:
    .a8
    bit #$20
    beq select_actor_status_appearance_c8e55b
    .a8
    lda #$EE
    clc
    adc $A4
    bra select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e55b:
    lda a:object_status_high,X
    bpl select_actor_status_appearance_c8e568
    lda $81
    clc
    .a8
    adc #$E4
    jmp select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e568:
    .a8
    bit #$10
    beq select_actor_status_appearance_c8e583
    lda a:object_original_id,X
    clc
    .a8
    adc #$70
    sta $A6
    lda $A4
    beq select_actor_status_appearance_c8e57f
    lda $A6
    clc
    .a8
    adc #$03
    sta $A6
select_actor_status_appearance_c8e57f:
    lda $A6
    bra select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e583:
    lda $A4
    beq select_actor_status_appearance_c8e58f
    lda a:object_original_id,X
    clc
    .a8
    adc #$76
    bra select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e58f:
    lda a:object_original_id,X
select_actor_status_appearance_c8e592:
    cmp a:object_appearance_id,X
    beq select_actor_status_appearance_c8e5a2
    sta a:object_appearance_id,X
    lda a:object_rebuild_flags,X
    .a8
    ora #$01
    sta a:object_rebuild_flags,X
select_actor_status_appearance_c8e5a2:
    rts
select_actor_status_appearance_c8e5a3:
    lda a:object_status_high,X
    bpl select_actor_status_appearance_c8e5a9
    rts
select_actor_status_appearance_c8e5a9:
    lda a:object_status_word,X
    .a8
    bit #$20
    beq select_actor_status_appearance_c8e5b4
    .a8
    lda #$83
    bra select_actor_status_appearance_c8e592
select_actor_status_appearance_c8e5b4:
    lda a:object_status_high,X
    .a8
    bit #$08
    beq select_actor_status_appearance_c8e58f
    sep #$20
    jsl f:random_byte_long_wrapper
    rep #$20
    .a16
    and #$0007
    tax
    sep #$20
    lda f:monster_change_form_ids,X
    ldx $85
    sta a:object_appearance_id,X
    lda a:object_rebuild_flags,X
    .a8
    ora #$07
    sta a:object_rebuild_flags,X
    jsl f:rebuild_actor_attributes_native
    lda a:object_primary_weapon_row,X
    sta $A4
    lda a:object_weapon_type,X
    bpl select_actor_status_appearance_c8e5ed
    lda a:object_secondary_weapon_row,X
    sta $A4
select_actor_status_appearance_c8e5ed:
    lda $A4
    sta a:object_effective_attack_row,X
    rts
