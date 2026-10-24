; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_program_long = $C10020

object_status_word = $E190
object_pending_hp_damage = $E1F1
object_pending_mp_damage_and_heal = $E1F5
object_actor_kind = $E1FB

.segment "CODE"
.org $E441
clear_recovered_actor_status_and_resume_hero_program:
    .a16
    lda #$0000
    sta $98
    sta a:object_status_word,X
    sta $B0
    sta a:object_pending_hp_damage,X
    sta a:object_pending_mp_damage_and_heal,X
    sep #$20
    lda a:object_actor_kind,X
    bmi clear_recovered_actor_status_and_resume_hero_program_c8e459
    rts
clear_recovered_actor_status_and_resume_hero_program_c8e459:
    lda $81
    inc
    .a8
    cmp #$03
    bne clear_recovered_actor_status_and_resume_hero_program_c8e461
    inc
clear_recovered_actor_status_and_resume_hero_program_c8e461:
    sta $AC
    .a8
    lda #$D9
    .a8
    and #$07
    cmp $AC
    beq clear_recovered_actor_status_and_resume_hero_program_c8e486
    .a8
    lda #$DA
    .a8
    and #$07
    cmp $AC
    beq clear_recovered_actor_status_and_resume_hero_program_c8e486
    .a8
    lda #$DB
    .a8
    and #$07
    cmp $AC
    beq clear_recovered_actor_status_and_resume_hero_program_c8e486
    lda $81
    clc
    .a8
    adc #$80
    jsl f:set_actor_program_long
    ldx $85
clear_recovered_actor_status_and_resume_hero_program_c8e486:
    rts
