; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_hero_within_class_8 = $0A5A
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $0A93
actor_script_if_no_hero_within_class_8:
    jsr find_first_eligible_hero_within_class_8
    .a8
    cmp #$FF
    bne actor_script_if_no_hero_within_class_8_c10a9f
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_hero_within_class_8_c10aa2
actor_script_if_no_hero_within_class_8_c10a9f:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_hero_within_class_8_c10aa2:
    rts
