.setcpu "65816"
.segment "CODE"
.org $E200
map_control_0ee200:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
