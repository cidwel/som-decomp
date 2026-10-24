.setcpu "65816"
.segment "CODE"
.org $60E3
map_control_0f60e3:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
