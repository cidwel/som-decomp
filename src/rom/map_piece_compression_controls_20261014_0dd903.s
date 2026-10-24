.setcpu "65816"
.segment "CODE"
.org $D903
map_control_0dd903:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
