.setcpu "65816"
.segment "CODE"
.org $E118
map_control_0fe118:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
