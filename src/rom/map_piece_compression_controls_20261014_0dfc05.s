.setcpu "65816"
.segment "CODE"
.org $FC05
map_control_0dfc05:
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
