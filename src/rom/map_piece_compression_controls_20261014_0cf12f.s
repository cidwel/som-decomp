.setcpu "65816"
.segment "CODE"
.org $F12F
map_control_0cf12f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
