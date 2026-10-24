.setcpu "65816"
.segment "CODE"
.org $E3AC
map_control_0ee3ac:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
