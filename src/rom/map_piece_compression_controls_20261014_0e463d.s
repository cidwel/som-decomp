.setcpu "65816"
.segment "CODE"
.org $463D
map_control_0e463d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
