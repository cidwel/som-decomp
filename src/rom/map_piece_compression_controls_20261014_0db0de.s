.setcpu "65816"
.segment "CODE"
.org $B0DE
map_control_0db0de:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
