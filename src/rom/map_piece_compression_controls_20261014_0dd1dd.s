.setcpu "65816"
.segment "CODE"
.org $D1DD
map_control_0dd1dd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
