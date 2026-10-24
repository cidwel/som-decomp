.setcpu "65816"
.segment "CODE"
.org $35BC
map_control_0e35bc:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
