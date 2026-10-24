; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_actor_appearance_context = $4518

.segment "CODE"
.org $45D6
prepare_boss_attack_row_and_appearance_context:
    phd
    phb
    php
    sep #$20
    pha
    jsr prepare_actor_appearance_context
    pla
    sta a:$E1E3,X
    sta a:$E1E8,X
