; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_monster_within_class_8 = $0F28
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0F61
actor_script_if_no_monster_within_class_8:
    jsr find_first_eligible_monster_within_class_8
    .a8
    cmp #$FF
    bne actor_script_if_no_monster_within_class_8_c10f6d
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_monster_within_class_8_c10f70
actor_script_if_no_monster_within_class_8_c10f6d:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_monster_within_class_8_c10f70:
    rts
