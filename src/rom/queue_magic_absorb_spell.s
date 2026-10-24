; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
select_spell_element_multiplier = $E8A0

object_mp = $E186
object_pending_mp_damage = $E1F5
object_pending_mp_heal = $E1F6
object_actor_traits = $E192
object_hit_flash_timer = $E1F8

.segment "CODE"
.org $EC3B
queue_magic_absorb_spell:
    ldx $85
    .a8
    lda #$20
    sta a:object_hit_flash_timer,Y
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    rep #$20
    lda $96
    sec
    sbc $94
    bpl queue_magic_absorb_spell_c8ec54
    .a16
    lda #$0000
queue_magic_absorb_spell_c8ec54:
    sta f:$004204
    sep #$20
    .a8
    lda #$0A
    sta f:$004206
    nop
    nop
    nop
    nop
    lda a:object_actor_traits,X
    .a8
    bit #$40
    bne queue_magic_absorb_spell_c8ec90
    lda f:$004214
    bne queue_magic_absorb_spell_c8ec73
    .a8
    lda #$01
queue_magic_absorb_spell_c8ec73:
    cmp a:object_mp,X
    bcc queue_magic_absorb_spell_c8ec7b
    lda a:object_mp,X
queue_magic_absorb_spell_c8ec7b:
    sta $A4
    lda a:object_pending_mp_damage,X
    clc
    adc $A4
    sta a:object_pending_mp_damage,X
    lda a:object_pending_mp_heal,Y
    clc
    adc $A4
    sta a:object_pending_mp_heal,Y
    rts
queue_magic_absorb_spell_c8ec90:
    lda f:$004214
    bne queue_magic_absorb_spell_c8ec98
    .a8
    lda #$01
queue_magic_absorb_spell_c8ec98:
    cmp a:object_mp,Y
    bcc queue_magic_absorb_spell_c8eca0
    lda a:object_mp,Y
queue_magic_absorb_spell_c8eca0:
    sta $A4
    lda a:object_pending_mp_damage,Y
    clc
    adc $A4
    sta a:object_pending_mp_damage,Y
    lda a:object_pending_mp_heal,X
    clc
    adc $A4
    sta a:object_pending_mp_heal,X
    rts
