.setcpu "65816"
.segment "CODE"
.org $D557
map_control_0dd557:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
