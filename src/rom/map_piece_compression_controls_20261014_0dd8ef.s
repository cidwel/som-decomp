.setcpu "65816"
.segment "CODE"
.org $D8EF
map_control_0dd8ef:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
