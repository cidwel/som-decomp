.setcpu "65816"
.segment "CODE"
.org $E17F
map_control_0ee17f:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E1 ; previous-row copy count
