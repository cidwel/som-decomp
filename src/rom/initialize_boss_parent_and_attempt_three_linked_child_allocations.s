; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-parent.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
boss_attack_row_public_jump = $C0006C
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
derive_boss_threshold_from_hardware_division_and_clamp = $5920
select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $56DB
initialize_boss_parent_and_attempt_three_linked_child_allocations:
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0020
    sta a:$00B8,X
    lda a:$0042,X
    bne initialize_boss_parent_and_attempt_three_linked_child_allocations_c256eb
    bra initialize_boss_parent_and_attempt_three_linked_child_allocations_c256f7
initialize_boss_parent_and_attempt_three_linked_child_allocations_c256eb:
    lda a:$0098,X
    .a16
    and #$FFFC
    .a16
    ora #$0002
    sta a:$0098,X
initialize_boss_parent_and_attempt_three_linked_child_allocations_c256f7:
    jsr derive_boss_threshold_from_hardware_division_and_clamp
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$0066,X
    stz a:$00A5,X
    .a16
    lda #$0004
    sta a:$00A7,X
    sta a:$001E,X
    .a16
    lda #$0001
    sta a:$0000,X
    .i16
    ldy #$3801
    .i16
    ldx #$311D
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    .a16
    lda #$0004
    sta a:$00A7,X
    .a16
    lda #$0001
    sta $02
initialize_boss_parent_and_attempt_three_linked_child_allocations_c2572b:
    .i16
    ldx #$59F7
    .i16
    ldy #$3821
    jsr allocate_boss_object_pool_slot
    lda $02
    sta a:$007A,X
    .a16
    lda #$07FF
    sta a:$0022,X
    .a16
    lda #$0001
    sta a:$000B,X
    lda $87
    sta a:$00B0,X
    lda $02
    asl
    clc
    adc $87
    tay
    txa
    sta a:$00B0,Y
    dec $02
    bpl initialize_boss_parent_and_attempt_three_linked_child_allocations_c2572b
    ldx $87
    .a16
    lda #$0018
    jsr select_boss_animation_and_reset_frame_cursor
    ldx $87
    .a16
    lda #$5775
    sta a:$008E,X
    inc a:$0094,X
    .a16
    lda #$0060
    jsl f:boss_attack_row_public_jump
    clc
    rts
