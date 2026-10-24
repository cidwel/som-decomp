.setcpu "65816"
.segment "CODE"
.org $E3B9
map_control_0ee3b9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
