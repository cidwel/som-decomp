.setcpu "65816"
.segment "CODE"
.org $E079
map_control_0ee079:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
