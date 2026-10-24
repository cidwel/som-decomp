.setcpu "65816"
.segment "CODE"
.org $E143
map_control_0ee143:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
