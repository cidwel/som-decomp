.setcpu "65816"
.segment "CODE"
.org $851B
map_control_0d851b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
