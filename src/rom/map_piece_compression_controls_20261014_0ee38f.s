.setcpu "65816"
.segment "CODE"
.org $E38F
map_control_0ee38f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
