.setcpu "65816"
.segment "CODE"
.org $F4D8
map_control_0cf4d8:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
