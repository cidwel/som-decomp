.setcpu "65816"
.segment "CODE"
.org $648F
map_control_0e648f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
