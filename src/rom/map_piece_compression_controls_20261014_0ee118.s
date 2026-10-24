.setcpu "65816"
.segment "CODE"
.org $E118
map_control_0ee118:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
