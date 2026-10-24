.setcpu "65816"
.segment "CODE"
.org $B1AC
map_control_0db1ac:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
