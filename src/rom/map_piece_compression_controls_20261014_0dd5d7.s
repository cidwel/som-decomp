.setcpu "65816"
.segment "CODE"
.org $D5D7
map_control_0dd5d7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
