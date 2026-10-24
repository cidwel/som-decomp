.setcpu "65816"
.segment "CODE"
.org $E789
map_control_0ee789:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
