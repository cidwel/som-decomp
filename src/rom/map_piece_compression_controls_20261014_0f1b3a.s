.setcpu "65816"
.segment "CODE"
.org $1B3A
map_control_0f1b3a:
    .byte $E0 ; previous-row copy escape
    .byte $DA ; row-distance/count
