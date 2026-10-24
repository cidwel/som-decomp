; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $68FB
dispatch_descriptor_thirteen_variant_destination_teleport:
    lda a:$0042,X
    asl
    tax
    jmp ($6903,X)
