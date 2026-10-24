.setcpu "65816"
.segment "CODE"
.org $DA3A
map_control_0eda3a:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
