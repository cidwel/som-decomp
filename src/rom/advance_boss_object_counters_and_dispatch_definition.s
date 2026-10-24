; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0F83
advance_boss_object_counters_and_dispatch_definition:
    inc a:$0096,X
    inc a:$00AD,X
    lda a:$008E,X
    sta $76
    jmp ($0276)
