.setcpu "65816"
.segment "CODE"
.org $D4C6
map_control_0dd4c6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
