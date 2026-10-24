.setcpu "65816"
.segment "CODE"
.org $D4A2
map_control_0dd4a2:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
