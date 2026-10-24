.setcpu "65816"
.segment "CODE"
.org $DA03
map_control_0fda03:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
