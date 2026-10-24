; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_monster_class_1 = $0D7A
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0DB1
actor_script_if_no_monster_class_1:
    jsr find_first_eligible_monster_class_1
    .a8
    cmp #$FF
    bne actor_script_if_no_monster_class_1_c10dbd
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_monster_class_1_c10dc0
actor_script_if_no_monster_class_1_c10dbd:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_monster_class_1_c10dc0:
    rts
