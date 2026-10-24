.setcpu "65816"
.segment "CODE"
.org $CA9F
map_control_0dca9f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
