.setcpu "65816"
.segment "CODE"
.org $D4A7
map_control_0dd4a7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
