; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8997
terminate_native59_mode7_child:
    sec
    rts
