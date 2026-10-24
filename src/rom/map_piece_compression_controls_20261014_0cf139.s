.setcpu "65816"
.segment "CODE"
.org $F139
map_control_0cf139:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
