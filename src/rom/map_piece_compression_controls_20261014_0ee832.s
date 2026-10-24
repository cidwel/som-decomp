.setcpu "65816"
.segment "CODE"
.org $E832
map_control_0ee832:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
