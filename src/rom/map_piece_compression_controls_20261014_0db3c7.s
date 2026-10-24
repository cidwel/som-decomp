.setcpu "65816"
.segment "CODE"
.org $B3C7
map_control_0db3c7:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
