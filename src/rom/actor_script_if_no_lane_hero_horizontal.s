; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_lane_hero_horizontal = $070D
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0745
actor_script_if_no_lane_hero_horizontal:
    jsr find_first_lane_hero_horizontal
    .a8
    cmp #$FF
    bne actor_script_if_no_lane_hero_horizontal_c10751
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_lane_hero_horizontal_c10754
actor_script_if_no_lane_hero_horizontal_c10751:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_lane_hero_horizontal_c10754:
    rts
