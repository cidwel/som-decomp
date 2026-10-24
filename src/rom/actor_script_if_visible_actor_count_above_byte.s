; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

count_visible_actor_slots_3_to_5 = $0D33
jump_actor_script_after_2_bytes = $028D
skip_actor_script_after_2_bytes = $021B

.segment "CODE"
.org $0D63
actor_script_if_visible_actor_count_above_byte:
    jsr count_visible_actor_slots_3_to_5
    ldx a:$0144,Y
    cmp f:$D04F16,X
    beq actor_script_if_visible_actor_count_above_byte_c10d76
    bcc actor_script_if_visible_actor_count_above_byte_c10d76
    jsr jump_actor_script_after_2_bytes
    bra actor_script_if_visible_actor_count_above_byte_c10d79
actor_script_if_visible_actor_count_above_byte_c10d76:
    jsr skip_actor_script_after_2_bytes
actor_script_if_visible_actor_count_above_byte_c10d79:
    rts
