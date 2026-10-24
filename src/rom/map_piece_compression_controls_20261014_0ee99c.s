.setcpu "65816"
.segment "CODE"
.org $E99C
map_control_0ee99c:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
