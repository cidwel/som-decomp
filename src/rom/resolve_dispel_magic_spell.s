; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
select_spell_element_multiplier = $E8A0

object_evasion_buff_timer = $E1BB
object_accuracy_buff_timer = $E1BA
object_defence_buff_timer = $E1BC
object_attack_buff_timer = $E1B7
object_saber_hits = $E19D
object_secondary_buff_flags = $E1B1
object_wall_hits = $E1B8
object_rebuild_flags = $E1FA
object_weapon_effect_timer = $E19B
object_magic_defence = $E1A8
object_spell_target_count = $E176

.segment "CODE"
.org $EDCB
resolve_dispel_magic_spell:
    ldx $85
    stz a:object_weapon_effect_timer,X
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    lda a:object_rebuild_flags,X
    .a8
    ora #$04
    sta a:object_rebuild_flags,X
    lda $9D
    .a8
    cmp #$08
    bne resolve_dispel_magic_spell_c8edfb
resolve_dispel_magic_spell_c8ede4:
    .a8
    lda #$01
    sta a:object_attack_buff_timer,X
    sta a:object_accuracy_buff_timer,X
    sta a:object_evasion_buff_timer,X
    sta a:object_defence_buff_timer,X
    stz a:object_saber_hits,X
    stz a:object_wall_hits,X
    jmp resolve_dispel_magic_spell_c8ee8d
resolve_dispel_magic_spell_c8edfb:
    .a8
    cmp #$04
    bcc resolve_dispel_magic_spell_c8ee08
    lda a:object_spell_target_count,Y
    .a8
    cmp #$01
    bne resolve_dispel_magic_spell_c8ee08
    bra resolve_dispel_magic_spell_c8ede4
resolve_dispel_magic_spell_c8ee08:
    rep #$20
    lda a:object_magic_defence,X
    lsr
    sta $A4
    lda $96
    lsr
    lsr
    sec
    sbc $A4
    bcs resolve_dispel_magic_spell_c8ee1c
    .a16
    lda #$0000
resolve_dispel_magic_spell_c8ee1c:
    sep #$20
    sta $A4
    lda a:object_attack_buff_timer,X
    sec
    sbc $A4
    bcs resolve_dispel_magic_spell_c8ee2a
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee2a:
    bne resolve_dispel_magic_spell_c8ee2e
    .a8
    lda #$01
resolve_dispel_magic_spell_c8ee2e:
    sta a:object_attack_buff_timer,X
    lda a:object_accuracy_buff_timer,X
    sec
    sbc $A4
    bcs resolve_dispel_magic_spell_c8ee3b
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee3b:
    bne resolve_dispel_magic_spell_c8ee3f
    .a8
    lda #$01
resolve_dispel_magic_spell_c8ee3f:
    sta a:object_accuracy_buff_timer,X
    lda a:object_evasion_buff_timer,X
    sec
    sbc $A4
    bcs resolve_dispel_magic_spell_c8ee4c
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee4c:
    bne resolve_dispel_magic_spell_c8ee50
    .a8
    lda #$01
resolve_dispel_magic_spell_c8ee50:
    sta a:object_evasion_buff_timer,X
    lda a:object_defence_buff_timer,X
    sec
    sbc $A4
    bcs resolve_dispel_magic_spell_c8ee5d
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee5d:
    bne resolve_dispel_magic_spell_c8ee61
    .a8
    lda #$01
resolve_dispel_magic_spell_c8ee61:
    sta a:object_defence_buff_timer,X
    ldx $85
    lda $9D
    inc
    asl
    asl
    sta $A4
    lda a:object_saber_hits,X
    sec
    sbc $A4
    bpl resolve_dispel_magic_spell_c8ee77
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee77:
    sta a:object_saber_hits,X
    lda $9D
    inc
    inc
    sta $A4
    lda a:object_wall_hits,X
    sec
    sbc $A4
    bpl resolve_dispel_magic_spell_c8ee8a
    .a8
    lda #$00
resolve_dispel_magic_spell_c8ee8a:
    sta a:object_wall_hits,X
resolve_dispel_magic_spell_c8ee8d:
    lda a:object_wall_hits,X
    bne resolve_dispel_magic_spell_c8ee9a
    lda a:object_secondary_buff_flags,X
    .a8
    and #$BF
    sta a:object_secondary_buff_flags,X
resolve_dispel_magic_spell_c8ee9a:
    lda a:object_saber_hits,X
    bne resolve_dispel_magic_spell_c8eeab
    lda a:object_rebuild_flags,X
    .a8
    ora #$04
    sta a:object_rebuild_flags,X
    jsl f:$C04530
resolve_dispel_magic_spell_c8eeab:
    lda a:object_secondary_buff_flags,X
    .a8
    bit #$40
    beq resolve_dispel_magic_spell_c8eeb6
    jsl f:$C05BB6
resolve_dispel_magic_spell_c8eeb6:
    rts
