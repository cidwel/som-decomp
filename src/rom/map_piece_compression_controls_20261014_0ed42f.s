.setcpu "65816"
.segment "CODE"
.org $D42F
map_control_0ed42f:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
