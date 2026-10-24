.setcpu "65816"
.segment "CODE"
.org $2CB2
map_control_0e2cb2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
