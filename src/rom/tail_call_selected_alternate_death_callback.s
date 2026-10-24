; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0BC9
tail_call_selected_alternate_death_callback:
    sta $0C
    jmp ($020C)
