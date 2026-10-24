.setcpu "65816"
.segment "CODE"
.org $B553
map_control_0eb553:
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
