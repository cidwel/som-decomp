.setcpu "65816"
.segment "CODE"
.org $D10C
map_control_0ed10c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
