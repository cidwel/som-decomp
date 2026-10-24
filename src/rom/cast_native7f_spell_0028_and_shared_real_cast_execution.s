; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
prepare_boss_spell_targets = $396D
routine_01800f = $1800F

.segment "CODE"
.org $9442
cast_native7f_spell_0028_and_shared_real_cast_execution:
    .a16
    lda #$0028
    ldx $87
    jsr prepare_boss_spell_targets
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne cast_native7f_spell_0028_and_shared_real_cast_execution_c29462
    ldx $87
    stz a:$0060,X
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
cast_native7f_spell_0028_and_shared_real_cast_execution_c29462:
    rts
