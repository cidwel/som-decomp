.setcpu "65816"
.segment "CODE"
.org $FCAC
map_control_0dfcac:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
