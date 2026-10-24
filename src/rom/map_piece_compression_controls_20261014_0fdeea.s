.setcpu "65816"
.segment "CODE"
.org $DEEA
map_control_0fdeea:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
