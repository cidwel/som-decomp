; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

reassign_controller_and_update_hud = $BDC5

.segment "CODE"
.org $BDBB
reassign_controller_with_saved_bank:
    phb
    .a8
    lda #$00
    pha
    plb
    jsr reassign_controller_and_update_hud
    plb
    rtl
