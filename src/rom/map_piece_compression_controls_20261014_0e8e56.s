.setcpu "65816"
.segment "CODE"
.org $8E56
map_control_0e8e56:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
