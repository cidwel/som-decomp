.setcpu "65816"
.segment "CODE"
.org $6661
map_control_0d6661:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
