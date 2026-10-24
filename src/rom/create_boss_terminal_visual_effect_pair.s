; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-phases.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3A9A
create_boss_terminal_visual_effect_pair:
    lda a:$0098,X
    .a16
    bit #$0008
    bne create_boss_terminal_visual_effect_pair_c23aaa
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    bra create_boss_terminal_visual_effect_pair_c23ab0
create_boss_terminal_visual_effect_pair_c23aaa:
    .a16
    lda #$0133
    jsr select_boss_animation_and_reset_frame_cursor
create_boss_terminal_visual_effect_pair_c23ab0:
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    clc
    adc a:$0062,X
    sta $97
    .i16
    ldx #$3ADB
    .i16
    ldy #$2A21
    jsr allocate_boss_object_pool_slot
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    .i16
    ldx #$3C78
    .i16
    ldy #$2100
    jsr allocate_boss_object_pool_slot
    rts
