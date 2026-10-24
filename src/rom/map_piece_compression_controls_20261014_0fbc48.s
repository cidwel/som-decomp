.setcpu "65816"
.segment "CODE"
.org $BC48
map_control_0fbc48:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
