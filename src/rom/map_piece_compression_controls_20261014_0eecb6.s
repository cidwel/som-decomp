.setcpu "65816"
.segment "CODE"
.org $ECB6
map_control_0eecb6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E7 ; previous-row copy count
