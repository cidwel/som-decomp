.setcpu "65816"
.segment "CODE"
.org $B188
map_control_0fb188:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
