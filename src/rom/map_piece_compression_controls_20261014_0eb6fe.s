.setcpu "65816"
.segment "CODE"
.org $B6FE
map_control_0eb6fe:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
