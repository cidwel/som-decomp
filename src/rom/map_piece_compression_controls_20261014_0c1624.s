.setcpu "65816"
.segment "CODE"
.org $1624
map_control_0c1624:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
