.setcpu "65816"
.segment "CODE"
.org $ED46
map_control_0ded46:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
