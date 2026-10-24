; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67E5
dispatch_descriptor_thirteen_variant_destination_selection:
    lda a:$0042,X
    asl
    tax
    jmp ($67ED,X)
