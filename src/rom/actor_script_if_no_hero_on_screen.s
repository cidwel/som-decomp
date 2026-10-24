; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_hero_on_screen = $0AA3
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213



.segment "CODE"
.org $0ADC
actor_script_if_no_hero_on_screen:
    jsr find_first_eligible_hero_on_screen
    .a8
    cmp #$FF
    bne actor_script_if_no_hero_on_screen_c10ae8
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_hero_on_screen_c10aeb
actor_script_if_no_hero_on_screen_c10ae8:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_hero_on_screen_c10aeb:
    rts
