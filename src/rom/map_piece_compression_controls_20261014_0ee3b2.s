.setcpu "65816"
.segment "CODE"
.org $E3B2
map_control_0ee3b2:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
