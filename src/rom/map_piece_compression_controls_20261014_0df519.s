.setcpu "65816"
.segment "CODE"
.org $F519
map_control_0df519:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
