; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_monster_within_class_4 = $0EDF
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0F18
actor_script_if_no_monster_within_class_4:
    jsr find_first_eligible_monster_within_class_4
    .a8
    cmp #$FF
    bne actor_script_if_no_monster_within_class_4_c10f24
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_monster_within_class_4_c10f27
actor_script_if_no_monster_within_class_4_c10f24:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_monster_within_class_4_c10f27:
    rts
