; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $499A
test_both_party_charge_globals:
    lda a:$CC79
    bne test_both_party_charge_globals_c049a1
    clc
    rts
test_both_party_charge_globals_c049a1:
    lda a:$CC78
    bne test_both_party_charge_globals_c049a8
    clc
    rts
test_both_party_charge_globals_c049a8:
    sec
    rts
