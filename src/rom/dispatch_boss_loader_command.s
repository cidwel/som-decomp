; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $21D2
dispatch_boss_loader_command:
    .a16
    and #$00FF
    asl
    tax
    jmp ($21DA,X)
