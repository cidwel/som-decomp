.setcpu "65816"
.segment "CODE"
.org $D8E7
map_control_0dd8e7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
