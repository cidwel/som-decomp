.setcpu "65816"
.segment "CODE"
.org $DAA3
map_control_0fdaa3:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
