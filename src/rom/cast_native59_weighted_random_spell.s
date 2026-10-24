; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
draw_boss_frame_random_number = $300B
prepare_boss_spell_targets = $396D
routine_01800f = $1800F

.segment "CODE"
.org $86B3
cast_native59_weighted_random_spell:
    .a16
    lda #$0006
    jsr draw_boss_frame_random_number
    tax
    lda f:$C286DD,X
    .a16
    and #$00FF
    .a16
    ora #$0000
    ldx $87
    jsr prepare_boss_spell_targets
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne cast_native59_weighted_random_spell_c286dc
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
cast_native59_weighted_random_spell_c286dc:
    rts
