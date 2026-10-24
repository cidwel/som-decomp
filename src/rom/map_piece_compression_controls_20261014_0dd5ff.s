.setcpu "65816"
.segment "CODE"
.org $D5FF
map_control_0dd5ff:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
