.setcpu "65816"
.segment "CODE"
.org $5CED
map_control_0d5ced:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
