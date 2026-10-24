; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
calculate_spell_magic_defence_roll = $E990
select_spell_element_multiplier = $E8A0

object_actor_traits = $E192
object_hp = $E182
object_pending_damage = $E1F1
object_pending_heal = $E1F3
object_hit_flash_timer = $E1F8

.segment "CODE"
.org $EB54
queue_energy_absorb_spell:
    ldx $85
    .a8
    lda #$20
    sta a:object_hit_flash_timer,Y
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    lda a:object_actor_traits,X
    .a8
    bit #$20
    rep #$20
    beq queue_energy_absorb_spell_c8eb77
    sep #$20
    ldx $83
    jsr calculate_spell_magic_defence_roll
    rep #$20
    ldx $83
    ldy $85
queue_energy_absorb_spell_c8eb77:
    lda $89
    sec
    sbc $94
    bpl queue_energy_absorb_spell_c8eb81
    .a16
    lda #$0001
queue_energy_absorb_spell_c8eb81:
    bne queue_energy_absorb_spell_c8eb86
    .a16
    lda #$0001
queue_energy_absorb_spell_c8eb86:
    cmp a:object_hp,X
    bcc queue_energy_absorb_spell_c8eb8e
    lda a:object_hp,X
queue_energy_absorb_spell_c8eb8e:
    sta $A4
    sta a:object_pending_damage,X
    lda $A4
    clc
    adc a:object_pending_heal,Y
    sta a:object_pending_heal,Y
    sep #$20
    rts
