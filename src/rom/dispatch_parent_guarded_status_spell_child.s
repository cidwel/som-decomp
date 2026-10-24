; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

delete_status_spell_child_for_dead_parent = $99CD

.segment "CODE"
.org $997D
dispatch_parent_guarded_status_spell_child:
    ldy a:$00B0,X
    lda a:$0190,Y
    bmi delete_status_spell_child_for_dead_parent
    lda a:$0094,X
    asl
    tax
    jmp ($99E1,X)
