.setcpu "65816"
.segment "CODE"
.org $CFC6
map_control_0fcfc6:
    .byte $E6 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
