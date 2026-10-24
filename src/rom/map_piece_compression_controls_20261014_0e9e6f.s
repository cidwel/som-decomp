.setcpu "65816"
.segment "CODE"
.org $9E6F
map_control_0e9e6f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
