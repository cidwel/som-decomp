; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E90
terminate_descriptor_eleven_height_child:
    sec
    rts
