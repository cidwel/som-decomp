.setcpu "65816"
.segment "CODE"
.org $918F
map_control_0c918f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
