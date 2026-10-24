; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_hero_class_8 = $094A
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $0981
actor_script_if_no_hero_class_8:
    jsr find_first_eligible_hero_class_8
    .a8
    cmp #$FF
    bne actor_script_if_no_hero_class_8_c1098d
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_hero_class_8_c10990
actor_script_if_no_hero_class_8_c1098d:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_hero_class_8_c10990:
    rts
