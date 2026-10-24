; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

advance_hero_spell_level_progress = $D04DCD
prepare_cast_actor_context_long = $C0395E
resolve_spell_hit_on_target = $E7A7

object_hit_flash_timer = $E1F8
object_spell_id = $E170
object_cast_spell_level = $E171
object_cast_hit_list = $E172
object_second_cast_hit = $E173
object_third_cast_hit = $E174
object_mp = $E186
object_status_high = $E191
object_actor_kind = $E1FB
object_id = $E180
object_last_spell_caster = $E1EC
object_last_damage_source = $E1F0
object_control_id = $E02C

.segment "CODE"
.org $E6D4
apply_spell_hit_to_actor:
    jsl f:prepare_cast_actor_context_long
    .a8
    lda #$10
    sta a:object_hit_flash_timer,X
    sta a:object_hit_flash_timer,Y
    lda a:object_spell_id,Y
    sta f:$004202
    .a8
    lda #$40
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    sta $DC
    sep #$20
    .a8
    lda #$D0
    sta $DE
    lda a:object_cast_hit_list,Y
    bpl apply_spell_hit_to_actor_c8e727
    lda a:object_second_cast_hit,Y
    bpl apply_spell_hit_to_actor_c8e727
    lda a:object_third_cast_hit,Y
    bpl apply_spell_hit_to_actor_c8e727
    jsl f:advance_hero_spell_level_progress
    .i16
    ldy #$2ADF
    lda [$DC],Y
    ldy $83
    sta $A4
    lda a:object_mp,Y
    sec
    sbc $A4
    bpl apply_spell_hit_to_actor_c8e724
    .a8
    lda #$00
apply_spell_hit_to_actor_c8e724:
    sta a:object_mp,Y
apply_spell_hit_to_actor_c8e727:
    stz $91
    stz $9A
    stz $9B
    ldx $83
    lda a:object_cast_spell_level,X
    sta $9D
    .i16
    ldy #$0003
    lda $81
apply_spell_hit_to_actor_c8e739:
    cmp a:object_cast_hit_list,X
    beq apply_spell_hit_to_actor_c8e744
    inx
    dey
    bne apply_spell_hit_to_actor_c8e739
    bra apply_spell_hit_to_actor_c8e745
apply_spell_hit_to_actor_c8e744:
    rtl
apply_spell_hit_to_actor_c8e745:
    ldx $83
    .i16
    ldy #$0003
apply_spell_hit_to_actor_c8e74a:
    lda a:object_cast_hit_list,X
    bmi apply_spell_hit_to_actor_c8e755
    inx
    dey
    bne apply_spell_hit_to_actor_c8e74a
    bra apply_spell_hit_to_actor_c8e744
apply_spell_hit_to_actor_c8e755:
    lda $81
    sta a:object_cast_hit_list,X
    ldx $85
    ldy $83
    lda a:object_status_high,Y
    bmi apply_spell_hit_to_actor_c8e77d
    lda a:object_actor_kind,X
    .a8
    bit #$10
    bne apply_spell_hit_to_actor_c8e77e
    lda a:object_spell_id,Y
    .a8
    cmp #$21
    beq apply_spell_hit_to_actor_c8e77e
    lda a:object_id,X
    .a8
    cmp #$EA
    beq apply_spell_hit_to_actor_c8e77e
    lda a:object_status_high,X
    bpl apply_spell_hit_to_actor_c8e77e
apply_spell_hit_to_actor_c8e77d:
    rtl
apply_spell_hit_to_actor_c8e77e:
    lda $82
    sta a:object_last_spell_caster,X
    .a8
    lda #$FF
    sta a:object_last_damage_source,X
    .a8
    lda #$00
    xba
    lda a:object_actor_kind,X
    .a8
    bit #$10
    beq resolve_spell_hit_on_target
    lda a:object_control_id,Y
    beq apply_spell_hit_to_actor_c8e7a6
    dec
    .a8
    cmp #$03
    bne apply_spell_hit_to_actor_c8e79d
    dec
apply_spell_hit_to_actor_c8e79d:
    tax
    lda a:$00D9,X
    .a8
    ora #$80
    sta a:$00D9,X
apply_spell_hit_to_actor_c8e7a6:
    rtl
