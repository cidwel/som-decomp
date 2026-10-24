.setcpu "65816"
.segment "CODE"
.org $58E3
map_control_0e58e3:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
