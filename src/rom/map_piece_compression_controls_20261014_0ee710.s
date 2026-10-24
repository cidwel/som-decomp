.setcpu "65816"
.segment "CODE"
.org $E710
map_control_0ee710:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
