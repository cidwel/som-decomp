.setcpu "65816"
.segment "CODE"
.org $537F
map_control_0e537f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
