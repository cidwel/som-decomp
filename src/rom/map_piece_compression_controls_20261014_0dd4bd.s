.setcpu "65816"
.segment "CODE"
.org $D4BD
map_control_0dd4bd:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
