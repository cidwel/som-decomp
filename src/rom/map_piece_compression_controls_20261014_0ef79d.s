.setcpu "65816"
.segment "CODE"
.org $F79D
map_control_0ef79d:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
