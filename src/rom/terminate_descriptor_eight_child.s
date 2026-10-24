; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7001
terminate_descriptor_eight_child:
    sec
    rts
