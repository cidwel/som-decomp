.setcpu "65816"
.segment "CODE"
.org $E0BC
map_control_0ee0bc:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
