.setcpu "65816"
.segment "CODE"
.org $D1B4
map_control_0dd1b4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
