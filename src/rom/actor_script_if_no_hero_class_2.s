; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_hero_class_2 = $08BC
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $08F3
actor_script_if_no_hero_class_2:
    jsr find_first_eligible_hero_class_2
    .a8
    cmp #$FF
    bne actor_script_if_no_hero_class_2_c108ff
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_hero_class_2_c10902
actor_script_if_no_hero_class_2_c108ff:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_hero_class_2_c10902:
    rts
