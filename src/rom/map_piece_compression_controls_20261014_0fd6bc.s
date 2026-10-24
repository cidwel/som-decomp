.setcpu "65816"
.segment "CODE"
.org $D6BC
map_control_0fd6bc:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
