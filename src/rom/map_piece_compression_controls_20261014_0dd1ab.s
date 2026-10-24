.setcpu "65816"
.segment "CODE"
.org $D1AB
map_control_0dd1ab:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
