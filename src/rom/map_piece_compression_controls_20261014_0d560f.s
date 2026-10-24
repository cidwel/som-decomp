.setcpu "65816"
.segment "CODE"
.org $560F
map_control_0d560f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
