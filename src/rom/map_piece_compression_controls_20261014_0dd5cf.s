.setcpu "65816"
.segment "CODE"
.org $D5CF
map_control_0dd5cf:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
