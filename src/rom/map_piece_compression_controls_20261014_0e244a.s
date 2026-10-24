.setcpu "65816"
.segment "CODE"
.org $244A
map_control_0e244a:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
