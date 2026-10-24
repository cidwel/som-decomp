.setcpu "65816"
.segment "CODE"
.org $DFFE
map_control_0ddffe:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
