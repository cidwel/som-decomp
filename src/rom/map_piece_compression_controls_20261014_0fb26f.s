.setcpu "65816"
.segment "CODE"
.org $B26F
map_control_0fb26f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
