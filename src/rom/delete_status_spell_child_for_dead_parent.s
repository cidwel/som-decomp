; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $99CD
delete_status_spell_child_for_dead_parent:
    sec
    rts
