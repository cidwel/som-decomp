.setcpu "65816"
.segment "CODE"
.org $D8DD
map_control_0dd8dd:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
