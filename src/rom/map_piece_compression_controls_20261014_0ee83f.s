.setcpu "65816"
.segment "CODE"
.org $E83F
map_control_0ee83f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
