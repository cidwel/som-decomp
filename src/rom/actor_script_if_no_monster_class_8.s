; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_monster_class_8 = $0E4F
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0E86
actor_script_if_no_monster_class_8:
    jsr find_first_eligible_monster_class_8
    .a8
    cmp #$FF
    bne actor_script_if_no_monster_class_8_c10e92
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_monster_class_8_c10e95
actor_script_if_no_monster_class_8_c10e92:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_monster_class_8_c10e95:
    rts
