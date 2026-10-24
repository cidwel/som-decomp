.setcpu "65816"
.segment "CODE"
.org $E24F
map_control_0ee24f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
