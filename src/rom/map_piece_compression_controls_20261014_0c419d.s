.setcpu "65816"
.segment "CODE"
.org $419D
map_control_0c419d:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
