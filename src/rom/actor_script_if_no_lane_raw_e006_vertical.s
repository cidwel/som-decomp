; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_lane_raw_e006_vertical = $0755
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $078D
actor_script_if_no_lane_raw_e006_vertical:
    jsr find_first_lane_raw_e006_vertical
    .a8
    cmp #$FF
    bne actor_script_if_no_lane_raw_e006_vertical_c10799
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_lane_raw_e006_vertical_c1079c
actor_script_if_no_lane_raw_e006_vertical_c10799:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_lane_raw_e006_vertical_c1079c:
    rts
