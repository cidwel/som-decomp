.setcpu "65816"
.segment "CODE"
.org $B4D9
map_control_0db4d9:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
