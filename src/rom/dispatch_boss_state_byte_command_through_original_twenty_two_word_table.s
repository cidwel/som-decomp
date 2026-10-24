; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-state-engine-vm.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $37C7
dispatch_boss_state_byte_command_through_original_twenty_two_word_table:
    asl
    tax
    jmp ($37CC,X)
