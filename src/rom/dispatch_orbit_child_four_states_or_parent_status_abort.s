; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $641D
dispatch_orbit_child_four_states_or_parent_status_abort:
    ldy a:$00BA,X
    lda a:$0190,Y
    bmi dispatch_orbit_child_four_states_or_parent_status_abort_c2642d
    lda a:$0094,X
    asl
    tax
    jmp ($642F,X)
dispatch_orbit_child_four_states_or_parent_status_abort_c2642d:
    sec
    rts
