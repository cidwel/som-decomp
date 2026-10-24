.setcpu "65816"
.segment "CODE"
.org $7DB3
map_control_0f7db3:
    .byte $E6 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
