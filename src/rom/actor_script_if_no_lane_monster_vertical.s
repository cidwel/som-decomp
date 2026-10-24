; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_lane_monster_vertical = $07E5
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $081D
actor_script_if_no_lane_monster_vertical:
    jsr find_first_lane_monster_vertical
    .a8
    cmp #$FF
    bne actor_script_if_no_lane_monster_vertical_c10829
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_lane_monster_vertical_c1082c
actor_script_if_no_lane_monster_vertical_c10829:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_lane_monster_vertical_c1082c:
    rts
