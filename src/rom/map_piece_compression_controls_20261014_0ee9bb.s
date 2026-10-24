.setcpu "65816"
.segment "CODE"
.org $E9BB
map_control_0ee9bb:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
