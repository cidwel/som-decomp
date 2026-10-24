; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $385D
unused_cast_completion_return:
    rtl
