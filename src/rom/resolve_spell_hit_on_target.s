; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

select_caster_magic_stat_and_power = $E855

object_spell_id = $E170
object_target_divisor = $E176
object_actor_kind = $E1FB
object_pending_damage = $E1F1
object_pending_damage_high = $E1F2
object_primary_buffs = $E1B0
spell_handler_table = $E801

.segment "CODE"
.org $E7A7
resolve_spell_hit_on_target:
    lda a:object_actor_kind,X
    .a8
    bit #$40
    beq resolve_spell_hit_on_target_c8e7b4
    lda a:object_spell_id,Y
    sta a:$E00A,X
resolve_spell_hit_on_target_c8e7b4:
    lda a:object_actor_kind,X
    bpl resolve_spell_hit_on_target_c8e7bf
    stz a:object_pending_damage,X
    stz a:object_pending_damage_high,X
resolve_spell_hit_on_target_c8e7bf:
    lda a:object_actor_kind,Y
    bpl resolve_spell_hit_on_target_c8e7cc
    .a8
    lda #$00
    sta a:object_pending_damage,Y
    sta a:object_pending_damage_high,Y
resolve_spell_hit_on_target_c8e7cc:
    jsr select_caster_magic_stat_and_power
    lda a:object_actor_kind,Y
    bpl resolve_spell_hit_on_target_c8e7dd
    .i16
    ldy #$2ADA
    lda [$DC],Y
    ldy $83
    sta $96
resolve_spell_hit_on_target_c8e7dd:
    lda a:object_target_divisor,Y
    beq resolve_spell_hit_on_target_c8e800
    lda a:object_primary_buffs,X
    pha
    .a8
    lda #$00
    xba
    lda a:object_spell_id,Y
    asl
    tax
    jsr (spell_handler_table,X)
    sep #$20
    ldx $85
    pla
    .a8
    eor #$FF
    and a:object_primary_buffs,X
    tay
    jsl f:$C05921
resolve_spell_hit_on_target_c8e800:
    rtl
