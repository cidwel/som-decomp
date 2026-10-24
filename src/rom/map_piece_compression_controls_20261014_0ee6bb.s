.setcpu "65816"
.segment "CODE"
.org $E6BB
map_control_0ee6bb:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
