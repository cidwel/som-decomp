.setcpu "65816"
.segment "CODE"
.org $E84B
map_control_0ee84b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
