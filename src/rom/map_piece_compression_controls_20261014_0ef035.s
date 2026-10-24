.setcpu "65816"
.segment "CODE"
.org $F035
map_control_0ef035:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
