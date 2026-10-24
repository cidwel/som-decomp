.setcpu "65816"
.segment "CODE"
.org $8927
map_control_0e8927:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
