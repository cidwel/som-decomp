.setcpu "65816"
.segment "CODE"
.org $2B6F
map_control_0c2b6f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
