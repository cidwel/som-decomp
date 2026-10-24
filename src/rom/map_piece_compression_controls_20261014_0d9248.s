.setcpu "65816"
.segment "CODE"
.org $9248
map_control_0d9248:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
