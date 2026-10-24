; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B

.segment "CODE"
.org $93EE
select_native7f_status_gated_spell_or_skip:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$01B1,Y
    .a16
    bit #$0040
    bne select_native7f_status_gated_spell_or_skip_c2940e
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    beq select_native7f_status_gated_spell_or_skip_c29409
    rts
select_native7f_status_gated_spell_or_skip_c29409:
    .a16
    lda #$0006
    bra select_native7f_status_gated_spell_or_skip_c29411
select_native7f_status_gated_spell_or_skip_c2940e:
    .a16
    lda #$0005
select_native7f_status_gated_spell_or_skip_c29411:
    asl
    tax
    jmp ($9416,X)
