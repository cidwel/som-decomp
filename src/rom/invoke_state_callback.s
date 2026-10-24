; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $36B3
invoke_state_callback:
    sta $30
    jmp ($0230)
