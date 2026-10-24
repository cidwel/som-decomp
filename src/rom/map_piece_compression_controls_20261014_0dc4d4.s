.setcpu "65816"
.segment "CODE"
.org $C4D4
map_control_0dc4d4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
