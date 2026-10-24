; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_lane_raw_e006_horizontal = $079D
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $07D5
actor_script_if_no_lane_raw_e006_horizontal:
    jsr find_first_lane_raw_e006_horizontal
    .a8
    cmp #$FF
    bne actor_script_if_no_lane_raw_e006_horizontal_c107e1
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_lane_raw_e006_horizontal_c107e4
actor_script_if_no_lane_raw_e006_horizontal_c107e1:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_lane_raw_e006_horizontal_c107e4:
    rts
