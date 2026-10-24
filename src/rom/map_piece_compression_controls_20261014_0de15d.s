.setcpu "65816"
.segment "CODE"
.org $E15D
map_control_0de15d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
