; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native70-palette-cycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D3F9
dispatch_native70_palette_cycle_phase:
    lda a:$0094,X
    asl
    tax
    jmp ($D401,X)
