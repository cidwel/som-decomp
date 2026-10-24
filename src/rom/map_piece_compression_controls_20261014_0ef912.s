.setcpu "65816"
.segment "CODE"
.org $F912
map_control_0ef912:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
