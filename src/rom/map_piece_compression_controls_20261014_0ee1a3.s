.setcpu "65816"
.segment "CODE"
.org $E1A3
map_control_0ee1a3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
