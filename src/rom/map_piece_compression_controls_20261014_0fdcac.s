.setcpu "65816"
.segment "CODE"
.org $DCAC
map_control_0fdcac:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
