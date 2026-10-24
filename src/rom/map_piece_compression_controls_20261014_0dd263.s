.setcpu "65816"
.segment "CODE"
.org $D263
map_control_0dd263:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
