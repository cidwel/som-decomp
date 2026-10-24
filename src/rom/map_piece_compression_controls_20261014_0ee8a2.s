.setcpu "65816"
.segment "CODE"
.org $E8A2
map_control_0ee8a2:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
