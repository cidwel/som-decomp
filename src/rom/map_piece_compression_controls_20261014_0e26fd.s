.setcpu "65816"
.segment "CODE"
.org $26FD
map_control_0e26fd:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
