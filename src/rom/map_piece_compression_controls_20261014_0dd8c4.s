.setcpu "65816"
.segment "CODE"
.org $D8C4
map_control_0dd8c4:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
