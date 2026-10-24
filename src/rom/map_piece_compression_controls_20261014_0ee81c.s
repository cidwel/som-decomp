.setcpu "65816"
.segment "CODE"
.org $E81C
map_control_0ee81c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
