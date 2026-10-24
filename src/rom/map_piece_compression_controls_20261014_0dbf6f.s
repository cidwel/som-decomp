.setcpu "65816"
.segment "CODE"
.org $BF6F
map_control_0dbf6f:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
