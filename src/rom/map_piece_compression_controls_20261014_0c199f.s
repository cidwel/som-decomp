.setcpu "65816"
.segment "CODE"
.org $199F
map_control_0c199f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
