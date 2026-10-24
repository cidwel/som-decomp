.setcpu "65816"
.segment "CODE"
.org $F5F9
map_control_0ff5f9:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
