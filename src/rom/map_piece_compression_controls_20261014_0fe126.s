.setcpu "65816"
.segment "CODE"
.org $E126
map_control_0fe126:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
