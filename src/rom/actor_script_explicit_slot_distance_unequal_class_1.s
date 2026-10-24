; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_2_bytes = $028D
skip_actor_script_after_2_bytes = $021B

.segment "CODE"
.org $1945
actor_script_explicit_slot_distance_unequal_class_1:
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
    bne actor_script_explicit_slot_distance_unequal_class_1_c1196c
    jsr classify_actor_squared_distance
    .a8
    cmp #$01
    beq actor_script_explicit_slot_distance_unequal_class_1_c1196c
    jsr skip_actor_script_after_2_bytes
    bra actor_script_explicit_slot_distance_unequal_class_1_c1196f
actor_script_explicit_slot_distance_unequal_class_1_c1196c:
    jsr jump_actor_script_after_2_bytes
actor_script_explicit_slot_distance_unequal_class_1_c1196f:
    rts
