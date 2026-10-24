; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_lane_monster_horizontal = $082D
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0865
actor_script_if_no_lane_monster_horizontal:
    jsr find_first_lane_monster_horizontal
    .a8
    cmp #$FF
    bne actor_script_if_no_lane_monster_horizontal_c10871
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_lane_monster_horizontal_c10874
actor_script_if_no_lane_monster_horizontal_c10871:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_lane_monster_horizontal_c10874:
    rts
