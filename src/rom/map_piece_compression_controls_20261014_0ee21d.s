.setcpu "65816"
.segment "CODE"
.org $E21D
map_control_0ee21d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
