.setcpu "65816"
.segment "CODE"
.org $D7C6
map_control_0dd7c6:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
