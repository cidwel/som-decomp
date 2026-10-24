.setcpu "65816"
.segment "CODE"
.org $5C56
map_control_0f5c56:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E1 ; previous-row copy count
