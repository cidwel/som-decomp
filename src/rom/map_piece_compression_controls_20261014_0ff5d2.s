.setcpu "65816"
.segment "CODE"
.org $F5D2
map_control_0ff5d2:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
