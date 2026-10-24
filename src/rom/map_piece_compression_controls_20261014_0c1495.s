.setcpu "65816"
.segment "CODE"
.org $1495
map_control_0c1495:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
