; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_2_bytes = $028D
skip_actor_script_after_2_bytes = $021B

.segment "CODE"
.org $19C6
actor_script_explicit_slot_distance_unequal_class_8:
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
    bne actor_script_explicit_slot_distance_unequal_class_8_c119ed
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    beq actor_script_explicit_slot_distance_unequal_class_8_c119ed
    jsr skip_actor_script_after_2_bytes
    bra actor_script_explicit_slot_distance_unequal_class_8_c119f0
actor_script_explicit_slot_distance_unequal_class_8_c119ed:
    jsr jump_actor_script_after_2_bytes
actor_script_explicit_slot_distance_unequal_class_8_c119f0:
    rts
