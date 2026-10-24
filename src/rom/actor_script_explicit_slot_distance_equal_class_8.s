; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_2_bytes = $028D
skip_actor_script_after_2_bytes = $021B

.segment "CODE"
.org $191A
actor_script_explicit_slot_distance_equal_class_8:
    ldx a:$0144,Y
    lda f:$D04F16,X
    asl
    xba
    .a8
    lda #$00
    rep #$20
    clc
    .a16
    adc #$E000
    tax
    sep #$20
    lda a:$0000,X
    .a8
    cmp #$01
    bne actor_script_explicit_slot_distance_equal_class_8_c11941
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    bne actor_script_explicit_slot_distance_equal_class_8_c11941
    jsr skip_actor_script_after_2_bytes
    bra actor_script_explicit_slot_distance_equal_class_8_c11944
actor_script_explicit_slot_distance_equal_class_8_c11941:
    jsr jump_actor_script_after_2_bytes
actor_script_explicit_slot_distance_equal_class_8_c11944:
    rts
