.setcpu "65816"
.segment "CODE"
.org $8DF4
map_control_0d8df4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
