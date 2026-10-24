.setcpu "65816"
.segment "CODE"
.org $E9AB
map_control_0ee9ab:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
