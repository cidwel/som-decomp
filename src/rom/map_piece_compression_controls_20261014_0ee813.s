.setcpu "65816"
.segment "CODE"
.org $E813
map_control_0ee813:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
