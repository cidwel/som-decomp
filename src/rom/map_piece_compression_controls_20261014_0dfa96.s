.setcpu "65816"
.segment "CODE"
.org $FA96
map_control_0dfa96:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
