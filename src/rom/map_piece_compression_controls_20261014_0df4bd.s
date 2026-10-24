.setcpu "65816"
.segment "CODE"
.org $F4BD
map_control_0df4bd:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
