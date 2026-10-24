; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-unused-native-leaves.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $60AD
lookup_native_script_root_word_from_actor_ab_selector:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE292,X
    rts
