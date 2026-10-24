; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

select_or_release_controller_actor = $BDD0
wait_for_nmi_and_update_controller_hud = $BF38

.segment "CODE"
.org $BDC5
reassign_controller_and_update_hud:
    lda $D9,X
    bpl reassign_controller_and_update_hud_c0bdca
    rts
reassign_controller_and_update_hud_c0bdca:
    jsr select_or_release_controller_actor
    brl wait_for_nmi_and_update_controller_hud
