.setcpu "65816"
.segment "CODE"
.org $D837
map_control_0dd837:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
