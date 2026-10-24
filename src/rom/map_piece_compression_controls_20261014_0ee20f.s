.setcpu "65816"
.segment "CODE"
.org $E20F
map_control_0ee20f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
