; Recovered Secret of Mana USA routine; behaviour documented in docs/map-motion-shared.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D47A
clear_actor_motion_contact_pose_flags:
    sep #$20
    .a8
    lda #$00
    sta a:$E029,X
    rts
