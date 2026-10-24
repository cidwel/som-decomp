.setcpu "65816"
.segment "CODE"
.org $598F
map_control_0d598f:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
