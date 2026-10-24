.setcpu "65816"
.segment "CODE"
.org $FEAD
map_control_0dfead:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
