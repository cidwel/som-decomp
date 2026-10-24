.setcpu "65816"
.segment "CODE"
.org $E31B
map_control_0ee31b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
