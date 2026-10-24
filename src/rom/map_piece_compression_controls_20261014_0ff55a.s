.setcpu "65816"
.segment "CODE"
.org $F55A
map_control_0ff55a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
