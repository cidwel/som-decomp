.setcpu "65816"
.segment "CODE"
.org $E2D7
map_control_0ee2d7:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
