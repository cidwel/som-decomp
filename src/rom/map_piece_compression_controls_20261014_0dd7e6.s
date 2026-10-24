.setcpu "65816"
.segment "CODE"
.org $D7E6
map_control_0dd7e6:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
