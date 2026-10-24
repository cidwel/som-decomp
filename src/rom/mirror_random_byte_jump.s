; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

random_byte_with_preserved_direct_page = $3872



.segment "CODE"
.org $3800
mirror_random_byte_jump:
    jmp random_byte_with_preserved_direct_page
