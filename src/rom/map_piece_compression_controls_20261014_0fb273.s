.setcpu "65816"
.segment "CODE"
.org $B273
map_control_0fb273:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
